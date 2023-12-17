//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DropDownMenu_MOUSEEVENTS_CPP
#define CS8_DropDownMenu_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<typename T>
bool MouseEvents::isHovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(mpos);
}

// Returns true if the mouse clicks on the object
template<typename T>
bool MouseEvents::isClicked(T &object, sf::RenderWindow &window) {
    return (isHovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
}




// Returns true if the mouse has been double clicked
template<typename T>
bool MouseEvents::mouseDoubleClicked() {
    if (clicks == 2) {
        clicks = 0;
        return true;
    }
    return false;
}


// Returns true if the mouse has been triple clicked
template<typename T>
bool MouseEvents::mouseTripleClicked() {
    if (clicks == 3) {
        clicks = 0;
        return true;
    }
    return false;
}




// Returns true if the object has been clicked and the mouse has dragged over the object
template<typename T>
bool MouseEvents::isdraggedOver(T& object, sf::RenderWindow& window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::FloatRect objectBounds = object.getGlobalBounds();
        if (objectBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
            return true;
        }
    }
    return false;
}




// Count clicks
template<typename T>
void MouseEvents::countClicks(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Time timeSinceLastClick = clock.getElapsedTime();
        if (timeSinceLastClick.asMilliseconds() <= 500) {  // Adjust this time threshold later
            clicks++;
        } else {
            clicks = 1;
        }
        clock.restart();
    }
}

bool MouseEvents::mouseClicked(sf::RenderWindow& window, sf::Event event) {
    return (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left &&
            event.mouseButton.x >= 0 && event.mouseButton.x < window.getSize().x &&
            event.mouseButton.y >= 0 && event.mouseButton.y < window.getSize().y);
}

#endif
