//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_GAMEMANAGER_H
#define CODE_GAMEMANAGER_H

#include "GameMap.h"
#include "Player.h"
#include "Monster.h"
#include "Skeleton.h"
#include "Zombie.h"

class GameManager {
    static constexpr int MAPSIZEX{83}; // 82 + 1 (WIDTH)
    static constexpr int MAPSIZEY{26}; // 26 (Height)

private:
    GameMap map;
    std::vector<Monster*> monsters;
    Player player;
    std::vector<Point> monsterPositions;

    int level;
    bool stopGame{false};

public:
    GameManager();
    ~GameManager();
    void startGame();
    bool gameOver();

private:
    void update();
    void renderUI();
    void renderGameOverUI();
    void setUpMonsters();
};


#endif //CODE_GAMEMANAGER_H
