//
// Created by Kristal Hong on 11/16/23.
//

#include "Snapshot.h"

Snapshot::Snapshot() {

}

//Snapshot::Snapshot(const sf::Vector2f &size) {
//
//}

Snapshot::Snapshot(const std::string& data) : data(data) {

}



const std::string& Snapshot::getText() const
{
    return data;
}


std::string Snapshot::getInputBoxText() const {
    return data;
}