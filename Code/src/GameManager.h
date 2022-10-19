//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_GAMEMANAGER_H
#define CODE_GAMEMANAGER_H

#include "GameMap.h"
#include "Player.h"

class GameManager {
    static constexpr int MAPSIZEX{83}; // 82 + 1 (WIDTH)
    static constexpr int MAPSIZEY{11}; // 11 (Height)

private:
    GameMap map;
    Player player;
    int level;
    bool stopGame{false};

public:
    GameManager();
    void startGame();
    void endGame();

private:
    void update();
    void renderUI();
};


#endif //CODE_GAMEMANAGER_H
