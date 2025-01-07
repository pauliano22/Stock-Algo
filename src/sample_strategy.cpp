// sample_strategy.cpp
#include "sample_strategy.h"

bool SampleStrategy::should_buy(const std::vector<PriceData>& data) {
    if (data.empty()) return false;
    return data.back().close > data[data.size() - 2].close;
}

bool SampleStrategy::should_sell(const std::vector<PriceData>& data) {
    if (data.empty()) return false;
    return data.back().close < data[data.size() - 2].close;
}
