//
// Created by Kristal Hong on 11/1/23.
//

#ifndef CS8_PROJECT1_MULTITEXT_H
#define CS8_PROJECT1_MULTITEXT_H

#include "Letter.h"
//#include "DropdownMenu.h"
#include "States.h"
#include <list>

class MultiText : public sf::Drawable
{
private:
    std::list<Letter> text;
    Letter lastLetter;
    char prevLetterUnicode;
    char currLetterUnicode;
    sf::Glyph prevLetterGlyph;
    sf::Text cursor;


    sf::Clock cursorBlinkTimer;

    bool cursorVisible = false;
    float cursorBlinkInterval;


    bool isLineBreak(char character);

    States cursorState;

    float lineHeight = 0; // Height of each line
    int numNewLine = 0;
    sf::Vector2f initialPosition;
//    sf::Font selectedFont;

public:
    typedef std::list<Letter>::iterator iterator;
//    typedef std::list<Letter>::iterator const_iterator;
//    using iterator = std::list<Letter>::iterator;
//    using const_iterator = std::list<Letter>::const_iterator;
    //typedef is an alias - lets make this: "iterator" mean "std::list<Letter>::iterator"; changes data type

    MultiText();

    MultiText(Fonts &fonts, const sf::Vector2f &position);
    static std::string getWord(MultiText::iterator begin, MultiText::iterator end);

//    void push(char letter, sf::Color color);
    void push(char letter);
    void push(Letter letter);

    iterator begin();
    iterator end();
//    const_iterator begin() const;
//    const_iterator end() const;
//    MultiText::iterator begin(); - could do this but we used typedef so we could do the following above
//    std::list<Letter>::iterator begin(); - unsexy way of doing the function above

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;


    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition() const;


    std::string getString();
    void setString(const std::string& newText);
    bool empty();
    void pop();

    std::string getLastNCharacters(std::size_t n) const;
    Letter& getLastCharacter();
    float getTextWidth(const sf::Font& font, unsigned int characterSize, const std::string& text);

    void updateCursorBlink();
//    sf::Text& setCursorString();

    void setCursorStatus();

    void setCursorPosition(sf::Vector2f position);


    bool isNumber(char c);
    void setLastCharacterColor(sf::Color color);

    void enableState(statesEnum state);
    bool checkState(statesEnum state) const;
    void disableState(statesEnum state);


    Letter& back();

    void addLineBreak();
    void minusLineBreak();


    void setFont(const sf::Font& font);
    void updateFont(fontEnum font);

//    sf::Color& colorText();
};

#endif //CS8_PROJECT1_MULTITEXT_H
