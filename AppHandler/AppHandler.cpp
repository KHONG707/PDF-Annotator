//
// Created by Kristal Hong on 12/11/23.
//

#include "AppHandler.h"
sf::Sprite AppHandler::createdSprite;
bool AppHandler::hasSprite = false;
void AppHandler::setSprite(sf::Sprite &sprite) {
    createdSprite = sprite;
    hasSprite = true;
}

sf::Sprite &AppHandler::getSprite() {
    return createdSprite;
}

bool AppHandler::isHasSprite() {
    return hasSprite;
}
