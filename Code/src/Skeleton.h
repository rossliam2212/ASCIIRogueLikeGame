//
// Created by Liam on 30/10/2022.
//

#ifndef CODE_SKELETON_H
#define CODE_SKELETON_H

#include "Monster.h"

class Skeleton : public Monster {
private:
    static const std::string skeletonName;
    static constexpr int skeletonStrength{20};
    static constexpr int skeletonHealth{100};
    static constexpr int skeletonDeathXP{20};
    static constexpr int skeletonFollowDistance{2};

public:
    Skeleton(Player* player, const GameMap& map, const Point& position);
    ~Skeleton() override = default;

    void update() override;
    void render() override;
    void attack() override;
};


#endif //CODE_SKELETON_H
