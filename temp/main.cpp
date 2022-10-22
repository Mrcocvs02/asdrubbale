#include <SFML/Graphics.hpp>

int main() {

    sf::RenderWindow window(sf::VideoMode(940, 940), "My window");
    window.setFramerateLimit(24);
        sf::CircleShape shape(50.f);
        shape.setOutlineThickness(1.f);
        shape.setFillColor(sf::Color(28, 239, 198));
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(23, 48, 73));
        for(int i=0; i<400; i++){
        shape.setPosition(400, 400);
        window.draw(shape);

        window.display();
        }
    }

    return 0;

}