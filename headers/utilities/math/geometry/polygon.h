#pragma once
#include "intersection_data.h"

namespace math {
    namespace geometry {
        class Polygon {
        public:
            Polygon(const std::vector<vector::Vec2>&, bool closed = false);
            bool isIntersecting(const Polygon&, IntersectionData&) const;
            Polygon& adjusted(vector::Vec2, float, float) const;
        private:
            bool isIntersecting(vector::Vec2, vector::Vec2, vector::Vec2, vector::Vec2, vector::Vec2&) const;        
            std::vector<vector::Vec2> points;
        };
    }
}