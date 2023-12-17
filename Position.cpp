//
// Created by Kristal Hong on 11/29/23.
//
#ifndef CS8_MENUBAR_POSITION_CPP
#define CS8_MENUBAR_POSITION_CPP
#include "Position.h"

template<typename T, typename S>
void Position::right(T &constObj, S &obj, float spacing) {
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect  ob = obj.getGlobalBounds();

    obj.setPosition({cb.left + cb.width, cb.top + spacing});
}

template<typename T>
void Position::centerText(const T &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});

}


template<typename T, typename S>
void Position::below(T &constObj, S &obj, float spacing) {
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect  ob = obj.getGlobalBounds();

    obj.setPosition({cb.left + spacing, cb.top + cb.height});
}

#endif