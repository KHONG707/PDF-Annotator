//
// Created by Kristal Hong on 11/16/23.
//


#include "Fonts.h"
std::map<fontEnum, sf::Font> Fonts::fonts;


void Fonts::loadFont(fontEnum font) {
    fonts[font].loadFromFile(getFontPath(font));
}

std::string Fonts::getFontPath(fontEnum font) {
    switch (font) {
        case(COMIC_SANS):
            return "Font/comic.ttf";
        case (OPEN_SANS):
            return "Font/OpenSans-Bold.ttf";
        case (WHISPER) :
            return "Font/Whisper-Regular.ttf";
        case (LOBSTER) :
            return "Font/Lobster-Regular.ttf";
    }
//    std::string f[] = {"Font/OpenSans-Bold.ttf"};
//    return f[font];
}

sf::Font &Fonts::getFont(fontEnum font) {
    loadFont(font);
    return fonts[font];
}

//// Helper function to convert a font name string to FontEnum
//fontEnum Fonts::getFontEnumFromString(const std::string& fontName) {
//    if (fontName == "OpenSans") {
//        return OPEN_SANS;
//    } else if (fontName == "Arial") {
//        return ARIAL;
//    } else if (fontName == "ComicSans") {
//        return COMIC_SANS;
//    } else {
//        // Handle the case when the font name is not recognized
//        std::cerr << "Unknown font name: " << fontName << std::endl;
//        return OPEN_SANS; // Or return a default font enum value
//    }
//}