#ifndef THE_MOLLUSK_FUNCTIONS_H
#define THE_MOLLUSK_FUNCTIONS_H

#include <cmath>
#include "Constants.h"

namespace Math{
    inline constexpr float normalize(float value, float start, float end){
        float result = (value - start)/(end - start);
        return result;
    }

    inline constexpr bool near(float a, float b, float epsilon = Math::Epsilon) {
        return std::abs(a - b) <= epsilon;
    }

    inline constexpr bool near_zero(float value, float epsilon = Math::Epsilon) {
        return std::abs(value) <= epsilon;
    }
}

#endif // !THE_MOLLUSK_FUNCTIONS_H