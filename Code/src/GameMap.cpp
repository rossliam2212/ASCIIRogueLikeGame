//
// Created by Liam on 17/10/2022.
//

#include "GameMap.h"

GameMap::GameMap(int mapWidth, int mapHeight)
    : map{nullptr}, mapWidth{mapWidth}, mapHeight{mapHeight}, monstersAndItems{} {
    map = new char[mapWidth * mapHeight];
}

GameMap::~GameMap() {
    delete[] map;
}

/**
 * Loads the current level map from the text file.
 * @param level The current level.
 * @param levels The level text files.
 */
void GameMap::loadMap(int level, const std::array<std::string, 5>& levels) {
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, WINDOWSIZE_X, WINDOWSIZE_Y, TRUE); // window size in pixels
    utility::showConsoleCursor(false);


    // Read level maps from text files
    std::ifstream gameMapFile{levels[level-1], std::ios::in };

    if (!gameMapFile) {
        std::cerr << "Error opening level file\n";
        exit(1);
    }

    char c;
    int counter{};
    while (gameMapFile >> c) {
        // Ignoring the ruler at the bottom of the level txt files.
        if (std::isdigit(c))
            continue;

        // Replace the '=' characters with ' '
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
            else if (currentChar == goblinChar) {
                monstersAndItems.emplace_back(std::make_pair(goblinChar, Point{x,y}));
            }
            else if (currentChar == ogreChar) {
                monstersAndItems.emplace_back(std::make_pair(ogreChar, Point{x,y}));
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

/**
 * Prints the map.
 */
void GameMap::printMap() {
    utility::gotoScreenPosition(0, 0);

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            std::cout << map[y * mapWidth + x];
        }
        std::cout << "\n";
    }
}

/**
 * This function is called when the player moves to a new level.
 * The monsters and items vector is cleared, so it can be used for the new monsters and items in the next level.
 */
void GameMap::clearResourcesForLevelChange() {
    monstersAndItems.clear();
}

/**
 * Gets the character at the xy position passed in.
 * @param x The x position.
 * @param y The y position.
 * @return The character at the given xy position.
 */
char GameMap::getXY(int x, int y) {
    return map[y * mapWidth + x];
}

/**
 * Gets the character at the position passed in
 * @param position The xy position.
 * @return The character at the given position.
 */
char GameMap::getXY(const Point& position) {
    return map[position.getY() * mapWidth + position.getX()];
}

/**
 * Sets the character at the xy position passed in.
 * @param x The x position.
 * @param y The y position.
 * @param value The new character to set the given xy position to.
 */
void GameMap::setXY(int x, int y, char value) {
    map[y * mapWidth + x] = value; //update value
}

/**
 * Sets the character at the position passed in.
 * @param position The xy position.
 * @param value The new character to set the given position to.
 */
void GameMap::setXY(const Point& position, char value) {
    map[position.getY() * mapWidth + position.getX()] = value;
}

/**
 * Getter for the monsters and items vectors.
 * @return The monsters and items vector.
 */
std::vector<std::pair<char, Point>> GameMap::getMonstersAndItems() const {
    return monstersAndItems;
}





