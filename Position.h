//
// Created by Kristal Hong on 11/29/23.
//

#ifndef CS8_MENUBAR_POSITION_H
#define CS8_MENUBAR_POSITION_H
#include <SFML/Graphics.hpp>
#include <cmath>

class Position {

public:
    template<typename T, typename S>
    static void right(T& constObj, S& obj, float spacing = 0);

    template<typename T>
    static void centerText(const T &obj, sf::Text &text);

    template<typename T, typename S>
    static void below(T& constObj, S& obj, float spacing = 0);

};

#include "Position.cpp"
#endif //CS8_MENUBAR_POSITION_H