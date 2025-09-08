#include <SFML/Graphics.hpp>
#include <algorithm>

int main() {
    // data
    int data[] = {1, 2, 3, 4, 5};
    int data_n = sizeof(data) / sizeof(data[0]);
    int data_max = *std::max_element(data, data + data_n);

    // create window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Title");

    // bar
    sf::RectangleShape bar;
    bar.setFillColor(sf::Color(0, 170, 255));

    // while window is still open
    while (window.isOpen()) {
        // handle events - SFML 3.0 style
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

        // size of window
        float window_w = static_cast<float>(window.getSize().x);
        float window_h = static_cast<float>(window.getSize().y);

        // parameters
        float size = 0.6f * window_w / data_n;
        float scale = 0.9f * window_h / data_max;
        float space = window_w / data_n;

        // fill window with color
        window.clear(sf::Color(64, 64, 64));

        // draw
        bar.setOrigin({size / 2, 0.f});
        bar.setScale({1.f, -1.f});
        for (int i = 0; i < data_n; i++) {
            bar.setSize({size, data[i] * scale});
            bar.setPosition({(i + 0.5f) * space, window_h});
            window.draw(bar);
        }

        // display
        window.display();
    }

    // program end successfully
    return 0;
}