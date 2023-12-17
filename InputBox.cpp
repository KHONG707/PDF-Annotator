//
// Created by Kristal Hong on 11/16/23.
//

#include "InputBox.h"

InputBox::InputBox()
        : selectedItem(nullptr) {
    // Initialize other properties of the input box as needed
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2.0f);
    shape.setFillColor(sf::Color::Transparent);
    shape.setSize({100, 50});
    buttonText.setFont(Fonts::getFont(OPEN_SANS));
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::Black);
}

void InputBox::setSelectedItem(Item* item) {

    if (item != nullptr) {
        selectedItem = item;
        const sf::Text& itemText = selectedItem->getText();
        setText(itemText.getString());
    }
}

void InputBox::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(shape, states);
    window.draw(buttonText, states);

}

sf::FloatRect InputBox::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

Item *InputBox::getSelectedItem() {
    return selectedItem;
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents::isClicked(shape, window)) {
//        std::cout << "Being clicked";
        isClicked = true;
    } else {
        isClicked = false;
    }
}

void InputBox::setText(const std::string& text) {
    buttonText.setString(text);

    sf::FloatRect textBounds = buttonText.getLocalBounds();
    buttonText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    Position::centerText(shape, buttonText);
}


std::string InputBox::getText() const {
    return buttonText.getString();
}

void InputBox::setSize(sf::Vector2f position) {
    shape.setSize(position);

    Position::centerText(shape, buttonText);

}

void InputBox::setPosition(sf::Vector2f position) {
    shape.setPosition({position.x, position.y});
    Position::centerText(shape, buttonText);
}

sf::Vector2f InputBox::getPosition() const {
    return shape.getPosition();
}

sf::Vector2f InputBox::getSize() const {
    return shape.getSize();
}