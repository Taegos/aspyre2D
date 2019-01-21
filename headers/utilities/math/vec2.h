#pragma once
#include <ostream>
#include <math.h>
namespace math {
    namespace vector {
        template <typename T> struct Vec2 {           
            T x;
            T y;
            
            Vec2<T> operator+(const Vec2<T> & other) const {
                return {x + other.x, y + other.y};
            }
            
            Vec2<T> operator-(const Vec2<T> & other) const {
                return {x - other.x, y - other.y};
            }

            Vec2<T> operator*(const Vec2<T> & other) const {
                return {x * other.x, y * other.y};
            }

            Vec2<T> operator/(const Vec2<T> & other) const{
                return {x / other.x, y / other.y};
            }

            Vec2<T> operator*(float scale) const {
                return {x * scale, y * scale};
            }

            Vec2<T> operator/(float scale) const{
                return {x / scale, y / scale};
            }
            
            void operator*=(float scale) {
                x*=scale;
                y*=scale;
            }

            void operator/=(float scale) {
                x/=scale;
                y/=scale;
            }

            bool operator==(const Vec2<T> & other) const {
                float diff = abs(x-other.x + y-other.y);
                return diff <= 0.015f;
            }

            bool operator!=(const Vec2<T> & other) const {
                return !(*this==other);
            }

            friend std::ostream& operator <<(std::ostream& out, Vec2<T> const& vec) {
                out << '(' << vec.x << ", " << vec.y << ')';
                return out;
            }

            Vec2<T> normalized() {
                float len = sqrt(pow(x, 2) + pow(y, 2));
                return *this / len;
            }
        };
    }
}