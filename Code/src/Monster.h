//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_MONSTER_H
#define CODE_MONSTER_H


class Monster {
    static constexpr int defaultStrength{50};
    static constexpr int defaultHealth{100};
    static constexpr int defaultXP{0};

private:
    int strength;
    int health;
    int xp;

public:
    Monster();
    Monster(int strength, int health, int xp);

    int getStrength() const;
    int getHealth() const;
    int getXP() const;
};


#endif //CODE_MONSTER_H
