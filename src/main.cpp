#include <vector>
#include <memory>
#include <utility>

#include <SFML/Graphics.hpp>

#include "Camera.h"
#include "Vector.h"
#include "Drawables.h"
#include "Vector.h"

int main()
{
    std::vector<std::unique_ptr<Drawable>> scene;
    scene.push_back(std::make_unique<Sphere>(Vector(2, 2, 0), 0.5));
    scene.push_back(std::make_unique<Plane>(Vector::X, Vector()));
        // std::make_unique<Sphere>(Vector(2, 2, 0), 0.5),
    // };
    std::cout << *scene[0];
    std::cout << *scene[1];

    Camera camera(Vector(), Vector(1, 0, 0), 200, 200, 2);

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
            else if (event.type == sf::Event::Resized)
            {
                std::cout<< "on passe\n";
                sprite.setScale(200./window.getSize().x, 200./window.getSize().y);
                camera = Camera(Vector(), Vector(1, 1, 0), window.getSize().x, window.getSize().y, 2);
                std::cout << camera << "\n";
                
                camera.renderImage(image, scene);
                // image.saveToFile("out.png");

                // std::cout << image << "\n";

                texture.loadFromImage(image);

                sprite.setTexture(texture, true);
                // sprite.setScale(0.5, 0.5);

                window.clear(sf::Color(255, 255, 255, 255));
                window.draw(sprite);
                window.display();   
                std::cout<< "Sprite " << sprite.getScale().x << sprite.getScale().y << std::endl;            
            }
        }
        // image.saveToFile("out2.png");
        // window.clear();
        // window.draw(sprite);
        // window.display();   
    }
    return 0;
}