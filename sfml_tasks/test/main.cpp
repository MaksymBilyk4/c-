#include <SFML/Graphics.hpp>
#include <fmt/core.h>
#include <sstream>

int main() {
    auto window = sf::RenderWindow({800, 600}, "Figures");

    auto font = sf::Font();
    if (!font.loadFromFile("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/sfml_tasks/test/Arial.ttf"))
        return EXIT_FAILURE;


    auto inputWrap = sf::RectangleShape(sf::Vector2f(300.f, 50.f));
    auto isActive = false;
    inputWrap.setOutlineColor(sf::Color::White);
    inputWrap.setOutlineThickness(2);
    inputWrap.setFillColor(sf::Color::Black);


    auto userInput = std::string();
    auto text = sf::Text("te", font, 30);
    text.setPosition(0, 0);
    text.setFillColor(sf::Color::White);

    while (window.isOpen()) {

        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();

            if (event.type == sf::Event::TextEntered) {
                if (isActive) {
                    int keyCode = event.text.unicode;
                    if (keyCode >= 10 && keyCode < 128) {
                        userInput += static_cast<char>(keyCode);
                        text.setString(userInput);
                    }
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (isActive) {
                    if (event.key.code == sf::Keyboard::Backspace && userInput.size() > 0) {
                        userInput.pop_back();
                        text.setString(userInput);
                    }
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {

                if (
                        event.mouseButton.x >= inputWrap.getPosition().x &&
                        event.mouseButton.x <= inputWrap.getPosition().x + inputWrap.getSize().x &&
                        event.mouseButton.y >= inputWrap.getPosition().y &&
                        event.mouseButton.y <= inputWrap.getPosition().y + inputWrap.getSize().y
                        ) {
                    isActive = true;
                    inputWrap.setOutlineColor(sf::Color::Red);
                } else {
                    if (isActive) {
                        inputWrap.setOutlineColor(sf::Color::White);
                        isActive = false;
                    }
                }
            }

        }

        window.clear();
        window.draw(inputWrap);
        window.draw(text);
        window.display();
    }

    return 0;
}
