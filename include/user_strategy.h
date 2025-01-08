#ifndef USER_STRATEGY_H
#define USER_STRATEGY_H

#include "strategy.h"
#include <vector>
#include <string>
#include <iostream> // For user input

class UserStrategy : public Strategy {
public:
    // Constructor to get user input for thresholds
    UserStrategy();

    // Override the should_buy and should_sell methods
    bool should_buy(const std::vector<PriceData>& data) override;
    bool should_sell(const std::vector<PriceData>& data) override;

private:
    double buy_threshold;
    double sell_threshold;
};

#endif // USER_STRATEGY_H