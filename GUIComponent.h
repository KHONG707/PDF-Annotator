//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_GUICOMPONENT_H
#define CS8_DROPDOWNMENU_GUICOMPONENT_H

#include <SFML/Graphics.hpp>
#include "SnapshotInterface.h"
#include "States.h"
#include "EventHandler.h"

class GUIComponent : public EventHandler, public States, public SnapshotInterface, public sf::Transformable
{
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

    // from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

    //from SnapshotInterface
//    virtual Snapshot& getSnapshot() = 0;
//    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //CS8_DROPDOWNMENU_GUICOMPONENT_H
