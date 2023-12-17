//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_INPUTBOX_H
#define CS8_DROPDOWNMENU_INPUTBOX_H
#include "Item.h"
#include "Fonts.h"
#include "MouseEvents.h"


class InputBox : public sf::Drawable
{
public:
    InputBox();

    void setSelectedItem(Item* item);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds() const;

    void setText(const std::string& text);


    std::string getText() const;

    void setPosition(sf::Vector2f position);

    void setSize(sf::Vector2f position);

    Item* getSelectedItem();

    sf::Vector2f getPosition() const;

    sf::Vector2f getSize() const;

private:
    Item* selectedItem;
    sf::RectangleShape shape;
    bool isClicked = false;
    sf::Text buttonText;


};


#endif //CS8_DROPDOWNMENU_INPUTBOX_H
