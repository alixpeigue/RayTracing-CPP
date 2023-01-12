#ifndef __CAMERA_H
#define __CAMERA_H

#include <cstdint>
#include <SFML/Graphics.hpp>

class Camera 
{
    protected :

    int32_t height;
    int32_t width;

    public :

    Camera(int32_t w, int32_t h);

    sf::Image& RenderImage(sf::Image& image);
};


#endif
