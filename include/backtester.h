#pragma once
#include <vector>
#include "price_data.h"
#include "strategy.h"

class Backtester {
public:
    Backtester(Strategy* strategy, const std::vector<PriceData>& data);
    void run();
private:
    Strategy* strategy;
    std::vector<PriceData> market_data;
};
