//
// Created by Liam on 17/10/2022.
//

#include "GameMap.h"

GameMap::GameMap(int mapWidth, int mapHeight)
    : map{nullptr}, mapWidth{mapWidth}, mapHeight{mapHeight} {
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


    // allocate memory for the 2D array
    map = new char[mapWidth * mapHeight];


    // Read map from gameMap.txt
    std::ifstream gameMapFile{ "../gameMap.txt" };

    if (!gameMapFile) {
        std::cerr << "Error opening level file\n";
        exit(1);
    }

    char c;
    int counter{};
    while (gameMapFile >> c) {
        if (std::isdigit(c))
            continue;

        if (c == '=')
            c = FLOORCHAR;

        map[counter] = c;
        counter++;
    }

    // For now just create a map with walls. Later we implement reading from file
//    for (int y = 0; y < mapHeight; y++) {
//        for (int x = 0; x < mapWidth; x++) {
//            if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight -1)
//                map[y * mapWidth + x] = WALLCHAR;
//            else
//                map[y * mapWidth + x] = FLOORCHAR;
//        }
//    }

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

// Set the character at position xy on the map
bool GameMap::setXY(int x, int y, char value) {
    map[y * mapWidth + x] = value; //update value
    return true;
}



