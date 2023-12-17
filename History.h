//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_HISTORY_H
#define CS8_DROPDOWNMENU_HISTORY_H
#include "HistoryNode.h"
#include "KeyShortcuts.h"
#include <stack>
#include <iostream>

class History {
private:
    static std::stack<HistoryNode> stack;
//    static std::stack<HistoryNode> undoStack;
//    static std::stack<HistoryNode> redoStack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);

    static void redo();
    static void undo();

    static bool canRedo();
    static bool canUndo();

    int size();
    bool empty();

};


#endif //CS8_DROPDOWNMENU_HISTORY_H
