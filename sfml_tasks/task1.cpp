#include <fmt/core.h>
#include <SFML/Graphics.hpp>
#include <deque>

auto main() -> int {

    auto window = sf::RenderWindow(
            sf::VideoMode({800, 600}),
            "Task 1",
            sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );

    auto square = sf::RectangleShape(sf::Vector2f(100.f, 100.f));
    square.setFillColor(sf::Color::Blue);

    auto position = sf::Vector2f(100, 100);
    auto velocity = sf::Vector2f(0.02f, 0.02f);

    auto colorsDeque = std::deque<sf::Color>(
            {sf::Color::White,
             sf::Color::Red,
             sf::Color::Magenta,
             sf::Color::Yellow,
             sf::Color::Green,
             sf::Color::Blue,
             sf::Color::Black
            });

    auto globalClearColor = sf::Color::Black;
    while (window.isOpen()) {

        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                auto clicked = event.mouseButton;
                auto squarePosition = square.getPosition();
                auto color = colorsDeque[0];
                colorsDeque.pop_front();
                if (
                        (clicked.x >= squarePosition.x && clicked.x <= squarePosition.x + square.getSize().x) &&
                        (clicked.y >= squarePosition.y && clicked.y <= squarePosition.y + square.getSize().y)
                        ) {
                    fmt::println("clicked");
                    square.setFillColor(color);
                } else {
                    globalClearColor = color;
                    fmt::println("else");
                }
                colorsDeque.push_back(color);
            }
        }

        position += velocity;

        if (position.x < 0 || position.x + square.getSize().x > window.getSize().x) {
            velocity.x = -velocity.x;
        }
        if (position.y < 0 || position.y + square.getSize().y > window.getSize().y) {
            velocity.y = -velocity.y;
        }
        square.setPosition(position);

        // Drawing the shape on the screen
        window.clear(globalClearColor);
        window.draw(square);
        window.display();
    }

    return 0;
}