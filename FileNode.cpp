//
// Created by Kristal Hong on 11/21/23.
//

#include "FileNode.h"


void FileNode::reposition() const {

    sf::Vector2f position = data.getPosition();
    position.x += 50;
    position.y += data.getGlobalBounds().height;

    if (checkState(SHOW_CHILDREN)) {
        for (auto &c : children) {
            c.second->getData().setPosition(position);
            position.y += c.second->getGlobalBounds().height;
            c.second->reposition();
        }
    }
}

FileNode::FileNode() {
    disableState(SHOW_CHILDREN);
}

FileNode::FileNode(std::string text, sf::Vector2f size, sf::Vector2f position)
: data(text, size, position) {

    disableState(SHOW_CHILDREN);
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    data.draw(window, states);
//    window.draw(data);

    // Draw the children recursively if they should be shown
    if (checkState(SHOW_CHILDREN)) {
//        for (const auto& child : children) {
//            child.second->draw(window, states);
//        }
        for (auto i = children.begin(); i != children.end(); ++i) {
            window.draw(*(i->second));
        }
    }
}



void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    data.addEventHandler(window, event);
    if (MouseEvents::isClicked(data, window)) {
        enableState(SELECTED);
        toggleChildren();
    }

    if (checkState(SHOW_CHILDREN)) {
        for (auto i = children.begin(); i != children.end(); ++i) {

            i->second->addEventHandler(window, event);
            if(MouseEvents::isClicked(*i->second, window))
            {
                disableState(SELECTED);
                disableState(SHOW_CHILDREN);
            }

        }
    }
}

void FileNode::update() {
    //
}

Snapshot FileNode::getSnapshot() {
    //
}

void FileNode::applySnapshot(const Snapshot &snapshot) {
    //
}

sf::FloatRect FileNode::getGlobalBounds() {
    // Get the global bounds for the current node
    sf::FloatRect bounds = data.getGlobalBounds();

    if (checkState(SHOW_CHILDREN) && !children.empty()) {
        for (auto& c: children) {
            bounds.height += c.second->getGlobalBounds().height;
        }
    }


    return bounds;
}

bool FileNode::isLeaf() const {
    return children.empty();
}

FileItem &FileNode::getData() {
    return data;
}

void FileNode::setData(FileItem newData) {
    data = newData;
}

std::map<std::string, FileNode *> &FileNode::getChildren() {
    return children;
}

FileNode::iterator FileNode::begin() {
    return children.begin();
}

FileNode::iterator FileNode::end() {
    return children.end();
}

void FileNode::toggleChildren() {
    toggleState(SHOW_CHILDREN);
}



