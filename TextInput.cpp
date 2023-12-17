//
// Created by Kristal Hong on 11/1/23.
//

#include "TextInput.h"

TextInput::TextInput()
{




    label.setFont(Fonts::getFont(OPEN_SANS));
    label.setString("Comments:");
    label.setCharacterSize(22);
    label.setFillColor(sf::Color::Black);
    label.setPosition({40, 485});



    inputBox.setSize({650, 190});
    inputBox.setPosition({30, 520});
    inputBox.setFillColor(sf::Color::Transparent);

    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2.0f);

    enableState(HIDDEN);

}


void TextInput::setLabel(const sf::Text &labelText) {

    label = labelText;

}

void TextInput::setLabelSize(int size) {
    fontSize = size;
}

void TextInput::setLabelMargin(const sf::FloatRect &margin) {
//    text.setPosition({margin.left, margin.top});
}

void TextInput::setPosition(const sf::Vector2f &position) {
}

void TextInput::setTextColor(const sf::Color& color) {
    textColor = color;
}





void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isClicked(inputBox, window)) {
        active = true;
        typing.getMultiText().disableState(HIDDEN);
        typing.getMultiText().setCursorStatus();


    } else if(MouseEvents::mouseClicked(window, event)) {
        active = false;
        typing.getMultiText().enableState(HIDDEN);
    }

    if (active) {
        if (sf::Event::TextEntered == event.type){
            HistoryNode hn;

            hn.snapshot = getSnapshot();
            hn.component = this;
            History::pushHistory(hn);
        }

        typing.addEventHandler(window, event);


    }



}

void TextInput::update() {
    if (!active) {
        typing.getMultiText().setCursorStatus();
    } else {
        typing.update();
    }
}

void TextInput::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (!checkState(HIDDEN)) {
        target.draw(label, states);

        target.draw(typing, states);
        target.draw(inputBox, states);
    }


}



TextInput::TextInput(Fonts &font, const sf::Vector2f &position, const sf::Vector2f &size)
        : inputBox(size), typing(font, position) {
    inputBox.setPosition(position);
    inputBox.setFillColor(sf::Color::Black);
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(1.0f);

}
















Snapshot TextInput::getSnapshot() {
    Snapshot snapshot (typing.getMultiText().getString());
    return snapshot;

}



void TextInput::applySnapshot(const Snapshot& snapshot) {
    typing.getMultiText().setString(snapshot.getText());
}

void TextInput::setFont(const fontEnum &font) {
    typing.setFont(font);
}

