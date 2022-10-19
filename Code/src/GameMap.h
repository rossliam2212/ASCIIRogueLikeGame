//
// Created by Liam on 17/10/2022.
//

#ifndef CODE_GAMEMAP_H
#define CODE_GAMEMAP_H


#include <fstream>
#include "utility.h"

#define WINDOWSIZE_X 800 // in px
#define WINDOWSIZE_Y 600 // in px

class GameMap {
public:
    // Map Characters
    static constexpr char floorChar = ' ';
    static constexpr char roofChar = '-';
    static constexpr char wallChar = '|';

private:
    char* map;

    int mapHeight;
    int mapWidth;

public:
    GameMap(int mapWidth, int mapHeight);
    ~GameMap();

    void loadMap();
    void printMap();

    char getXY(int x, int y);
    bool setXY(int x, int y, char value);
};


#endif //CODE_GAMEMAP_H
