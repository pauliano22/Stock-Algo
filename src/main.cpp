#include "data_parser.h"
#include "strategy.h"
#include "backtester.h"
#include "user_strategy.h"
#include <vector>
#include <filesystem>
#include <iostream>

int main() {
    // Prompt the user for starting cash
    double starting_cash;
    std::cout << "Enter your starting cash: ";
    std::cin >> starting_cash;
    // Load the market data (CSV file)
    DataParser p;
    std::vector<PriceData> market_data = p.load_csv("C:/Users/pmi/OneDrive - Cornell University/Desktop/Projects/c++projects/backtesting-engine/data/market_data.csv");

    // Create a sample strategy
    UserStrategy strategy;

    // Create the backtester
    Backtester backtester(&strategy, market_data, starting_cash);

    // Run the backtest
    backtester.run();

    return 0;
}
