#pragma once
#include "polygon.h"
#include "iostream"
using namespace math::vector;
using namespace math::geometry;

Polygon::Polygon(const std::vector<Vec2>& _points, bool closed) : points { _points } {

}


bool Polygon::getIntersection(const Polygon& other, IntersectionData& intersectionData) const {
    bool intersection = false;
    for (int i = 0; i < points.size() - 1; i++) {
        for (int j = 0; j < other.points.size() - 1; j++) {    
            Vec2 intersectionPoint {};    
            intersection = getIntersection(
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

//y = kx + m
//y = slopeA * x + interceptA
//y = slopeB * x + interceptB
//slopeA * x + interceptA = slopeB * x + interceptB
//slopeA * x - slopeB * x = interceptB - interceptA
//x(slopeA - slopeB) = interceptB - interceptA 
//x = (interceptB - interceptA) / (slopeA - slopeB)
bool Polygon::getIntersection(const Vec2& pointA1, const Vec2& pointA2, const Vec2& pointB1, const Vec2& pointB2, Vec2& intersectionPoint) const{
    float slopeA = (pointA2.y - pointA1.y) / (pointA2.x - pointA1.x);
    float interceptA = pointA1.y - slopeA * pointA1.x;
    float slopeB = (pointB2.y - pointB1.y) / (pointB2.x - pointB1.x);
    float interceptB = pointB1.y - slopeB * pointB1.x;
    float x = (interceptB - interceptA) / (slopeA - slopeB);
    float yA = slopeA * x + interceptA;
    float yB = slopeB * x + interceptB;
    std::cout << yA << std::endl;
    std::cout << yB << std::endl;
    if (abs(yA-yB) <= FLT_EPSILON) {
        intersectionPoint = { x, yA };
        return true;
    }
    return false;
}

Polygon& Polygon::adjusted(Vec2 origin, float rotation, float scale) const {
    return Polygon(points);    
}