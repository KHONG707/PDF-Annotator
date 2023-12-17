//
// Created by Kristal Hong on 11/16/23.
//

#include "Item.h"

Item::Item () : highlighted(false)
{
    setPosition({200, 200});

    name.setString("Notes");
    name.setFont(Fonts::getFont(OPEN_SANS));
    name.setCharacterSize(24);
    name.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.0f);
    shape.setSize({155, 70});
}


Item::Item(const std::string& itemName)
 {

    setPosition({100, 100});

    name.setString(itemName);
    name.setFont(Fonts::getFont(OPEN_SANS));
    name.setCharacterSize(24);
    name.setFillColor(sf::Color::Black);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.0f);
    shape.setFillColor(sf::Color::White);
    shape.setSize({180, 60});


}

void Item::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(shape, states);
    window.draw(name, states);
}



void Item::highlight(bool isHighlighted) {

    highlighted = isHighlighted;

    if (isHighlighted) {
        shape.setFillColor(sf::Color::Blue);
    } else {
        shape.setFillColor(sf::Color::White);
    }
}

sf::Text Item::getName() const {
    return name;
}


sf::FloatRect Item::getGlobalBounds() const {
    return shape.getGlobalBounds();
}


void Item::setPosition(sf::Vector2f position) {
    shape.setPosition(position);
    Position::centerText(shape, name);
}

float Item::getHeight() const {
    return shape.getSize().y;
}

void Item::update() {

}

void Item::setText(const std::string& itemName) {
    name.setString(itemName);
    name.setFont(Fonts::getFont(OPEN_SANS));
    name.setCharacterSize(24);
    name.setFillColor(sf::Color::Black);
    Position::centerText(shape, name);

}

const sf::Text& Item::getText() const {
    return name;
}


std::string Item::getTextString() {
    return name.getString();
}

void Item::setItemName(const std::string string) {
    name.setString(string);
    Position::centerText(shape, name);
}


void Item::setSize(sf::Vector2f size) {
    shape.setSize(size);
    Position::centerText(shape, name);
}

const sf::Vector2f Item::getPosition() const {

    return shape.getPosition();
}

const sf::RectangleShape& Item::getShape() {
    return shape;
}

sf::Vector2f Item::getSize() const {
    return shape.getSize();
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents::isHovered(shape, window))
    {
        shape.setFillColor(sf::Color::Blue);
    } else {
        shape.setFillColor(sf::Color::White);
    }

}



void Item::setCallback(std::function<void(std::string)> cb) {
    callback = std::move(cb);
}
