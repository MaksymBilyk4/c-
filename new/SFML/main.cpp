//#include <SFML/Graphics.hpp>
//
//auto main() -> int {
//    auto window = sf::RenderWindow(
//            sf::VideoMode({800, 600}), "Hexagon", sf::Style::Default, sf::ContextSettings(0, 0, 8)
//    );
//    auto hexagon = sf::CircleShape(50, 6);
//    //Color contractor
//    hexagon.setOutlineColor(sf::Color::Red);
//    hexagon.setOutlineThickness(15);
//    //Fill color
//    hexagon.setFillColor(sf::Color::Blue);
//    hexagon.setPosition({100, 100});
//
//    while (window.isOpen()) {
//        auto event = sf::Event();
//        //event handler for window closing
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        //painting window with background color
//        window.clear(sf::Color::White);
//        //hexagon drawing
//        window.draw(hexagon);
//        //updating window display
//        window.display();
//    }
//}

//#include <SFML/Graphics.hpp>
//
//auto main() -> int{
//    auto window = sf::RenderWindow(
//            sf::VideoMode({800, 600}), "Test", sf::Style::Default, sf::ContextSettings(0, 0, 8)
//    );
//    auto hexagon = sf::CircleShape(50, 6);
//    while (window.isOpen()) {
//        auto event = sf::Event();
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//        window.clear(sf::Color::Blue);
//        for (int y = 0; y < 3; y++) {
//            for (int x = 0; x < 2; x++)
//            {
//                if(y%2 == 0) hexagon.setFillColor(sf::Color::Black);
//                else hexagon.setFillColor(sf::Color::White);
//                hexagon.setPosition({(y % 2 ? 280 : 230) + x * 100.f, 100 + y * 85.f});
//                window.draw(hexagon);
//            }
//        }
//        window.display();
//    }
//}

//#include <SFML/Graphics.hpp>
//
//auto main() -> int {
//    auto window = sf::RenderWindow(
//            sf::VideoMode({800, 600}), "Test", sf::Style::Default, sf::ContextSettings(0, 0, 8)
//    );
//    auto font = sf::Font();
//    if (!font.loadFromFile("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/new/SFML/Arial.ttf"))
//        return EXIT_FAILURE;
//    auto text = sf::Text("Hello SFML", font, 50);
//    text.setPosition({250, 250});
//    text.setFillColor(sf::Color::Black);
//
//    while (window.isOpen()) {
//        auto event = sf::Event();
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//        }
//
//        window.clear(sf::Color::White);
//        window.draw(text);
//        window.display();
//    }
//}

#include <SFML/Graphics.hpp>
#include <iostream>

auto main() -> int{
    auto window = sf::RenderWindow(
            sf::VideoMode({800, 600}), "Test", sf::Style::Default, sf::ContextSettings(0, 0, 8)
    );
    auto font = sf::Font();
    if (!font.loadFromFile("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/new/SFML/Arial.ttf")) {
        std::cout << "Failed to load font.\n";
        return 1;
    }
    auto text = sf::Text("Click to change", font, 24);
    text.setPosition({300, 250});

    auto button = sf::RectangleShape(sf::Vector2f(300, 50));
    button.setPosition({250, 300});
    button.setFillColor(sf::Color::Green);

    auto buttonText = std::string("click");
    // Convert buttonText to sf::String
    auto buttonTextText = sf::Text(sf::String(buttonText), font, 24);
    buttonTextText.setPosition({350, 310});

    while (window.isOpen()) {
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    auto mousePos = sf::Mouse::getPosition(window);
                    if (button.getGlobalBounds().contains({static_cast<float>(mousePos.x),static_cast<float>(mousePos.y)})) {
                        if (buttonText == "click")
                            buttonText = "clicked!";
                        else
                            buttonText = "click";
                        // Convert buttonText to sf::String
                        buttonTextText.setString(sf::String(buttonText));
                    }
                }
            }
        }

        window.clear();
        window.draw(text);
        window.draw(button);
        window.draw(buttonTextText);
        window.display();
    }
}