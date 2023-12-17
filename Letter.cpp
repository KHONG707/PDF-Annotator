//
// Created by Kristal Hong on 11/1/23.
//

#include "Letter.h"
Letter::Letter() : Letter('\0')
{

}

Letter::Letter (char letter) : sf::Text(), character(letter)
{
    setFont(Fonts::getFont(OPEN_SANS));
    setPosition({300.f, 300.f});
    setString(std::string(1, letter)); // (std::string(1, letter) - char to string
    setCharacterSize(24);

}

unsigned char Letter::getChar() const {
    return character;
}


void Letter::enableState(statesEnum state) {
    letterStates.enableState(state);
}

// Add a method to check the state in the letter
bool Letter::checkState(statesEnum state) const {
    return letterStates.checkState(state);
}

void Letter::disableState(statesEnum state) {
    letterStates.disableState(state);
}

sf::Color Letter::getColor() const {
    return color;
}

void Letter::setColor(sf::Color col) {
    color = col;
    setFillColor(color);
}
