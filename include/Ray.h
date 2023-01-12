#ifndef __RAY_H
#define __RAY_H

#include <cstdint>

#include "Vector.h"

class Ray
{
    protected :

    Vector dir;
    Vector pos;

    public :

    Ray(const Vector& rDir, const Vector& rPos): dir(rDir), pos(rPos) {}

    Ray(const Ray& ray):dir(ray.dir), pos(ray.pos) {}

    Vector& getDir()
    {
        return dir;
    }

    Vector& getPos()
    {
        return pos;
    }


};


#endif
