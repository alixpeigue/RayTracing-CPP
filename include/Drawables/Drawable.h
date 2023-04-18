#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Vector.h"
#include "Ray.h"

class Drawable
{
    public :
    virtual ~Drawable() {};
    virtual double_t GetClosestIntersection(const Ray & ray, float_t min, float_t max) const = 0;
    virtual std::ostream& print(std::ostream& os) const;
    friend std::ostream& operator << (std::ostream& os, const Drawable& d);
};

#endif