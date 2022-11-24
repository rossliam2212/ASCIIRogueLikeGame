//
// Created by Liam on 18/11/2022.
//

#ifndef CODE_OGRE_H
#define CODE_OGRE_H

#include "Monster.h"

class Ogre : public Monster {
private:
    static constexpr const char* ogreName = "Ogre";
    static constexpr int ogreStrength{25};
    static constexpr int ogreHealth{120};
    static constexpr int ogreDeathXP{30};
    static constexpr int ogreFollowDistance{3};

public:
    Ogre(Player* player, const GameMap& map, const Point& position);
    ~Ogre() override = default;

    void update() override;
    void render() override;
    int attack() override;
};


#endif //CODE_OGRE_H
