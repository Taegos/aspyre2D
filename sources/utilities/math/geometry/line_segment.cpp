#pragma once
#include "line_segment.h"
using namespace math::geometry;
using namespace math::vector;

LineSegment::LineSegment(Vec2 _pointA, Vec2 _pointB) :
    pointA { _pointA},
    pointB { _pointB} {
}

IntersectionData* LineSegment::getIntersection(const LineSegment& other) const {
    return nullptr;
}


// namespace math {
//     namespace geometry {
//         class LineSegment {
//         public:
//             LineSegment(vector::Vec2, vector::Vec2);
//             IntersectionData* getIntersection(const LineSegment&) const;
//             LineSegment& adjusted(vector::Vec2, float, float) const;
//         private:
//             const vector::Vec2 pointA;
//             const vector::Vec2 pointB;
//         };
//     }
// }