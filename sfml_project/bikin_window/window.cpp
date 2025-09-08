#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode({800, 800}), "judul");
    while (window.isOpen()) {

        while (std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {

                window.close();
            }
        }
        window.clear(sf::Color::Red);
        window.display();
    }
    return 0;
}