#pragma once
#include "path_graph.h"
#include "iostream"
using namespace math::vector;
using namespace math::geometry;

PathGraph::PathGraph(const std::vector<Vec2>& _points) : 
    points { _points }
{
    if (points.size() == 1) {
        throw std::invalid_argument("The amount of points have to be larger than 1.");
    }
    if (isSelfIntersecting()) {
        throw std::invalid_argument("The path is self intersecting.");
    }
}

bool PathGraph::isIntersecting(const PathGraph& other, IntersectionData& intersectionData) const {
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 0; j < other.points.size() - 1; j++) {             
            Vec2 intersectionPoint {-1000000, -1000000};    
            bool intersection = areLinesIntersecting(
                points[i],
                points[i+1],
                other.points[j],
                other.points[j+1],
                intersectionPoint           
            );
            if (intersection) {
                intersectionData.pointsOfIntersection.push_back(intersectionPoint);
            }
        }
    }
    if (intersectionData.pointsOfIntersection.size() > 0) {
        return true;
    }
    return false;
}

bool PathGraph::isSelfIntersecting() const {
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 0; j < points.size() - 1; j++) {  
            Vec2 pA = points[i];
            Vec2 pB = points[i+1];
            Vec2 pC = points[j];
            Vec2 pD = points[j+1];
            if (pA == pB || pC == pD) {                
                return true;
            }
            if (pA == pC ||
                pA == pD ||
                pB == pC ||
                pB == pD) {
                continue;
            }            
            bool intersecting = areLinesIntersecting(pA, pB, pC, pD, Vec2{});        
            if (intersecting) {
                return true;
            }
        }
    }
    return false;
}

bool PathGraph::areLinesIntersecting(Vec2 pA, Vec2 pB, Vec2 pC, Vec2 pD, Vec2& intersectionPoint ) const { 
    Vec2 pAB = pB-pA;
    Vec2 pCD = pD-pC;
    float divisor = pAB.cross(pCD);
    if (divisor == 0) {          
        if (pB.cross(pC) != 0 && pA != pC && pB != pD) {
            return false;
        }
        float a = pA.x+pA.y;
        float b = pB.x+pB.y;
        float c = pC.x+pC.y;
        float d = pD.x+pD.y;
        if (a > b) {
            a = pB.x+pB.y;
            b = pA.x+pA.y;
        }
        if (c > d) {
            c = pD.x+pD.y;
            d = pC.x+pC.y;
        }
        float roll = (float)rand() / (float)RAND_MAX;
        Vec2 tmp = intersectionPoint;
        if (a <= c && c <= b) {             
            intersectionPoint = pC + (pB - pC) * roll;
        }
        else if(c <= a && a <= d) {
            intersectionPoint = pA + (pD - pA) * roll;
        }
        else if(a <= c && d <= b) {
            intersectionPoint = pC + (pD - pC) * roll;
        }
        else if(c <= a && b <= d) {
            intersectionPoint = pA + (pB - pA) * roll;
        }
        if (intersectionPoint != tmp) {
            return true;
        }
        return false;
    }
    if (divisor == 0) {
        throw std::runtime_error("Can't divide by 0, lines are parallel.");
    }
    Vec2 pCA = pC-pA;
    float t = pCA.cross(pCD) / divisor;
    float u = pCA.cross(pAB) / divisor;
    if (0 <= t && t <= 1 && 0 <= u && u <= 1) {
        intersectionPoint = pA + pAB * t;
        return true;
    }  
    return false;
}

PathGraph& PathGraph::adjusted(Vec2 origin, float rotation, float scale) const {
    return PathGraph(points);    
}