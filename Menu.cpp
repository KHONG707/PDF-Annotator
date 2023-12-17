//
// Created by Kristal Hong on 11/27/23.
//

#include "Menu.h"
Menu::Menu() {
    //
}

Menu::Menu(const std::string& title) {
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineColor(sf::Color::Black);
    box.setOutlineThickness(2.0f);

    setText(title);

}

void Menu::addItem(const std::string& text, std::function<void(std::string)> cb) {
    Item *item = new Item();
    item->setText(text);
    item->setCallback(std::move(cb));

    itemList.addItem(item);
}


void Menu::setPosition(sf::Vector2f position) {

    box.setPosition({position.x, position.y});

    Position::below(box, itemList, spacing);
    Position::centerText(box, titleText);
}

void Menu::setItemSize(sf::Vector2f size) {
    box.setSize(size);

    updateListSize();
}

void Menu::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    if (MouseEvents::isClicked(box, window) || (MouseEvents::mouseClicked(window, event) && !itemList.checkState()) || (MouseEvents::isClicked(itemList, window) && !itemList.checkState())) {
        itemList.toggleVisibility();
    }

    itemList.addEventHandler(window, event);

}



void Menu::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(titleText, states);
    window.draw(itemList, states);
}


void Menu::updateListSize() {

    sf::Vector2f boxHeight = box.getSize();

    itemList.setSize({(boxHeight.x), boxHeight.y});

}

const float Menu::getItemSize() const {
    auto size = box.getGlobalBounds().width;
    return size;
}


void Menu::setText(const std::string& menuName) {


    titleText.setString(menuName);
    titleText.setFont(Fonts::getFont(OPEN_SANS));
    titleText.setCharacterSize(24);
    titleText.setFillColor(sf::Color::Black);
    Position::centerText(box, titleText);

}

sf::FloatRect Menu::getGlobalBounds() const {
    return box.getGlobalBounds();
}


std::string Menu::getOptionString() {
    return itemList.getOption();

}

void Menu::update() {
}
