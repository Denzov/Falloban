#ifndef THEMOLLUSK_VEC2_H
#define THEMOLLUSK_VEC2_H

#include "Constants.h"

namespace Math{
    struct Vec2{
        float x, y;

        Vec2 operator+(const Vec2& other) const;
        Vec2& operator+=(const Vec2& other);

        Vec2 operator-(const Vec2& other) const;
        Vec2& operator-=(const Vec2& other);

        Vec2 operator*(const Vec2& other) const;
        Vec2 operator*(const float other) const;
        Vec2& operator*=(const Vec2& other);
        Vec2& operator*=(const float other);

        Vec2 operator/(const Vec2& other) const;
        Vec2 operator/(const float other) const;
        Vec2& operator/=(const Vec2& other);
        Vec2& operator/=(const float other);

        float length() const;
        float lengthSq() const;

        float angle() const;
        Vec2 rotated(float angle) const;
        
        Vec2 normalized() const;
    };

    float distance_sq(Vec2 v1, Vec2 v2);
    float distance(Vec2 v1, Vec2 v2);
    float dot(Vec2 v1, Vec2 v2);
    float angle_from_to(Vec2 from, Vec2 to);
    bool near(Vec2 v1, Vec2 v2, float epsilon = Math::Epsilon);
    bool near_zero(Vec2 v, float epsilon = Math::Epsilon);
}
Math::Vec2 operator/(float scalar, const Math::Vec2& vec);

#endif // !THEMOLLUSK_VEC2_H