//
// Created by Liam on 30/10/2022.
//

#ifndef CODE_ZOMBIE_H
#define CODE_ZOMBIE_H

#include "Monster.h"

class Zombie : public Monster {
    static constexpr int zombieStrength{15};
    static constexpr int zombieHealth{100};
    static constexpr int zombieDeathXP{10};
    static constexpr int zombieFollowDistance{5};

public:
    Zombie(const GameMap& map, Point position);
    ~Zombie() override = default;

    void update() override;
    void render() override;
    void attack() override;
};


#endif //CODE_ZOMBIE_H
