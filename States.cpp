//
// Created by Kristal Hong on 11/16/23.
//

#include "States.h"

States::States()
{
    for(int i = 0; i < LAST_STATE; i++) {
        states[static_cast<statesEnum>(i)] = false; //cast integer into statesEnum
    }
}

bool States::checkState(statesEnum state) const {
//    return states[state]; //Cant use this bc map doesnt do the []
    return states.at(state);
}

void States::enableState(statesEnum state) {
    states[state] = true;
}

void States::disableState(statesEnum state) {
    states[state] = false;
}

void States::toggleState(statesEnum state) {
    states[state] = !states[state];
}
