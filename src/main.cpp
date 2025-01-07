#include <iostream>
#include "../include/data_parser.h"
#include "../include/backtester.h"
#include "../include/strategy.h"

int main() {
    // Load market data from a CSV file
    DataParser parser;
    std::vector<PriceData> market_data = parser.load_csv("data/market_data.csv");

    if (market_data.empty()) {
        std::cerr << "Error: No market data loaded." << std::endl;
        return 1; // Exit if no data is loaded
    }

    // Create a sample strategy (e.g., buy if price drops by 5%)
    class SampleStrategy : public Strategy {
    public:
        bool should_buy(const PriceData& data) override {
            return data.close < data.open * 0.95; // Buy if close < 95% of open
        }
        bool should_sell(const PriceData& data) override {
            return data.close > data.open * 1.05; // Sell if close > 105% of open
        }
    };

    SampleStrategy strategy;

    // Initialize the backtester with the data and initial cash
    Backtester backtester(market_data, 10000.0); // Start with $10,000
    backtester.run(strategy); // Run the simulation

    // Print the results of the backtest
    backtester.print_results();
    return 0;
}
