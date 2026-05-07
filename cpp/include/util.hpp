#pragma once

#include <cstdint>

namespace util {
    template <uint32_t N>
    uint32_t modulus(int64_t value) {
        value %= N;
        if (value < 0) {
            return value + N;
        }
        return value;
    }
}
