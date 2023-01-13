#include "Vector.h"

Vector Vector::X(1, 0, 0);
Vector Vector::Y(0, 1, 0);
Vector Vector::Z(0, 0, 1);

Vector operator * (float_t i, const Vector& v)
{
    return v*i;
}

Vector operator / (float_t i, const Vector& v)
{
    return Vector(i/v.x, i/v.y, i/v.z);
}

std::ostream& operator << (std::ostream& os, const Vector& v)
{
    return os << "Vector(x=" << v.x << ", y=" << v.y << ", z=" << v.z << ")";
}