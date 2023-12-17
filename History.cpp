//
// Created by Kristal Hong on 11/16/23.
//

#include "History.h"

std::stack<HistoryNode> History::stack;

void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);

}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    if (!stack.empty()) {
        stack.top().component->applySnapshot(stack.top().snapshot); //apply snapshot back to object
        stack.pop();
    }
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
// Handle events to trigger undo and redo

    if (KeyShortcuts::isUndo()) {
        popHistory();

    }
    if (KeyShortcuts::isRedo()) {
        if (canRedo()) {
            redo();
        }
    }

}


bool History::canUndo() {
    return !stack.empty();
}

bool History::canRedo() {
    return !stack.empty();
}

void History::undo() {

    HistoryNode history = topHistory();
    history.component->applySnapshot(history.snapshot);
    popHistory();

}


void History::redo() {

    HistoryNode historyNode = stack.top();
    stack.pop();
    pushHistory(historyNode);

    historyNode.component->applySnapshot(historyNode.snapshot);
//    }
}