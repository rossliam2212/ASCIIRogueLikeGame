//
// Created by Liam on 30/10/2022.
//

#ifndef CODE_SKELETON_H
#define CODE_SKELETON_H

#include "Monster.h"

class Skeleton : public Monster {
    static constexpr int skeletonStrength{20};
    static constexpr int skeletonHealth{100};
    static constexpr int skeletonDeathXP{15};
    static constexpr int skeletonFollowDistance{2};

public:
    Skeleton(const GameMap& map, Point position);
    ~Skeleton() override = default;

    void update() override;
    void render() override;
    void attack() override;
};


#endif //CODE_SKELETON_H
