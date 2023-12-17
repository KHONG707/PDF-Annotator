//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_ITEM_H
#define CS8_DROPDOWNMENU_ITEM_H
#include <SFML/Graphics.hpp>
#include "MouseEvents.h"
#include "Fonts.h"
#include "Position.h"
#include <string>
#include <iostream>
#include "States.h"

class Item : public sf::Drawable, public States
{
public:
    std::function<void(std::string)> callback;

    Item();
    Item(const std::string& itemName);

    // Define drawing and highlighting functions
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void highlight(bool isHighlighted);

    sf::Text getName() const;
    sf::Vector2f getSize() const;

    // Add function to get global bounds
    sf::FloatRect getGlobalBounds() const;


    void setPosition(sf::Vector2f position);

    float getHeight() const;

    void setCallback(std::function<void(std::string)> cb);


    void setText(const std::string& itemName);
    const sf::Text& getText() const;
    std::string getTextString();
    void setItemName(const std::string string);

    void setSize(sf::Vector2f size);
    const sf::Vector2f getPosition()const;

    const sf::RectangleShape& getShape();

    void setDoubleClicked();

    bool isDoubleClicked() const;

private:
    sf::Text name;
    sf::RectangleShape shape;
    bool highlighted;

    sf::Color originalFillColor;

    int counterClick = 0;
};


#endif //CS8_DROPDOWNMENU_ITEM_H
