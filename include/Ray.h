#if !defined(RAY_H)
#define RAY_H

#include <cstdint>
#include <iostream>

#include "Vector.h"

struct Ray
{
    const Vector dir;
    const Vector pos;

    Ray(const Vector& rDir, const Vector& rPos): dir(rDir.normalized()), pos(rPos) {}

    Ray(const Ray& ray):dir(ray.dir), pos(ray.pos) {}

    Vector getDir() const
    {
        return dir;
    }

    Vector getPos() const
    {
        return pos;
    }

    Vector at(int32_t t) const
    {
        return pos+t*dir;
    }

    Ray bounce(const Vector& point, const Vector& normal)
    {
        return Ray(dir-2*dir.project(normal), point);
    }

    friend std::ostream& operator << (std::ostream& os, const Ray& ray);

};

#endif
