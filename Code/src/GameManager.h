//
// Created by Liam on 19/10/2022.
//

#ifndef CODE_GAMEMANAGER_H
#define CODE_GAMEMANAGER_H

#include "GameMap.h"
#include "Player.h"

class GameManager {
    static constexpr int MAPSIZEX{24};
    static constexpr int MAPSIZEY{16};

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
