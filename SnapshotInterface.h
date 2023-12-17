//
// Created by Kristal Hong on 11/16/23.
//

#ifndef CS8_DROPDOWNMENU_SNAPSHOTINTERFACE_H
#define CS8_DROPDOWNMENU_SNAPSHOTINTERFACE_H
#include "Snapshot.h"

class SnapshotInterface {
public:
    SnapshotInterface() {};
    //This function will return a snapshot of the object's current state
    virtual Snapshot getSnapshot() = 0;

// this function will apply a snapshot to the object.
//This will revert the object back to the state that has been recorded in the snapshot
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //CS8_DROPDOWNMENU_SNAPSHOTINTERFACE_H
