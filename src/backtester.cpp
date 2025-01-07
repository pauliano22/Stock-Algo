// backtester.cpp
#include "backtester.h"
#include <iostream>

Backtester::Backtester(Strategy* strategy, const std::vector<PriceData>& market_data)
    : strategy(strategy), market_data(market_data) {}

void Backtester::run() {
    bool holding = false;  // Whether we are holding a position or not

    for (const auto& data : market_data) {
        if (strategy->should_buy(market_data) && !holding) {
            std::cout << "Buying at: " << data.close << std::endl;
            holding = true;
        }
        if (strategy->should_sell(market_data) && holding) {
            std::cout << "Selling at: " << data.close << std::endl;
            holding = false;
        }
    }
}
