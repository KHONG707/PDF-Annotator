//
// Created by Kristal Hong on 11/1/23.
//

#include "Typing.h"

Typing::Typing()
{
    //
}





Typing::Typing(Fonts &font, const sf::Vector2f &position)
        : multiText(font, position) {
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    char inputChar = static_cast<char>(event.text.unicode);
    std::string inputAsString = std::to_string(event.text.unicode);
    if (event.type == sf::Event::TextEntered) {
        if (inputChar >= 32) {
            sf::Color charColor;
            if (colorCoder.isOperator(inputChar)) {
                charColor = sf::Color::Green;
            } else if (colorCoder.isNumber(inputChar)) {
                charColor = sf::Color::Red;
            } else {
                charColor = sf::Color::Black; // Default color
            }


            multiText.push(inputChar);
            multiText.back().setFillColor(charColor);

            colorCoder.color(multiText);

            isTyping = true;
        }

        if (inputChar == 10) {
            multiText.push(inputChar);

        }

        if (inputChar == 8) {
            multiText.pop();

        }
    }

}


void Typing::update() {
    multiText.updateCursorBlink();


    if (multiText.empty()) {
        multiText.setCursorPosition({60, 535});
    }

}


void Typing::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(multiText, states);

}


bool Typing::isOperator(char c) {
//    std::cout << colorCoder.isOperator(c);
    return colorCoder.isOperator(c);
}

bool Typing::isNumber(char c) {
//    std::cout << colorCoder.isNumber(c);
    return colorCoder.isNumber(c);
}


MultiText &Typing::getMultiText() {
    return multiText;
}



void Typing::setFont(const fontEnum &font) {
    multiText.updateFont(font);
}
