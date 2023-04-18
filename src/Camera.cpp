#include <memory>
#include <iostream>
#include <vector>
#include <math.h>

#include "Camera.h"
#include "Vector.h"
#include "Ray.h"

#include "Drawables/Drawable.h"

Camera::Camera(const Vector& cPos, const Vector& cDir, int32_t w, int32_t h, float_t cFov): 
    pos(cPos), dir(cDir.normalized()), width(w), height(h), hfov(cFov), 
    vfov((float_t)h/w*cFov), planeDist(getPlaneDist(w, cFov)), hDir(getHDir(cDir)), vDir(getVDir(cDir)) {}

std::ostream& operator<<(std::ostream& os, const Camera& cam)
{
    os << "Camera(" << std::endl;
    os << " height=" << cam.height << ", " << std::endl;
    os << " width=" << cam.width << ", " << std::endl;
    os << " vfov=" << cam.vfov << ", " << std::endl;
    os << " hfov=" << cam.hfov << ", " << std::endl;
    os << " planeDist=" << cam.planeDist << ", " << std::endl;
    os << " pos=" << cam.pos << ", " << std::endl;
    os << " dir=" << cam.dir << ", " << std::endl;
    os << " hDir=" << cam.hDir << ", " << std::endl;
    os << " vDir=" << cam.vDir << std::endl << ")";
    return os;
}

Ray Camera::getRay(int32_t x, int32_t y) const
{
    return Ray(planeDist*dir+(x-width/2)*hDir+(y-height/2)*vDir, pos);
}

sf::Image&  Camera::renderImage(sf::Image& image, const std::vector<std::unique_ptr<Drawable>>& scene)
{
    image.create(width, height);

    for(int y=0; y<height; y++)
    {
        for(int x=0; x<width; x++)
        {
            sf::Color c = scene.at(0)->GetClosestIntersection(getRay(x, y), 0.1, 100) > -1 ? sf::Color(255, 0, 0) : sf::Color(0, 0, 0);
            image.setPixel(x, y, c);
        }
    }
    std::cout << height/width*hfov << std::endl;
    std::cout << *this << std::endl;
    return image;
}