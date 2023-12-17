//
// Created by Kristal Hong on 11/21/23.
//

#ifndef CS8_FILETREE_FILEITEM_H
#define CS8_FILETREE_FILEITEM_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Image.h"
#include "Item.h"
#include "States.h"
#include "ItemList.h"


class FileItem : public Item
{
public:
    //Constructors
    FileItem();
    FileItem(std::string text, sf::Vector2f size, sf::Vector2f position);

    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //I use this function to highlight the item when clicked, and unhighlight when something
    //else is clicked
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);

//    //Returns the bounds of the item
//    sf::FloatRect getGlobalBounds() const;
//
//    //returns the size of the item
//    sf::Vector2f getSize() const;
//
//    //returns the size of the item
//    sf::Vector2f getPosition() const;

    //sets the position of the item
    void setPosition(sf::Vector2f position);

    //uses an enum to change the icon to a folder or file
    void setIcon(const std::string& filename);


    // Set the file path
    void setFilePath(const std::string& path);

    // Get the file path
    std::string getFilePath() const;
    void setPNGImage(const std::string& filename);

private:

    void setIconPosition();
    void resizeIcon();
    void setPNGPosition();

    //this is the folder or file icon
    sf::Sprite icon;
    sf::Sprite imagePNG;
    float padding = 5;

    sf::Texture texturePNG;
    sf::Texture texture;
    sf::RectangleShape shape;
    sf::Text labelText;


};


#endif //CS8_FILETREE_FILEITEM_H
