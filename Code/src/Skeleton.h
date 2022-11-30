//
// Created by Liam on 30/10/2022.
//

#ifndef CODE_SKELETON_H
#define CODE_SKELETON_H

#include "Monster.h"

class Skeleton : public Monster {
private:
    static constexpr const char* skeletonName = "Skeleton";
    static constexpr int skeletonStrength{20};
    static constexpr int skeletonHealth{100};
    static constexpr int skeletonDeathXP{20};
    static constexpr int skeletonDeathGold{5};
    static constexpr int skeletonFollowDistance{3};

public:
    Skeleton(Player* player, const GameMap& map, int level, const Point& position);
    ~Skeleton() override = default;

    void update() override;
    void render() override;
    int attack() override;
};


#endif //CODE_SKELETON_H
