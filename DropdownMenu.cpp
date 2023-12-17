//
// Created by Kristal Hong on 11/16/23.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu()
        : isMenuOpen(false), isItemSelected(false) {

    inputBox.setSize({150, 80});
}


void DropdownMenu::addItem(const std::string &text) {
    Item *item = new Item();
    item->setText(text);
    item->setSize(getSize());

    if (itemList.getSize() == 0) { //check if itemList is empty or not
        inputBox.setText(text);
    }

    itemList.addItem(item);
    updateListSize();
//    std::cout << "Adding item\n";

}


void DropdownMenu::setPosition(sf::Vector2f position) {
    inputBox.setPosition({position.x, position.y});
    Position::below(inputBox, itemList, spacing);
}


void DropdownMenu::setSize(sf::Vector2f position) {
    inputBox.setSize(position);

    updateListSize();
}



void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if (MouseEvents::isClicked(inputBox, window)) {
        itemList.toggleVisibility();

    } else if (MouseEvents::mouseClicked(window, event) && !itemList.checkState()) {

        itemList.toggleVisibility();
    }
    itemList.addEventHandler(window,event);
        if (MouseEvents::isClicked(itemList, window)) {
            Item *selectedItem = itemList.getItemUnderMouse(window);
            selectItem(selectedItem);
            if (selectedItem != nullptr) {
                inputBox.setSelectedItem(selectedItem);
                isItemSelected = true;
                fontString = selectedItem->getTextString();

            } else {
                isItemSelected = false;
            }

        }

}


void DropdownMenu::update() {
    if (!itemList.checkState()) {
        itemList.update();
    }

}

void DropdownMenu::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    if (!itemList.checkState()) {
        window.draw(itemList, states);
    }
    window.draw(inputBox, states);
}

void DropdownMenu::highlightItemUnderMouse(sf::RenderWindow& window) {

    Item* item = itemList.getItemUnderMouse(window);
    if (item) {
        item->highlight(true);
    }
}

void DropdownMenu::updateListSize() {

    sf::Vector2f boxHeight = inputBox.getSize();

    itemList.setSize({(boxHeight.x), boxHeight.y});
}





Item* DropdownMenu::selectItem(Item* selectedItem) {

    if (selectedItem) {

        HistoryNode hn;
        hn.snapshot = getSnapshot();
        hn.component = this;
        History::pushHistory(hn);


        inputBox.setSelectedItem(selectedItem);
        isItemSelected = true;
    } else {
        isItemSelected = false;
    }
}


Snapshot DropdownMenu::getSnapshot() {


    Snapshot snapshot (inputBox.getText());
    return snapshot;
}

void DropdownMenu::applySnapshot(const Snapshot& snapshot) {
    inputBox.setText(snapshot.getText());


}

sf::Vector2f DropdownMenu::getSize() {
    return inputBox.getSize();
}

std::string DropdownMenu::getString() {
    return fontString;
}