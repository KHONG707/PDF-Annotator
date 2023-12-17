//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_FINAL_PROJECT_ITEMLIST_H
#define CS8_FINAL_PROJECT_ITEMLIST_H
#include "Item.h"
#include "States.h"
#include "Position.h"

class ItemList : public sf::Drawable
{
public:
    ItemList();

    // Methods to add and draw items
//    void addItem(const std::string& name);
    void addItem(Item* item);
    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    Item* getItemUnderMouse(sf::RenderWindow& window);
    void highlightItem(Item *item, bool isHighlighted);

    sf::FloatRect getGlobalBounds() const;

    void setPosition(sf::Vector2f position);
    sf::Vector2f getPosition();

    int getSize();

    void setSize(sf::Vector2f position);

    const std::vector<Item*>& getItems() const;

    void toggleVisibility();
    bool checkState() const;

    std::string getOption();

private:
    std::vector<Item*> items;
    Item* hoveredItem;
    float spacing = 2;
    States listState;

    std::string selectedText;
};

#endif
