//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_EVENTHANDLER_H
#define CS8_DROPDOWNMENU_EVENTHANDLER_H

#include <SFML/Graphics.hpp>

class EventHandler : public sf::Drawable
{
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //CS8_DROPDOWNMENU_EVENTHANDLER_H
