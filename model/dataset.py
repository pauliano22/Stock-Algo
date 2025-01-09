import pandas as pd
import torch
from torch.utils.data import Dataset, DataLoader

# Load market data
df = pd.read_csv('market_data.csv')

# Define a sliding window function to create features and targets
def create_dataset(data, window_size=5):
    features, targets = [], []
    for i in range(len(data) - window_size):
        features.append(data[i:i+window_size])
        targets.append(data[i+window_size])
    return torch.tensor(features, dtype=torch.float32), torch.tensor(targets, dtype=torch.float32)

# Prepare dataset
prices = df['close'].values
X, y = create_dataset(prices, window_size=5)
