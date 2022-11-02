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
    Player player;
    std::vector<Monster*> monsters;
    std::vector<std::pair<int, int>> monsterPositions;

    int level;
    bool stopGame{false};

public:
    GameManager();
    ~GameManager();
    void startGame();
    void endGame();

private:
    void update();
    void renderUI();
    void renderGameOverUI();
    void setUpMonsters();
};


#endif //CODE_GAMEMANAGER_H
