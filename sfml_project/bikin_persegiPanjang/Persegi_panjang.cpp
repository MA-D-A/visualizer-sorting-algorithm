#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "judul");
    sf::RectangleShape rectangle({400.f, 200.f});
    rectangle.setOrigin({100.f, 100.f});
    rectangle.setPosition({200.f, 200.f});
    // rectangle.setScale({1.f, 1.5f});
    rectangle.setRotation(sf::degrees(15.f));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setOutlineThickness(-20.f);
    rectangle.setOutlineColor(sf::Color::Cyan);
    while (window.isOpen()) {

        while (std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {

                window.close();
            } else if (event->is<sf::Event::Resized>()) {
                sf::View view({400.f, 300.f}, sf::Vector2f(window.getSize()));
                window.setView(view);
            }
        }

        window.clear(sf::Color::Magenta);
        window.draw(rectangle);
        window.display();
    }
    return 0;
}