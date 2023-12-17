//
// Created by Kristal Hong on 11/16/23.
//

#include "ColorCoder.h"

void ColorCoder::color(MultiText::iterator begin, MultiText::iterator end, sf::Color color) {
    for (auto it = begin; it != end; ++it) {
        it->setColor(color);
    }
}


sf::Color ColorCoder::getColor(const std::string& string) {
    return sf::Color::Blue;
}

sf::Color ColorCoder::getColor(const char& letter) {
    if (isOperator(letter)) {
        return sf::Color::Green;
    }
    if (isNumber(letter)) {
        return sf::Color::Red;
    }
    return sf::Color::Black;
}


void ColorCoder::color(MultiText::iterator& begin, MultiText::iterator& end) {
    std::string highlightString = MultiText::getWord(begin, end);
//    std::cout << "highlightString: "  << highlightString << "."  <<std::endl;
    if (isWord (highlightString)){
//        std::cout << highlightString << std::endl;
        sf::Color theColor = getColor(highlightString);
        color(begin, end, theColor);

    }

}












void ColorCoder::color(MultiText &multiText) {
    auto start = multiText.begin();
    auto end = multiText.begin();

    while (start != multiText.end()) {

        while (end != multiText.end() && end->getString()[0] != ' ') {
            ++end;
        }

        color(start, end);

        start = end;

        // Skip any spaces
        while (start != multiText.end() && start->getString()[0] == ' ') {
            ++start;
        }

//        // Move 'end' to 'start' for the next iteration
        end = start;
    }
}





bool ColorCoder::isWord(const std::string& string) {
    return string == "int" || string == "double" || string == "float" || string == "char";
}


bool ColorCoder::isNumber(const Letter& letter) {
    return isdigit(letter.getChar());
}

bool ColorCoder::isOperator(const Letter& letter) {
    return letter.getChar() == '+' || letter.getChar() == '-' || letter.getChar() == '*' || letter.getChar() == '/';
}