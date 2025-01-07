#include "data_parser.h"
#include "strategy.h"
#include "backtester.h"
#include "sample_strategy.h"
#include <vector> // Don't forget to include this
#include <filesystem>
#include <iostream>

int main()
{
    // Load the market data (CSV file)
    DataParser p;
    std::vector<PriceData> market_data = p.load_csv("C:/Users/pmi/OneDrive - Cornell University/Desktop/Projects/c++projects/backtesting-engine/data/market_data.csv");

    // Create a sample strategy
    SampleStrategy strategy;

    // Create the backtester
    Backtester backtester(&strategy, market_data);

    // Run the backtest
    backtester.run();

    return 0;
}
