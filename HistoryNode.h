//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_HISTORYNODE_H
#define CS8_DROPDOWNMENU_HISTORYNODE_H

#include "Snapshot.h"
#include "GUIComponent.h"

struct HistoryNode {
    Snapshot snapshot;
    GUIComponent* component;
};

#endif //CS8_DROPDOWNMENU_HISTORYNODE_H
