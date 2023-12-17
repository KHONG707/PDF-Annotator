//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_DROPDOWNMENU_H
#define CS8_DROPDOWNMENU_DROPDOWNMENU_H
#include <SFML/Graphics.hpp>
#include "GUIComponent.h"
#include "ItemList.h"
#include "InputBox.h"
#include "History.h"
#include "MultiText.h"



class DropdownMenu : public GUIComponent {
public:
    DropdownMenu();

    void addItem(const std::string& text);

    // Implement methods to position and resize the menu
    void setPosition(sf::Vector2f position);

    void setSize(sf::Vector2f position);

    // Event handling methods
    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void update();

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;


    void highlightItemUnderMouse(sf::RenderWindow& window);

    void updateListSize();


    Item* selectItem(Item* selectedItem);

    sf::Vector2f getSize();

    Snapshot getSnapshot();
    void applySnapshot(const Snapshot& snapshot);

    std::string getString();

private:
    ItemList itemList;
    InputBox inputBox;
//    MultiText multiText;

    float spacing = 2;

    std::string fontString;

    bool isMenuOpen;
    bool isResizing;
    bool isItemSelected;
    std::size_t selectedItemIndex;


};

#endif //CS8_DROPDOWNMENU_DROPDOWNMENU_H
