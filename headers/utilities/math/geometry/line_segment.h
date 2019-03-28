#pragma once
#include "intersection_data.h"

namespace math {
    namespace geometry {
        class LineSegment {
        public:
            LineSegment(vector::Vec2, vector::Vec2);
            IntersectionData* getIntersection(const LineSegment&) const;
        private:
            const vector::Vec2 pointA;
            const vector::Vec2 pointB;
        };
    }
}