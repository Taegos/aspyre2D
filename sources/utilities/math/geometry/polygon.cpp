#pragma once
#include "polygon.h"
#include "iostream"
using namespace math::vector;
using namespace math::geometry;

Polygon::Polygon(const std::vector<Vec2>& _points, bool closed) : points { _points } {

}


bool Polygon::isIntersecting(const Polygon& other, IntersectionData& intersectionData) const {
    bool intersection = false;
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 0; j < other.points.size() - 1; j++) {    
            Vec2 intersectionPoint {};    
            intersection = isIntersecting(
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
    return intersection;
}

bool Polygon::isIntersecting(Vec2 pA, Vec2 pB, Vec2 pC, Vec2 pD, Vec2& intersectionPoint) const { 
    Vec2 pAB = pB-pA;
    Vec2 pCD = pD-pC;
    float divisor = pAB.cross(pCD);
    if (divisor == 0) {
        Vec2 pBC = pC - pB;      
        if (pAB.x * pBC.y != pAB.y * pBC.x) {
            return false;
        }
        float a = pA.x+pA.y;
        float b = pD.x+pB.y;
        float c = pD.x+pC.y;
        float d = pD.x+pD.y;
       // Vec2 tmp = intersectionPoint;
        if (a <= c && c <= b) {
            return true;
            //float r = (b - c)
            // Vec2 pCB = pB - pC;
            // intersectionPoint = pC+pCB*(c / b); 
            //intersectionPoint = pC;
            //pc -> pb
        }
        else if(c <= a && a <= d) {
            return true;
        }
        else if(a <= c && d <= b) {
            return true;
        }
        else if(c <= a && b <= d) {
            return true;
        }
        // if (tmp != intersectionPoint) {
        //     return true;
        // }
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

Polygon& Polygon::adjusted(Vec2 origin, float rotation, float scale) const {
    return Polygon(points);    
}