// strategy.cpp
#include "strategy.h"

// Base class does not need to implement the buy/sell methods itself
// These methods are purely virtual, meaning derived classes must implement them

bool Strategy::should_buy(const std::vector<PriceData>& data) {
    // This is a placeholder. Derived classes must implement this.
    return false;
}

bool Strategy::should_sell(const std::vector<PriceData>& data) {
    // This is a placeholder. Derived classes must implement this.
    return false;
}
