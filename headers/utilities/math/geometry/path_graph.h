#pragma once
#include "intersection_data.h"

namespace math {
    namespace geometry {
        class PathGraph {
        public:
            PathGraph(const std::vector<vector::Vec2>&);
            bool isIntersecting(const PathGraph&, IntersectionData&) const;
            PathGraph& adjusted(vector::Vec2, float, float) const;
        private:
            bool isIntersecting(const std::vector<vector::Vec2>&, IntersectionData&) const;
            bool isSelfIntersecting() const;
            bool areLinesIntersecting(vector::Vec2, vector::Vec2, vector::Vec2, vector::Vec2, vector::Vec2&) const;        
            const std::vector<vector::Vec2> points;
        };
    }
}

// namespace math {
//     namespace geometry {
//         class PathGraph {
//         public:
//             PathGraph(const std::vector<vector::Vec2>&, bool closed = false);
//             bool isIntersecting(const PathGraph&, IntersectionData&) const;
//             PathGraph& adjusted(vector::Vec2, float, float) const;
//         private:
//             bool isIntersecting(const std::vector<vector::Vec2>&, IntersectionData& intersectionData, bool) const;
//             bool isLineIntersecting(vector::Vec2, vector::Vec2, vector::Vec2, vector::Vec2, vector::Vec2&) const;        
//             const std::vector<vector::Vec2> points;
//         };
//     }
// }