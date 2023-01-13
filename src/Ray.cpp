#include "Ray.h"

std::ostream& operator << (std::ostream& os, const Ray& ray)
{
    return os << "Ray(dir=" << ray.dir << ", pos=" << ray.pos << ")";
}