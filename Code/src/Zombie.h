//
// Created by Liam on 30/10/2022.
//

#ifndef CODE_ZOMBIE_H
#define CODE_ZOMBIE_H

#include "Monster.h"

class Zombie : public Monster {
private:
    static constexpr const char* zombieName = "Zombie";
    static constexpr int zombieStrength{15};
    static constexpr int zombieHealth{100};
    static constexpr int zombieDeathXP{15};
    static constexpr int zombieDeathGold{3};
    static constexpr int zombieFollowDistance{4};

public:
    Zombie(Player* player, const GameMap& map, int level, const Point& position);
    ~Zombie() override = default;

    void update() override;
    void render() override;
    int attack() override;
};


#endif //CODE_ZOMBIE_H
