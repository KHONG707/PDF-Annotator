//
// Created by Kristal Hong on 12/11/23.
//

#ifndef CS8_FINAL_PROJECT_APPHANDLER_H
#define CS8_FINAL_PROJECT_APPHANDLER_H


#include <SFML/Graphics/Sprite.hpp>

class AppHandler {
private:
    static sf::Sprite createdSprite;
    static bool hasSprite;
public:
    static void setSprite(sf::Sprite &sprite);
    static sf::Sprite &getSprite();

    static bool isHasSprite();

};


#endif //CS8_FINAL_PROJECT_APPHANDLER_H
