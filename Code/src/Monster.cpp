//
// Created by Liam on 19/10/2022.
//

#include "Monster.h"

Monster::Monster() : strength{defaultStrength}, health{defaultHealth}, xp{defaultXP} {
}

Monster::Monster(int strength, int health, int xp)
    : strength{strength},
      health{health},
      xp{xp} {
}

int Monster::getStrength() const { return strength; }
int Monster::getHealth() const { return health; }
int Monster::getXP() const { return xp; }
