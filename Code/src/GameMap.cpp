//
// Created by Liam on 17/10/2022.
//

#include "GameMap.h"

GameMap::GameMap(int mapWidth, int mapHeight)
    : mapWidth{mapWidth}, mapHeight{mapHeight}, monstersAndItems{} {
    map = new char[mapWidth * mapHeight];
}

GameMap::~GameMap() {
    delete[] map;
}

void GameMap::loadMap() {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, WINDOWSIZE_X, WINDOWSIZE_Y, TRUE); // window size in pixels
    utility::showConsoleCursor(FALSE);


    // Read map from gameMap.txt
    std::ifstream gameMapFile{ "../gameMap.txt", std::ios::in };

    if (!gameMapFile) {
        std::cerr << "Error opening level file\n";
        exit(1);
    }

    char c;
    int counter{};
    while (gameMapFile >> c) {
        if (std::isdigit(c))
            continue;

        if (c == defaultChar)
            c = floorChar;

        map[counter] = c;
        counter++;
    }

    // Checking for monsters/items in the map and creating instances for them
    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            char currentChar = map[y * mapWidth + x];

            if (currentChar == skeletonChar) {
                monstersAndItems.emplace_back(std::make_pair(skeletonChar, Point{x,y}));
            }
            else if (currentChar == zombieChar) {
                monstersAndItems.emplace_back(std::make_pair(zombieChar, Point{x,y}));
            }
            else if (currentChar == goldCoinChar) {
                monstersAndItems.emplace_back(std::make_pair(goldCoinChar, Point{x, y}));
            }
            else if (currentChar == healthPotionChar) {
                monstersAndItems.emplace_back(std::make_pair(healthPotionChar, Point{x, y}));
            }
            else if (currentChar == weaponChar) {
                monstersAndItems.emplace_back(std::make_pair(weaponChar, Point{x, y}));
            }

        }
    }

    monstersAndItems.shrink_to_fit();

    printMap();
    gameMapFile.close();
}

void GameMap::printMap() {
    utility::gotoScreenPosition(0, 0);

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            std::cout << map[y * mapWidth + x];
        }
        std::cout << "\n";
    }
}

// Get the character at position xy on the map
char GameMap::getXY(int x, int y) {
    return map[y * mapWidth + x];
}

char GameMap::getXY(Point& position) {
    return map[position.getY() * mapWidth + position.getX()];
}

// Set the character at position xy on the map
void GameMap::setXY(int x, int y, char value) {
    map[y * mapWidth + x] = value; //update value
}

void GameMap::setXY(Point& position, char value) {
    map[position.getY() * mapWidth + position.getX()] = value;
}

std::vector<std::pair<char, Point>> GameMap::getMonstersAndItems() const {
    return monstersAndItems;
}





