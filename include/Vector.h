#ifndef __VECTOR_H
#define __VECTOR_H

#include <cstdint>
#include <cmath>

#include <iostream>

struct Vector
{
    const int32_t x;
    const int32_t y;
    const int32_t z;

    Vector(int32_t x1 = 0, int32_t y1 = 0, int32_t z1 = 0): x(x1), y(y1), z(z1) {}

    Vector(const Vector& v): x(v.x), y(v.y),z(v.z) {}
    
    bool operator == (const Vector& v) const
    {
        return x==v.x && y==v.y && z==v.z;
    }

    Vector operator + (const Vector& v) const
    {
        return Vector(x+v.x, y+v.y, z+v.z);
    }

    Vector operator - (const Vector& v) const
    {
        return Vector(x-v.x, y-v.y, z-v.z);
    }

    Vector operator * (const Vector& v) const
    {
        return Vector(x*v.x, y*v.y, z*v.z);
    }

    Vector operator * (int i) const
    {
        return Vector(i*x, i*y, i*z);
    }

    friend Vector operator * (int i, const Vector& v);

    Vector operator / (const Vector& v) const
    {
        return Vector(x*v.x, y*v.y, z*v.z);
    }

    Vector operator / (int i) const
    {
        return Vector(x/i, y/i, z/i);
    }

    friend Vector operator / (int i, const Vector& v);

    int normSq() const
    {
        return x*x+y*y+z*z;
    }

    int norm() const
    {
        return sqrt(normSq());
    }

    Vector normalized() const
    {
        return *this/norm();
    }

    int dot(const Vector& v) const
    {
        return x*v.x+y*v.y+z*v.z;
    }

    Vector cross(const Vector& v) const
    {
        return Vector(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
    }

    friend std::ostream& operator << (std::ostream& os, const Vector& v);

};

Vector operator * (int i, const Vector& v)
{
    return v*i;
}

Vector operator / (int i, const Vector& v)
{
    return Vector(i/v.x, i/v.y, i/v.z);
}

std::ostream& operator << (std::ostream& os, const Vector& v)
{
    return os << "Vector(x=" << v.x << ", y=" << v.y << ", z=" << v.z << ")";
}

#endif