#include <iostream>

#include "Camera.h"
#include "Vector.h"
#include "Ray.h"

Camera::Camera(int32_t w, int32_t h): width(w), height(h) {}

sf::Image& Camera::RenderImage(sf::Image & image )
{
    Vector v1(1, 1, 1);
    Vector v2(2, 2, 2);
    Vector v3 = v2+2*v1;
    //Ray r(v1, v2);
    //std::cout << r.getDir() << std::endl;
    image.create(width, height);
    image.setPixel(10, 10, sf::Color(0, 0, 255));
    return image;
}