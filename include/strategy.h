// strategy.h
#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "data_parser.h"  // To use PriceData

class Strategy {
public:
    // Virtual methods to be overridden by derived classes
    virtual bool should_buy(const std::vector<PriceData>& data) = 0;
    virtual bool should_sell(const std::vector<PriceData>& data) = 0;
    virtual ~Strategy() {}
};

#endif // STRATEGY_H
