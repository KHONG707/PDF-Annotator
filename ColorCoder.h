//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_PROJECT1_COLORCODER_H
#define CS8_PROJECT1_COLORCODER_H
#include "MultiText.h"
#include <iostream>
#include <cctype>


class ColorCoder {

public:

    void color(MultiText::iterator begin, MultiText::iterator end, sf::Color color);

    sf::Color getColor(const std::string& string);
    sf::Color getColor(const char& letter);


    void color(MultiText& multiText);

    void color(MultiText::iterator& begin, MultiText::iterator& end);


    bool isWord(const std::string& string);
    bool isOperator(const Letter& letter);

    bool isNumber(const Letter& letter);
};


#endif //CS8_PROJECT1_COLORCODER_H
