#include "user_strategy.h"
#include <iostream>

UserStrategy::UserStrategy() {
    // Get user input for the buy and sell thresholds
    std::cout << "Enter the buy threshold (ex. -2.34 for a drop in 2.34%): ";
    std::cin >> buy_threshold;
    std::cout << "Enter the sell threshold (ex. 3.45 for an increase of 3.45%): ";
    std::cin >> sell_threshold;
}

bool UserStrategy::should_buy(const std::vector<PriceData>& data) {
    // Check if the price change is greater than or equal to the buy threshold
    double last_close = data[data.size() - 2].close;
    double current_price = data.back().close;
    
    double price_change = ((current_price - last_close) / last_close) * 100;
    std::cout << "Checking buy: " << price_change << "% change" << std::endl;
    
    if (price_change <= buy_threshold) {
        std::cout << "Buying at: " << current_price << std::endl;
        return true; // Buy condition met
    }
    return false; // Buy condition not met
}

bool UserStrategy::should_sell(const std::vector<PriceData>& data) {
    // Check if the price change is greater than or equal to the sell threshold
    double buy_price = data[data.size() - 2].close;  // Assuming last buy was at this price
    double current_price = data.back().close;
    
    double price_change = ((current_price - buy_price) / buy_price) * 100;
    std::cout << "Checking sell: " << price_change << "% change" << std::endl;
    
    if (price_change >= sell_threshold) {
        std::cout << "Selling at: " << current_price << std::endl;
        return true; // Sell condition met
    }
    return false; // Sell condition not met
}
