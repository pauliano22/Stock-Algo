import torch
import torch.nn as nn
import torch.optim as optim
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import MinMaxScaler
import pandas as pd
import numpy as np
import yfinance as yf

# Step 1: Download historical stock data
print("Downloading stock data...")
stock_data = yf.download("AAPL", start="2020-01-01", end="2023-01-01")
stock_data.to_csv("apple_stock_data.csv")  # Save for future reference

# Step 2: Preprocess the data
# Check for missing data
if stock_data.isnull().sum().any():
    print("Missing data detected. Filling missing values...")
    stock_data.fillna(method='ffill', inplace=True)  # Forward fill to handle missing data

print("Processing data...")
data = stock_data[['Open', 'High', 'Low', 'Close', 'Volume']].values

# Normalize the features
scaler = MinMaxScaler()
data_normalized = scaler.fit_transform(data)

# Prepare features and target
X = data_normalized[:-1, :]  # All rows except the last one
y = data_normalized[1:, 3:4]  # The 'Close' price of the next day as the target

# Convert to PyTorch tensors
X = torch.tensor(X, dtype=torch.float32)
y = torch.tensor(y, dtype=torch.float32)

# Split data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Step 3: Define the StockPredictor model
class StockPredictor(nn.Module):
    def __init__(self, input_size):
        super(StockPredictor, self).__init__()
        self.fc1 = nn.Linear(input_size, 64)
        self.fc2 = nn.Linear(64, 32)
        self.fc3 = nn.Linear(32, 1)

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        return self.fc3(x)

# Initialize the model
input_size = X.shape[1]  # Number of features
model = StockPredictor(input_size)

# Step 4: Define loss function and optimizer
criterion = nn.MSELoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)

# Step 5: Train the model
print("Training the model...")
epochs = 100  # Number of epochs
for epoch in range(epochs):
    model.train()  # Set model to training mode
    optimizer.zero_grad()  # Clear gradients
    
    # Forward pass
    outputs = model(X_train)
    loss = criterion(outputs, y_train)
    
    # Backward pass and optimization
    loss.backward()
    optimizer.step()
    
    # Print loss for every epoch
    if (epoch + 1) % 10 == 0 or epoch == 0:  # Every 10 epochs
        print(f"Epoch {epoch+1}/{epochs}, Loss: {loss.item():.4f}")

# Step 6: Evaluate the model
print("Evaluating the model...")
model.eval()  # Set model to evaluation mode
with torch.no_grad():
    predictions = model(X_test)
    test_loss = criterion(predictions, y_test)
    print(f"Test Loss: {test_loss.item():.4f}")

# Step 7: Make a prediction
print("Making predictions...")
new_data = torch.tensor(data_normalized[-1:, :], dtype=torch.float32)  # Use the most recent row (all 5 features)
predicted_price = model(new_data)

# Perform the inverse transformation only on the original features (not including the predicted price)
scaled_prediction = new_data.numpy()  # Get the original 5 feature columns

# Inverse transform only the features (not the predicted 'Close')
inverse_transformed_data = scaler.inverse_transform(scaled_prediction)

# Now append the predicted 'Close' value to the inverse-transformed data
predicted_price_actual = np.hstack((inverse_transformed_data, predicted_price.detach().numpy().reshape(-1, 1)))

# The 'predicted_price_actual' now contains the original features and the predicted 'Close' value
print(f"Predicted Next Day Closing Price: {predicted_price_actual[0, -1]:.2f}")
