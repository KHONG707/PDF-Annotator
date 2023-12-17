//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_APPLICATION_H
#define CS8_DROPDOWNMENU_APPLICATION_H
#include "GUIComponent.h"
#include "EventHandler.h"
#include "History.h"
#include "SnapshotInterface.h"
#include "DropdownMenu.h"
#include "TextInput.h"
#include "MenuBar.h"
#include "Canvas.h"
#include "FileTree.h"
#include "Everything.h"
#include <functional>

class Application
{
private:
    static std::vector<GUIComponent*> components;

public:
    Application();
    static void addComponent(GUIComponent& component);
    static void run();
};



#endif //CS8_DROPDOWNMENU_APPLICATION_H
