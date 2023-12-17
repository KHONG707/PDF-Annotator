//
// Created by Kristal Hong on 11/5/23.
//

#ifndef CS8_PROJECT1_LETTER_H
#define CS8_PROJECT1_LETTER_H

#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "States.h"

class Letter : public sf::Text
{
public:
    Letter();

    Letter(char letter);

    Letter(char letter, fontEnum font);

    void enableState(statesEnum state);

    bool checkState(statesEnum state) const;

    unsigned char getChar() const;

    sf::Color getColor() const;

    void setColor(sf::Color col);

    void updateFont(const sf::Font& font);

    void disableState(statesEnum state);

private:
    States letterStates;
    unsigned char character;
    sf::Color color;
    sf::Font font;

};
#endif //CS8_PROJECT1_LETTER_H
