#ifndef PLANE_H
#define PLANE_H

#include "Drawable.h"
#include "Vector.h"
#include "Ray.h"
#include <iostream>

class Plane: public Drawable {
    protected : 
    Vector normal;
    Vector position;

    public:
    Plane(const Vector& normal, const Vector& position);
    double_t GetClosestIntersection(const Ray& ray, float_t min, float_t max) const override;
    std::ostream& print(std::ostream& os) const override;
};

 #endif