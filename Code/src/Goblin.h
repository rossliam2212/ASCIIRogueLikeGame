//
// Created by Liam on 18/11/2022.
//

#ifndef CODE_GOBLIN_H
#define CODE_GOBLIN_H

#include "Monster.h"

class Goblin : public Monster {
private:
    static const std::string goblinName;
    static constexpr int goblinStrength{10};
    static constexpr int goblinHealth{100};
    static constexpr int goblinDeathXP{10};
    static constexpr int goblinFollowDistance{5};

public:
    Goblin(Player* player, const GameMap& map, const Point& position);
    ~Goblin() override = default;

    void update() override;
    void render() override;
    int attack() override;
};


#endif //CODE_GOBLIN_H
