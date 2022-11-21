//
// Created by Liam on 18/11/2022.
//

#include "Ogre.h"

const std::string Ogre::ogreName = "Ogre";

Ogre::Ogre(Player* player, const GameMap& map, const Point& position)
    : Monster{player, map, ogreStrength, ogreHealth, ogreDeathXP, ogreFollowDistance, position} {
    name = ogreName;
}

void Ogre::update() {

}

void Ogre::render() {

}

void Ogre::attack() {

}