//
// Created by Kristal Hong on 11/16/23.
//

#include "ItemList.h"

ItemList::ItemList() {
    listState.enableState(HIDDEN);
}


void ItemList::draw(sf::RenderTarget& window, sf::RenderStates states) const {
    // Draw each item in the list
    if (!listState.checkState(HIDDEN)) {
        for (auto& item : items) {
            item->draw(window, states);
        }
    }

}


void ItemList::addItem(Item *item) {
    items.push_back(item);
}


int ItemList::getSize() {
    return items.size();
}

void ItemList::setSize(sf::Vector2f position) {
    float spacing = 5.0f;
    for (size_t i = 0; i < items.size(); ++i) {
        items[i]->setSize(position);
    }

}

sf::Vector2f ItemList::getPosition()  {
    if (!items.empty()) {
        return items[0]->getPosition();
    } else {
        // Return a default position if the items vector is empty
        return sf::Vector2f(0.0f, 0.0f);
    }
}



Item* ItemList::getItemUnderMouse(sf::RenderWindow& window) {
    for (auto& item : items) {
        if (MouseEvents::isClicked(*item, window)) {
            return item;
        }
    }
    return nullptr;
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for (Item *item : items) {
        if (MouseEvents::isHovered(*item, window)) {
            item->highlight(true);
        } else {
            item->highlight(false);  // Unhighlight other items
        }
        if (MouseEvents::isClicked(*item, window)) {
            if (item->callback != nullptr) {
                item->callback(item->getTextString());
            }
        }
    }
}



void ItemList::highlightItem(Item* item, bool isHighlighted) {
    // Set the highlighting state of a specific item
    if (item) {
        item->highlight(isHighlighted);
    }
}



void ItemList::setPosition(sf::Vector2f position) {
    if(!items.empty())
    {
        items[0]->setPosition(position);
        for (int i = 1; i < items.size() ; ++i) {
            Position::below(*(items[i-1]), *(items[i]), spacing);
        }
    }

}

void ItemList::update() {
        //
}


const std::vector<Item*>& ItemList::getItems() const {
    return items;
}


sf::FloatRect ItemList::getGlobalBounds() const {
    if (items.empty()) {
        return sf::FloatRect();
    }

    sf::FloatRect globalBounds = items[0]->getGlobalBounds();

    for (size_t i = 1; i < items.size(); ++i) {
        const sf::FloatRect& itemBounds = items[i]->getGlobalBounds();

        if (itemBounds.left < globalBounds.left) {
            globalBounds.width += globalBounds.left - itemBounds.left;
            globalBounds.left = itemBounds.left;
        }
        if (itemBounds.top < globalBounds.top) {
            globalBounds.height += globalBounds.top - itemBounds.top;
            globalBounds.top = itemBounds.top;
        }
        if (itemBounds.left + itemBounds.width > globalBounds.left + globalBounds.width) {
            globalBounds.width = itemBounds.left + itemBounds.width - globalBounds.left;
        }
        if (itemBounds.top + itemBounds.height > globalBounds.top + globalBounds.height) {
            globalBounds.height = itemBounds.top + itemBounds.height - globalBounds.top;
        }
    }

    return globalBounds;
}

void ItemList::toggleVisibility() {
    listState.toggleState(statesEnum::HIDDEN);
}

bool ItemList::checkState() const {
    return listState.checkState(HIDDEN);
}

std::string ItemList::getOption() {
//    std::cout << selectedText;
    return selectedText;
}
