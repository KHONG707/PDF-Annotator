//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_FONTS_H
#define CS8_DROPDOWNMENU_FONTS_H

#include <SFML/Graphics.hpp>
#include <map>
#include "FontEnum.h"
#include <iostream>
#include <string>

class Fonts {
private:
    static std::map<fontEnum, sf::Font> fonts; //so you can use this one font rather making multiple
    static void loadFont(fontEnum font);
    static std::string getFontPath(fontEnum font);


public:
    static sf::Font& getFont(fontEnum font);
    static fontEnum getFontEnumFromString(const std::string& fontName);
};


#endif //CS8_DROPDOWNMENU_FONTS_H
