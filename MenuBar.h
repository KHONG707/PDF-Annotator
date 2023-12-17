//
// Created by Kristal Hong on 11/27/23.
//

#ifndef CS8_MENUBAR_MENUBAR_H
#define CS8_MENUBAR_MENUBAR_H
#include "Menu.h"
#include "GUIComponent.h"
#include "Position.h"
class MenuBar : public GUIComponent
{
public:
    MenuBar();

//    void addMenu(const std::string& title);
    void addMenu(Menu menu);

    void setPosition(sf::Vector2f position);

    void setMenuSize(sf::Vector2f size);

    void addEventHandler(sf::RenderWindow& window, sf::Event event);

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    void update();

    Snapshot getSnapshot();
    void applySnapshot(const Snapshot& snapshot);

private:
    std::vector<Menu> menus;
};


#endif //CS8_MENUBAR_MENUBAR_H
