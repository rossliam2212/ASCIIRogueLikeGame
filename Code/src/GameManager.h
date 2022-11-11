//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_GAMEMANAGER_H
#define CODE_GAMEMANAGER_H

#include "GameMap.h"
#include "Item.h"
#include "Player.h"
#include "Monster.h"
#include "Skeleton.h"
#include "Zombie.h"
#include "HistoryLogger.h"
#include "GoldCoin.h"
#include "HealthPotion.h"

class GameManager {
    static constexpr int MAPSIZEX{83}; // 82 + 1 (WIDTH)
    static constexpr int MAPSIZEY{26}; // 26 (Height)

private:
    GameMap map;
    std::vector<Monster*> monsters;
    std::vector<Item*> mapItems;
    HistoryLogger historyLogger;
    Player player;

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
    void setUpGameItemsAndMonsters();
};


#endif //CODE_GAMEMANAGER_H
