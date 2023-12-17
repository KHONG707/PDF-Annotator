//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_STATES_H
#define CS8_DROPDOWNMENU_STATES_H
#include <iostream>
#include <map>
#include "statesEnum.h"

class States {
private:
    std::map<statesEnum, bool> states; //bool = represent states of the object (whether in the state or not)
    //The map data structure is a container of key/value pairs. Think of it as an array, only you can use any data type as the index
    //statesEnum would be the "index" and bool would be the "value".

public:
    States();
    bool checkState (statesEnum state) const; //check state of object - take in statesEnum - true/false
    void enableState(statesEnum state); //to make that state true
    void disableState(statesEnum state); //to make that state false
    void toggleState(statesEnum state); //switch between

};


#endif //CS8_DROPDOWNMENU_STATES_H
