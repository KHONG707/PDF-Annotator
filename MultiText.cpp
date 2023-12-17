//
// Created by Kristal Hong on 11/1/23.
//

#include "MultiText.h"


MultiText::MultiText()
{
// Initialize the cursor
    cursor.setFont(Fonts::getFont(OPEN_SANS));
    cursor.setString("|");
    cursor.setFillColor(sf::Color::Black);
    setCursorPosition({60, 535});
    initialPosition = {60, 535};



    cursorBlinkTimer.restart();
    cursorVisible = false;
    cursorBlinkInterval = 0.5f;
    //
}

MultiText::MultiText(Fonts &fonts, const sf::Vector2f &position) {
    //
    cursorBlinkTimer.restart();
    cursorVisible = false;
    cursorBlinkInterval = 0.5f;
}


float MultiText::getTextWidth(const sf::Font& font, unsigned int characterSize, const std::string& text) {
    float totalWidth = 0.0f;
    for (char character : text) {
        sf::Glyph glyph = font.getGlyph(character, characterSize, 0); // Use style 0 for plain style
        totalWidth += static_cast<float>(glyph.advance);
    }
    return totalWidth;
}


bool MultiText::isNumber(char c) {
    return (c >= '0' && c <= '9');
}


void MultiText::push(char letter) {
    sf::Color charColor;
    Letter newLetter(letter);


    if(text.empty()){
        currLetterUnicode = letter;
        newLetter.setPosition(60, 535);
    }
    else {

        prevLetterUnicode = currLetterUnicode;
        currLetterUnicode = letter;
        lastLetter = text.back();
        prevLetterGlyph = text.back().getFont()->getGlyph(prevLetterUnicode, 24, "bold") ;
        if (currLetterUnicode == '\n') {

            numNewLine++;
            lineHeight = numNewLine * 30.f;
            lastLetter.setPosition(initialPosition.x - (2 * prevLetterGlyph.advance), initialPosition.y + lineHeight);

            addLineBreak();

        }



        sf::Vector2f prevPosition = lastLetter.getPosition();
        newLetter.setPosition(prevPosition.x+prevLetterGlyph.advance, prevPosition.y);




    }



    text.push_back(newLetter);


    if (!text.empty()) {
        sf::Vector2f cursorPosition = back().getPosition();
        cursor.setPosition(cursorPosition.x + back().getGlobalBounds().width, cursorPosition.y);
    }
    // Restart the cursor blink timer when a character is added
    cursorBlinkTimer.restart();
    cursorVisible = true;

}

Letter &MultiText::back() {
    return text.back();
}


void MultiText::push(Letter letter) {


    if(text.empty()){
//        currLetterUnicode = letter;
        letter.setPosition(60, 535);
    }
    else {
        prevLetterUnicode = currLetterUnicode;
//        currLetterUnicode = letter;
        lastLetter = text.back();


        prevLetterGlyph = Fonts::getFont(OPEN_SANS).getGlyph(prevLetterUnicode, 24, "bold");
        sf::Vector2f prevPosition = lastLetter.getPosition();
        letter.setPosition(prevPosition.x+prevLetterGlyph.advance, 535);


    }



    text.push_back(letter);

    if (!text.empty()) {
        sf::Vector2f cursorPosition = text.back().getPosition();
        cursor.setPosition(cursorPosition.x + text.back().getGlobalBounds().width, cursorPosition.y);
    }
    // Restart the cursor blink timer when a character is added
    cursorBlinkTimer.restart();
    cursorVisible = true;

}


MultiText::iterator MultiText::begin() {
    return text.begin();
}

MultiText::iterator MultiText::end() {
    return text.end();
}


void MultiText::draw(sf::RenderTarget& window, sf::RenderStates states) const  {
    for (const Letter& letter : text) {
        window.draw(letter, states);
    }

    // Draw the cursor only if it's currently visible
    if (cursorVisible) {
        window.draw(cursor, states);
    }
}


bool MultiText::empty() {
    return text.empty();
}


void MultiText::pop() {
    if (!text.empty()) {

//
        lastLetter = text.back();

        if (!text.empty()) {

            sf::Vector2f cursorPosition = lastLetter.getPosition();
            text.pop_back();
            cursor.setPosition(cursorPosition.x - (0.5 * text.back().getGlobalBounds().width), cursorPosition.y);

            if(lastLetter.getChar() == '\n') {
                numNewLine--;
            }

        } else {

            cursor.setPosition(60, 535); // Adjust the position as needed
        }

    }

}

void MultiText::setPosition(const sf::Vector2f& position) {

    float xOffset = position.x;
    for (Letter& letter : text) {
        letter.setPosition({xOffset, position.y});
        xOffset += letter.getGlobalBounds().width;
    }
}

sf::Vector2f MultiText::getPosition() const {
    if (!text.empty()) {
        return text.front().getPosition();
    }
    return sf::Vector2f(0.f, 0.f);
}


void MultiText::addLineBreak() {
    int height = 30.0f;
    sf::Vector2f cursorPosition = cursor.getPosition();
    cursorPosition.x = initialPosition.x;
    cursorPosition.y += height;
    cursor.setPosition(cursorPosition);

}

void MultiText::minusLineBreak() {
    int height = 30.0f;
    sf::Vector2f cursorPosition = cursor.getPosition();
    cursorPosition.x = lastLetter.getPosition().x;
    cursorPosition.y -= height;
    cursor.setPosition(cursorPosition);

}

std::string MultiText::getString() {
    std::string newText;
    for (Letter& letter : text) {
        newText += letter.getString();
    }
    return newText;
}

void MultiText::setString(const std::string& newText) {
    // Clear the existing text
    text.clear();

    for (char c: newText) {
        push(c);
    }


}





void MultiText::updateCursorBlink() {
    if (cursorBlinkTimer.getElapsedTime().asSeconds() >= cursorBlinkInterval) {
        cursorVisible = !cursorVisible;
        cursorBlinkTimer.restart();
    }
}

void MultiText::setCursorPosition(sf::Vector2f position) {
    cursor.setPosition(position);
}

void MultiText::setLastCharacterColor(sf::Color color) {
    if (!text.empty()) {
        text.back().setColor(color);
    }
}

void MultiText::enableState(statesEnum state) {
    cursorState.enableState(state);
}

void MultiText::disableState(statesEnum state) {
    cursorState.disableState(state);
}

bool MultiText::checkState(statesEnum state) const {
    return cursorState.checkState(state);
}



void MultiText::setCursorStatus() {
    if (cursorState.checkState(HIDDEN)) {
        cursorVisible = !cursorVisible;
        setCursorPosition({-100, -100});
    } else {
        sf::Vector2f rePosition = text.back().getPosition();
        setCursorPosition({rePosition.x + text.back().getGlobalBounds().width, rePosition.y});
    }

}


std::string MultiText::getWord(MultiText::iterator begin, MultiText::iterator end) {
    std::string word;
//    std::cout << "Accessing function";

    for (auto it = begin; it != end; ++it) {
        word += it->getChar();
//        std::cout << "Character:" << word << std::endl;
    }
    return word;
}

bool MultiText::isLineBreak(char character) {
    return character == '\n';
}


std::string MultiText::getLastNCharacters(std::size_t n) const {
    std::string result;
    auto it = text.end();
    for (std::size_t i = 0; i < n && it != text.begin(); ++i) {
        --it;
    }

    for (; it != text.end(); ++it) {
        result += it->getChar();
    }

    return result;
}



void MultiText::updateFont(fontEnum font) {
    for(auto x = text.begin(); x != text.end(); ++x){
        x->setFont(Fonts::getFont(font));
    }
}



Letter& MultiText::getLastCharacter() {
    return lastLetter;
}
