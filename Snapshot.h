//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_SNAPSHOT_H
#define CS8_DROPDOWNMENU_SNAPSHOT_H

//#include "MultiText.h"
#include <iostream>


class Snapshot
{
private:
    std::string data;
public:

    std::string getInputBoxText() const;

    Snapshot();


    Snapshot(const std::string& data);


    const std::string& getText() const;


    bool isMenuOpen;
    std::size_t selectedItemIndex;
};


#endif //CS8_DROPDOWNMENU_SNAPSHOT_H
