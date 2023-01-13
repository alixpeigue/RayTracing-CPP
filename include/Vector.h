#if !defined(VECTOR_H)
#define VECTOR_H

#include <cstdint>
#include <cmath>

#include <iostream>

struct Vector
{
    const float_t x;
    const float_t y;
    const float_t z;

    Vector(float_t x1 = 0, float_t y1 = 0, float_t   z1 = 0): x(x1), y(y1), z(z1) {}

    Vector(const Vector& v): x(v.x), y(v.y),z(v.z) {
        //std::cout << "Copie de Vecteur" << std::endl;
    }
    
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

    Vector operator * (float_t i) const
    {
        return Vector(i*x, i*y, i*z);
    }

    friend Vector operator * (float_t i, const Vector& v);

    Vector operator / (const Vector& v) const
    {
        return Vector(x*v.x, y*v.y, z*v.z);
    }

    Vector operator / (float_t i) const
    {
        return Vector(x/i, y/i, z/i);
    }

    friend Vector operator / (float_t i, const Vector& v);

    float_t normSq() const
    {
        return x*x+y*y+z*z;
    }

    float_t norm() const
    {
        return sqrt(normSq());
    }

    Vector normalized() const
    {
        return *this/norm();
    }

    float_t dot(const Vector& v) const
    {
        return x*v.x+y*v.y+z*v.z;
    }

    Vector cross(const Vector& v) const
    {
        return Vector(y*v.z-z*v.y, z*v.x-x*v.z, x*v.y-y*v.x);
    }

    Vector project(const Vector& v) const
    {
        return v.normalized()*dot(v);
    }

    friend std::ostream& operator << (std::ostream& os, const Vector& v);

    // Global Vectors

    static Vector X;
    static Vector Y;
    static Vector Z;

};

#endif