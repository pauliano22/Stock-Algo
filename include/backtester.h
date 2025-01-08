// backtester.h
#ifndef BACKTESTER_H
#define BACKTESTER_H

#include <iostream>
#include <vector>
#include "strategy.h"
#include "data_parser.h"  // For PriceData

class Backtester {
private:
    Strategy* strategy;
    std::vector<PriceData> market_data;
    double net_profit; // Track net profit
    double starting_cash; // Store the starting cash

public:
    Backtester(Strategy* strat, const std::vector<PriceData>& data, double starting_cash);

    void run();

    // Getter for net profit
    double get_net_profit() const;
};

#endif // BACKTESTER_H
