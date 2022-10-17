//
// Created by Liam on 17/10/2022.
//

#ifndef CODE_GAMEMAP_H
#define CODE_GAMEMAP_H


#include "utility.h"

#define WALLCHAR '#'
#define FLOORCHAR ' '
#define WINDOWSIZE_X 800 // in px
#define WINDOWSIZE_Y 600 // in px

class GameMap {
private:
    int mapHeight;
    int mapWidth;

    char* map;

public:
    GameMap();
    ~GameMap();

    void loadMap(int width, int height);
    char getXY(int x, int y);
    bool setXY(int x, int y, char value);
    void printMap();
};


#endif //CODE_GAMEMAP_H
