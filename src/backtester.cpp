#include "backtester.h"

Backtester::Backtester(Strategy* strat, const std::vector<PriceData>& data, double starting_cash)
    : strategy(strat), market_data(data), net_profit(0.0), starting_cash(starting_cash) {}

void Backtester::run() {
    double cash = starting_cash; // Use the user-defined starting cash
    double position = 0.0; // Current stock position

    for (size_t i = 1; i < market_data.size(); ++i) {
        std::vector<PriceData> data_slice(market_data.begin(), market_data.begin() + i);
        const PriceData& current_data = market_data[i];

        if (strategy->should_buy(data_slice) && cash >= current_data.close) {
            // Buy one unit
            position += 1;
            cash -= current_data.close;
            std::cout << "Buying at: " << current_data.close << std::endl;
        }

        if (strategy->should_sell(data_slice) && position > 0) {
            // Sell one unit
            position -= 1;
            cash += current_data.close;
            std::cout << "Selling at: " << current_data.close << std::endl;
        }
    }

    // Final value calculation
    double final_value = cash + position * market_data.back().close;
    net_profit = final_value - starting_cash; // Subtract the user-defined starting cash
    std::cout << "Final Net Profit: " << net_profit << std::endl;
}

double Backtester::get_net_profit() const {
    return net_profit;
}
