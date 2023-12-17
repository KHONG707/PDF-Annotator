//
// Created by Kristal Hong on 11/27/23.
//

#ifndef CS8_FINAL_PROJECT_MENU_H
#define CS8_FINAL_PROJECT_MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Item.h"
#include "ItemList.h"
#include "Fonts.h"
#include "MouseEvents.h"
#include <functional>

class Menu : public sf::Drawable {
public:
    Menu();
    Menu(const std::string& title);

    void addItem(const std::string& text, std::function<void(std::string)> cb);
    void setPosition(sf::Vector2f position);
    void setItemSize(sf::Vector2f size);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();

    const float getItemSize() const;
    void updateListSize();
    void setText(const std::string& menuName);
    sf::FloatRect getGlobalBounds() const;

    std::string getOptionString();

private:
    sf::RectangleShape box;
    sf::Text titleText;
    ItemList itemList;
    float spacing = 2;
    bool isItemSelected;
//    std::string getOption;

    std::string optionString;
};

#endif //CS8_FINAL_PROJECT_MENU_H
