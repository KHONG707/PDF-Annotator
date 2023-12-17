//
// Created by Kristal Hong on 11/21/23.
//

#include "FileItem.h"
#include "AppHandler/AppHandler.h"


FileItem::FileItem() : Item() {
    //
}

FileItem::FileItem(std::string text, sf::Vector2f size, sf::Vector2f position) : shape(size), labelText(text, sf::Font(), 12) {
     shape.setPosition(position);
    shape.setFillColor(sf::Color::White);
     labelText.setPosition(position.x + 5, position.y + 5);

}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {

    Item::draw(window, states);
    window.draw(icon);


}

void FileItem::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    Item::addEventHandler(window, event);
}

void FileItem::setPosition(sf::Vector2f position) {

    Item::setPosition(position);

    setIconPosition();
}

void FileItem::setIcon(const std::string& filename) {
    this->texture.loadFromFile(filename);
    icon.setTexture(texture);
    resizeIcon();
}

void FileItem::setPNGImage(const std::string& filename) {
    this->texturePNG.loadFromFile(filename);
    imagePNG.setTexture(texturePNG);

    //change the position of the image
    imagePNG.setPosition({210, 130});
    //change the scale of the image.
    imagePNG.setScale({1.6, 1.6});
    AppHandler::setSprite(imagePNG);
}




////private
void FileItem::setPNGPosition() {

    sf::Vector2f PNGPosition;

    PNGPosition = {100, 100};
    this->imagePNG.setPosition(PNGPosition);
}



void FileItem::setIconPosition() {
    sf::Vector2f borderPosition = getPosition();
    sf::Vector2f iconPosition;

    iconPosition = {borderPosition.x - padding - icon.getGlobalBounds().width, borderPosition.y + 2 * padding};

    this->icon.setPosition(iconPosition);
}


void FileItem::resizeIcon() {
    float borderHeight = getSize().y - 5 * padding;
    float iconHeight = icon.getGlobalBounds().height;
    float resizeFactor = borderHeight / iconHeight;

    icon.setScale({resizeFactor, resizeFactor});
}

