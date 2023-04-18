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
    protected:

    int32_t height;
    int32_t width;

    float_t vfov;
    float_t hfov;

    float_t planeDist;

    Vector pos;
    Vector dir;

    Vector hDir;
    Vector vDir;

    public:

    Camera(const Vector& cPos, const Vector& cDir, int32_t w, int32_t h, float_t cFov);

    Camera(const Camera& c);

    Camera & operator = (const Camera& c) = default;

    friend std::ostream& operator<<(std::ostream& os, const Camera& cam);

    sf::Image& renderImage(sf::Image& image, const std::vector<std::unique_ptr<Drawable>>& scene);

    // Getters and setters

    int32_t getHeight(){
        return height;
    }

    int32_t getWidth(){
        return width;
    }

    protected:

    Ray getRay(int32_t x, int32_t y) const;

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
