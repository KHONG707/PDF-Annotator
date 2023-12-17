//
// Created by Kristal Hong on 11/27/23.
//

#include "MenuBar.h"
MenuBar::MenuBar() {

}


void MenuBar::addMenu(Menu menu) {


    menus.push_back(menu);
    setPosition({menus[0].getGlobalBounds().left, menus[0].getGlobalBounds().top});
}

void MenuBar::setPosition(sf::Vector2f position) {
    if(!menus.empty())
    {
        menus[0].setPosition(position);
        for (int i = 1; i < menus.size() ; ++i) {
            Position::right(menus[i-1], menus[i], 2);
        }
    }
}

void MenuBar::setMenuSize(sf::Vector2f size) {
    for (auto& menu : menus) {
        menu.setItemSize(size);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow& window, sf::Event event) {
    for (auto& menu : menus) {
        menu.addEventHandler(window, event);
    }
}

void MenuBar::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    for (const auto& menu : menus) {
        window.draw(menu, states);
    }
}


void MenuBar::update() {

}

Snapshot MenuBar::getSnapshot() {
    return Snapshot();
}

void MenuBar::applySnapshot(const Snapshot &snapshot) {

}
