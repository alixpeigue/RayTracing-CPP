#include <iostream>

#include "Drawables/Sphere.h"

// Sphere::Sphere(const Vector& v, float_t r) : Drawable(), center(v), radius(r) {}

// Sphere::Sphere(const Sphere& s) : center(s.center), radius(s.radius) {}

std::ostream& operator<<(std::ostream& os, const Sphere& s)
{
    return os << "Sphere(center=" << s.center << ", radius=" << s.radius << ")";
}

double_t Sphere::GetClosestIntersection(const Ray &ray, float_t min, float_t max) const
{
    Vector toCenter = ray.pos - center;
    double_t a = 1;
    double_t halfB = toCenter.dot(ray.dir);
    double_t c = toCenter.normSq()-radius*radius;

    double_t quarterDelta = halfB*halfB-a*c;
    if(quarterDelta<0){
        return -1;
    }
    double_t root = (-halfB-sqrt(quarterDelta))/a;
    if (root<min || root > max){
        root = (-halfB+sqrt(quarterDelta))/a;
        if(root<min || root > max){
            return -1;
        }
    }
    return root;
}