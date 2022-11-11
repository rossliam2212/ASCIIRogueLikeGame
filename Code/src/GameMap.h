//
// Created by Liam on 17/10/2022.
//

#ifndef CODE_GAMEMAP_H
#define CODE_GAMEMAP_H


#include <fstream>
#include <vector>
#include "utility.h"
#include "Point.h"

#define WINDOWSIZE_X 800 // in px
#define WINDOWSIZE_Y 700 // in px

class GameMap {
public:
    // --- Map Characters ---
    // Environment
    static constexpr char defaultChar = '=';
    static constexpr char floorChar = ' ';
    static constexpr char roofChar = '-';
    static constexpr char wallChar = '|';

    // Game Items
    static constexpr char healthPotionChar = '^';
    static constexpr char goldCoinChar = '*';
    static constexpr char weaponChar = '?';

    // Characters
    static constexpr char playerChar = '@';
    static constexpr char skeletonChar = 'S';
    static constexpr char zombieChar = 'Z';


private:
    char* map;

    int mapHeight;
    int mapWidth;

    std::vector<std::pair<char, Point>> monstersAndItems;

public:
    GameMap(int mapWidth, int mapHeight);
    ~GameMap();

    void loadMap();
    void printMap();

    char getXY(int x, int y);
    char getXY(Point& position);

    void setXY(int x, int y, char value);
    void setXY(Point& position, char value);

    std::vector<std::pair<char, Point>> getMonstersAndItems() const;
};


#endif //CODE_GAMEMAP_H
