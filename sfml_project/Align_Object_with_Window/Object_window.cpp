#include <SFML/Graphics.hpp>
#include <iostream>
int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "aplikasi_pas");

    // top-left
    sf::RectangleShape topLeft({200.f, 100.f});
    topLeft.setFillColor(sf::Color::Cyan);
    // top-right
    sf::RectangleShape topRight({200.f, 100.f});
    topRight.setOrigin({200.f, 0.f});
    topRight.setFillColor(sf::Color::Cyan);
    // bottomLeft
    sf::RectangleShape bottomLeft({200.f, 100.f});
    bottomLeft.setOrigin({0.f, 100.f});
    bottomLeft.setFillColor(sf::Color::Cyan);
    // bottom-right
    sf::RectangleShape bottomRight({200.f, 100.f});
    bottomRight.setOrigin({200.f, 100.f});
    bottomRight.setFillColor(sf::Color::Cyan);
    // top
    sf::RectangleShape top({200.f, 100.f});
    top.setOrigin({100.f, 0.f});
    top.setFillColor(sf::Color::Cyan);

    // bottom
    sf::RectangleShape bottom({200.f, 100.f});
    bottom.setOrigin({100.f, 100.f});
    bottom.setFillColor(sf::Color::Cyan);

    // left
    sf::RectangleShape left({200.f, 100.f});
    left.setOrigin({0.f, 50.f});
    left.setFillColor(sf::Color::Cyan);

    // right
    sf::RectangleShape right({200.f, 100.f});
    right.setOrigin({200.f, 50.f});
    right.setFillColor(sf::Color::Cyan);

    // center
    sf::RectangleShape center({200.f, 100.f});
    center.setOrigin({100.f, 50.f});
    center.setFillColor(sf::Color::Cyan);

    // while window is still open
    while (window.isOpen()) {
        // handle events
        while (std::optional event = window.pollEvent()) {
            // when close button is clicked
            if (event->is<sf::Event::Closed>()) {
                // close window
                window.close();
            }
            // when window is resized
            else if (event->is<sf::Event::Resized>()) {
                // update view
                sf::View view(
                    sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
        }

        // set position
        float window_w = static_cast<float>(window.getSize().x);
        float window_h = static_cast<float>(window.getSize().y);
        topRight.setPosition({window_w, 0.f});
        bottomLeft.setPosition({0.f, window_h});
        bottomRight.setPosition({window_w, window_h});
        top.setPosition({window_w / 2, 0.f});
        bottom.setPosition({window_w / 2, window_h});
        left.setPosition({0.f, window_h / 2});
        right.setPosition({window_w, window_h / 2});
        center.setPosition({window_w / 2, window_h / 2});
        // fill window with color
        window.clear(sf::Color(127, 127, 127));
        // draw
        window.draw(topLeft);
        window.draw(topRight);
        window.draw(bottomLeft);
        window.draw(bottomRight);
        window.draw(top);
        window.draw(bottom);
        window.draw(left);
        window.draw(right);
        window.draw(center);
        // display
        window.display();
    }
    // program end successfully
    return 0;
}