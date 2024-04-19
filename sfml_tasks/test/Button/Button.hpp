#pragma once

#include <SFML/Graphics.hpp>

struct Button {

    auto getX() -> float;

    auto getY() -> float;

    auto getPosition() -> sf::Vector2f;

    auto getWidth() -> float;

    auto getHeight() -> float;

    auto getSize() -> sf::Vector2f;

    auto getFillColor() -> sf::Color;

    auto getBorderColor() -> sf::Color;

    auto getBorderWidth() -> float;

    auto setX(float x) -> void;

    auto setY(float y) -> void;

    auto setPosition(sf::Vector2f position) -> void;

    auto setWidth(float width) -> void;

    auto setHeight(float height) -> void;

    auto setSize(sf::Vector2f size) -> void;

    auto setFillColor(sf::Color color) -> void;

    auto setBorderColor(sf::Color color) -> void;

    auto setBorderWidth(float width) -> void;

    Button(sf::Vector2f size, sf::Vector2f position);
    Button(sf::Vector2f size, sf::Color fillColor);
    Button(sf::Vector2f size);

private:
    sf::RectangleShape buttonBase;
    sf::Font buttonFont;
    sf::Text buttonText;

    auto initFont() -> void;

};