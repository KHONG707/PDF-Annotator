//
// Created by Kristal Hong on 11/1/23.
//

#ifndef CS8_PROJECT1_TEXTINPUT_H
#define CS8_PROJECT1_TEXTINPUT_H
#include "GUIComponent.h"
#include "KeyShortcuts.h"
#include "History.h"
//#include "Cursor.h"
#include "Typing.h"
#include "MouseEvents.h"
#include "Fonts.h"
//#include "SnapshotInterface.h"
//#include "MultiText.h"
//#include "States.h"

class TextInput : public GUIComponent
{
private:
    bool active = false;

//    Cursor cursor;
    sf::Text label;
    int fontSize = 16;
    sf::Color textColor;
    sf::Vector2f cursorPosition;

    States cursorStates;
    Typing typing;



    sf::RectangleShape inputBox;
//    sf::RectangleShape lastName;

public:
    TextInput();
    TextInput(Fonts &font, const sf::Vector2f &position, const sf::Vector2f &size);

//    void getLabel(std::string labelText);
    void setLabel(const sf::Text& labelText);
    void setLabelSize(int size);
    void setLabelMargin(const sf::FloatRect& margin);
    void setPosition(const sf::Vector2f& position);
    void setTextColor(const sf::Color& color);

//    void setTypingClass(Typing* typing);
//    void setTextFromTyping();


    void addEventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    void setFont(const fontEnum& font);



    void setText(const std::string& newText);


    void setCursorPosition(const sf::Vector2f& newPosition);

    Snapshot getSnapshot();
    void applySnapshot(const Snapshot& snapshot);

};


#endif //CS8_PROJECT1_TEXTINPUT_H
