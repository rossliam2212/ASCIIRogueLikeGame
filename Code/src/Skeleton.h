//
// Created by Liam on 30/10/2022.
//

#ifndef CODE_SKELETON_H
#define CODE_SKELETON_H

#include "Monster.h"

class Skeleton : public Monster {
    static constexpr int skeletonStrength{50};
    static constexpr int skeletonHealth{100};
    static constexpr int skeletonXP{0};
    static constexpr int skeletonFollowDistance{0};

public:
    Skeleton(const GameMap& map);
    Skeleton(const GameMap& map, int strength, int health, int xp);
    ~Skeleton() override = default;
};


#endif //CODE_SKELETON_H
