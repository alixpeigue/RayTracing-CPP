#include "Drawables/Plane.h"
#include "Vector.h"
#include "Ray.h"
#include <iostream>

Plane::Plane(const Vector& normal, const Vector& position) : normal(normal), position(position){}

double_t Plane::GetClosestIntersection(const Ray &ray, float_t min, float_t max) const {
    if(ray.dir.dot(normal)==0){
        return -1; // If the ray is parallel to the plane, it doesn't intersects
    }
    double_t t = (position-ray.pos).dot(normal)/ray.dir.dot(normal);
    if (t<min || t>max){
        return -1;
    }
    std::cout << t << "\n";
    return t;
}

std::ostream& Plane::print(std::ostream &os) const {
    return os << "Plane(normal=" << normal << ", position=" << position << ")\n";
}
