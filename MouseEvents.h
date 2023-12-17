//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_MOUSEEVENTS_H
#define CS8_DROPDOWNMENU_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>

class MouseEvents {
public:
    template<typename T>
    inline static bool isHovered(T& object, sf::RenderWindow& window);

    template<typename T>
    inline static bool isdraggedOver(T& object, sf::RenderWindow& window, sf::Event event);

    template<typename T>
    inline static bool isClicked(T& object, sf::RenderWindow& window);

    template<typename T>
    inline static bool mouseDoubleClicked();

    template<typename T>
    inline static bool mouseTripleClicked();


    inline static bool mouseClicked(sf::RenderWindow& window, sf::Event event);

private:
    // Static members for tracking double and triple clicks
    static sf::Clock clock;
    static int clicks;

    template<typename T>
    inline static void countClicks(sf::Event event);

};


#include "MouseEvents.cpp"


#endif //CS8_DROPDOWNMENU_MOUSEEVENTS_H
