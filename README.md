# Stock-ALGO

**Quantitative Portfolio Trading Backtesting Engine with C++ and PyTorch**

## Overview

A robust backtesting engine designed to evaluate quantitative trading strategies. Combining the power of C++ for speed and efficiency with PyTorch's' ML models, this engine allows users to test, analyze, and refine strategies using historical stock data.

### Features
- **LSTM-based Stock Prediction Model**:
  - Utilizes PyTorch to implement and train a Long Short-Term Memory (LSTM) model on Yahoo Finance data.
  - Predicts future stock prices using historical time series data.

- **Backtesting Engine**:
  - Written in C++ for high-performance simulations.
  - Simulates various trading strategies over historical data to evaluate performance.

- **Data Handling**:
  - Parses and preprocesses financial data efficiently.
  - Supports input from multiple data sources.

- **Custom Strategies**:
  - Create and test user-defined trading strategies.
  - Evaluate performance metrics like Sharpe ratio, drawdown, and return on investment.

### Directory Structure
- `/data`: Contains datasets used for backtesting.
- `/model`: Includes the LSTM model and PyTorch-related files.
- `/src`: Core C++ implementation of the backtesting engine.
- `/tests`: Unit tests for verifying the functionality of the engine.
- `/include`: Header files for the project.
- `/build`: Compiled binaries and build artifacts.

### Prerequisites
#### Dependencies:
- **C++**: A modern C++ compiler supporting C++17.
- **Python**: Python 3.8+ with the following libraries:
  - PyTorch
  - NumPy
  - Pandas
- **CMake**: Build system for compiling the C++ engine.
