//
// Created by Liam on 17/10/2022.
//

#ifndef CODE_GAMEMAP_H
#define CODE_GAMEMAP_H


#include <fstream>
#include <vector>
#include <array>
#include "utility.h"
#include "Point.h"

#define WINDOWSIZE_X 800 // in px
#define WINDOWSIZE_Y 800 // in px

class GameMap {
public:
    // --- Map Characters ---
    // Environment
    static constexpr char defaultChar = '=';
    static constexpr char floorChar = ' ';
    static constexpr char roofChar = '-';
    static constexpr char wallChar = '|';
    static constexpr char nextLevelChar = '>';

    // Game Items
    static constexpr char healthPotionChar = '^';
    static constexpr char goldCoinChar = '*';
    static constexpr char weaponChar = '?';
    static constexpr char buyMenuChar = '$';

    // Characters
    static constexpr char playerChar = '@';
    static constexpr char skeletonChar = 'S';
    static constexpr char zombieChar = 'Z';
    static constexpr char goblinChar = 'G';
    static constexpr char ogreChar = 'O';


private:
    char* map;

    int mapHeight;
    int mapWidth;

    std::vector<std::pair<char, Point>> monstersAndItems;

public:
    GameMap(int mapWidth, int mapHeight);
    ~GameMap();

    void loadMap(int level, const std::array<std::string, 5> &levels);
    void printMap();

    char getXY(int x, int y);
    char getXY(const Point &position);

    void setXY(int x, int y, char value);
    void setXY(Point& position, char value);

    void clearResourcesForLevelChange();

    std::vector<std::pair<char, Point>> getMonstersAndItems() const;
};


#endif //CODE_GAMEMAP_H
