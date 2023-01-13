#include <vector>

#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "Vector.h"
#include "Drawables.h"
#include "Vector.h"

int main()
{
    std::vector<Drawable*> scene{
        new Sphere(Vector(2, 2, 0), 0.5), 
        };

    Camera camera(Vector(), Vector(1, 1, 0), 200, 200, 2);

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    sf::Image image;
    
    camera.renderImage(image, scene);

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

    delete scene[0];

    return 0;
}