#if !defined(CAMERA_H)
#define CAMERA_H

#include <memory>
#include <vector>
#include <cstdint>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Vector.h"
#include "Ray.h"
#include "Drawables/Drawable.h"

class Camera 
{
    public :

    const int32_t height;
    const int32_t width;

    const float_t vfov;
    const float_t hfov;

    const float_t planeDist;

    const Vector pos;
    const Vector dir;

    const Vector hDir;
    const Vector vDir;

    Camera(const Vector& cPos, const Vector& cDir, int32_t w, int32_t h, float_t cFov);

    friend std::ostream& operator<<(std::ostream& os, const Camera& cam);

    Ray getRay(int32_t x, int32_t y);

    sf::Image& renderImage(sf::Image & image, const std::vector<Drawable*>& scene);

    protected:

    float_t getPlaneDist(int32_t width, float_t hfov)
    {
        return (float_t)width/(2*tan(hfov/2));
    }

    Vector getHDir(const Vector& dir)
    {
        return dir.cross(Vector::Z).normalized();
    }

    Vector getVDir(const Vector& dir)
    {
        return getHDir(dir).cross(dir).normalized();
    }
};


#endif
