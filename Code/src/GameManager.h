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
#include "Goblin.h"
#include "Ogre.h"
#include "HistoryLogger.h"
#include "GoldCoin.h"
#include "HealthPotion.h"

class GameManager {
private:
    // Same for all levels
    static constexpr int mapSizeX{83}; // 82 + 1 (WIDTH)
    static constexpr int mapSizeY{26}; // 26 (Height)

    static constexpr int numberOfLevels{5};

    int level;
    bool levelsCompleted{false};

    GameMap map;
    std::vector<Monster*> monsters;
    std::vector<Item*> mapItems;
    HistoryLogger historyLogger;
    Player player;

    // CLion format for finding files
    const std::array<std::string, numberOfLevels> levels {
        "../levels/level1.txt",
        "../levels/level2.txt",
        "../levels/level3.txt",
        "../levels/level4.txt",
        "../levels/level5.txt"
    };


public:
    GameManager();
    ~GameManager();
    void startGame();
    void nextLevel();
    bool gameOver();

private:
    void update();
    void renderUI();
    static void renderGameOverWinUI();
    static void renderGameOverUI();
    void setUpGameItemsAndMonsters();
    void cleanResourcesOnLevelChange();
};


#endif //CODE_GAMEMANAGER_H
