// sample_strategy.h
#ifndef SAMPLE_STRATEGY_H
#define SAMPLE_STRATEGY_H

#include "strategy.h"

class SampleStrategy : public Strategy {
public:
    bool should_buy(const std::vector<PriceData>& data) override;
    bool should_sell(const std::vector<PriceData>& data) override;
};

#endif // SAMPLE_STRATEGY_H
