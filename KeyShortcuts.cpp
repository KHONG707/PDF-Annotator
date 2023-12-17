//
// Created by Kristal Hong on 11/16/23.
//

#include "KeyShortcuts.h"
bool KeyShortcuts::isUndo() {
    // Check if either Ctrl (or Command on Mac) and Z keys are pressed
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) &&
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LSystem) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RSystem)));
}

bool KeyShortcuts::isRedo() {
    // Check if either Ctrl (or Command on Mac) and Y keys are pressed
    return (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Y) &&
            (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LSystem) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RSystem)));
}