#ifndef SPHERE_H
#define SPHERE_H

#include <math.h>
#include <iostream>

#include "Drawables/Drawable.h"

#include "Vector.h"
#include "Ray.h"

class Sphere : public Drawable
{
    public :
    const Vector center;
    const float_t radius;

    Sphere(const Vector& v, float_t r) : Drawable(), center(v), radius(r) {}

    Sphere(const Sphere& s) : center(s.center), radius(s.radius) {}

    friend std::ostream& operator<<(std::ostream& os, const Sphere& s);

    double_t GetClosestIntersection(const Ray & ray, float_t min, float_t max) const override;
};

#endif