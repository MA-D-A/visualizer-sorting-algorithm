// pasang library
#include <SFML/Graphics.hpp>
#include <algorithm>

int main() {

    // deklarasi_data

    sf::RenderWindow window(sf::VideoMode({300, 400}), "Visual_Sort_Algo");
    // deklarasi_bar
    sf::RectangleShape bar({100.f, 40.0f});
    bar.setFillColor(sf::Color(0, 170, 255));
    while (window.isOpen()) {
        // handler_event
        while (std::optional event = window.pollEvent()) {
            // saat_button_close_di_clicked
            if (event->is<sf::Event::Closed>()) {
                // tutup_window
                window.close();
            }
            // saat_window_di_resized
            else if (event->is<sf::Event::Resized>()) {
                // update_view
                sf::View view(
                    sf::FloatRect({0.f, 0.f}, sf::Vector2f(window.getSize())));
                window.setView(view);
            }
            // set_ukuran_window
            float window_w = static_cast<float>(window.getSize().x);
            float window_h = static_cast<float>(window.getSize().y);

            // set_parameter_bar

            // penuhi_window_dengan_warna
            window.clear(sf::Color(127, 127, 127));

            // gambar

            window.display();
        }
    }
    return 0;
}
