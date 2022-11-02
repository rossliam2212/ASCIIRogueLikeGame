//
// Created by Liam on 30/10/2022.
//

#ifndef CODE_SKELETON_H
#define CODE_SKELETON_H

#include "Monster.h"

class Skeleton : public Monster {
    static constexpr int skeletonStrength{50};
    static constexpr int skeletonHealth{100};
    static constexpr int skeletonDeathXP{0};
    static constexpr int skeletonFollowDistance{0};

public:
    Skeleton(const GameMap& map, int startPositionX, int startPositionY);
    ~Skeleton() override = default;

    void update() override;
    void render() override;
    void attack() override;
};


#endif //CODE_SKELETON_H
