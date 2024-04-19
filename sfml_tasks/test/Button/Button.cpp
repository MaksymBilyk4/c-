#include "Button.hpp"

/////////////////////////////////////////////////////
// CONSTRUCTORS

Button::Button(sf::Vector2f size) : buttonBase(size) {
    buttonBase.setPosition(0, 0);
    initFont();
}

Button::Button(sf::Vector2f size, sf::Vector2f position) : buttonBase(size) {
    buttonBase.setPosition(position);
    initFont();
}

Button::Button(sf::Vector2f size, sf::Color fillColor) : buttonBase(size) {
    buttonBase.setFillColor(fillColor);
    initFont();
}

/////////////////////////////////////////////////////
// GETTERS
auto Button::getX() -> float {
    return buttonBase.getPosition().x;
}

auto Button::getY() -> float {

    return buttonBase.getPosition().y;
}

auto Button::getPosition() -> sf::Vector2f {
    return buttonBase.getPosition();
}

auto Button::getWidth() -> float {
    return buttonBase.getSize().x;
}

auto Button::getHeight() -> float {
    return buttonBase.getSize().y;
}

auto Button::getSize() -> sf::Vector2f {
    return buttonBase.getSize();
}

auto Button::getFillColor() -> sf::Color {
    return buttonBase.getOutlineColor();
}

auto Button::getBorderColor() -> sf::Color {
    return buttonBase.getOutlineColor();
}

auto Button::getBorderWidth() -> float {
    return buttonBase.getOutlineThickness();
}

/////////////////////////////////////////////////////
// SETTERS

auto Button::setX(float x) -> void {
    buttonBase.setPosition(x, getY());
}

auto Button::setY(float y) -> void {
    buttonBase.setPosition(getX(), y);
}

auto Button::setPosition(sf::Vector2f position) -> void {
    buttonBase.setPosition(position);
}

auto Button::setWidth(float width) -> void {
    buttonBase.setSize(sf::Vector2f(width, getHeight()));
}

auto Button::setHeight(float height) -> void {
    buttonBase.setSize(sf::Vector2f(getWidth(), height));
}

auto Button::setSize(sf::Vector2f size) -> void {
    buttonBase.setSize(size);
}

auto Button::setFillColor(sf::Color color) -> void {
    buttonBase.setFillColor(color);
}

auto Button::setBorderColor(sf::Color color) -> void {
    buttonBase.setOutlineColor(color);
}

auto Button::setBorderWidth(float width) -> void {
    buttonBase.setOutlineThickness(width);
}

/////////////////////////////////////////////////////
// Additional

auto Button::initFont() -> void {
    buttonFont.loadFromFile("/Users/maksymbilyk/Desktop/programming/PJAIT/C++/sfml_tasks/test/Arial.ttf");
}