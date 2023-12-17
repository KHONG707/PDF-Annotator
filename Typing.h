//
// Created by Kristal Hong on 11/1/23.
//

#ifndef CS8_PROJECT1_TYPING_H
#define CS8_PROJECT1_TYPING_H
#include <SFML/Graphics.hpp>
#include "MultiText.h"
//#include "Cursor.h"
//#include "MouseEvents.h"
#include "Fonts.h"
#include "ColorCoder.h"
#include "FontCoder.h"
#include "DropdownMenu.h"

class Typing : public sf::Drawable {
public:
    Typing();
    Typing(Fonts &font, const sf::Vector2f &position);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    MultiText& getMultiText();

    void setFont(const fontEnum &font);
private:
    bool isWord(const std::string& word);
    bool isOperator(char c);
    bool isNumber(char c);
    ColorCoder colorCoder;

    MultiText multiText;

    bool isTyping;

    sf::Vector2f position;
    DropdownMenu dropdownOption;
};


#endif //CS8_PROJECT1_TYPING_H
