#include <SFML/Graphics.hpp>

#include "Camera.h"

int main()
{
    Camera camera(200, 200);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    sf::Image image;
    
    camera.RenderImage(image);

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}