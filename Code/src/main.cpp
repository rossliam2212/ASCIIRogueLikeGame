#include <iostream>

#include "GameMap.h"
#include "Player.h"


constexpr int MAPSIZEX{35};
constexpr int MAPSIZEY{25};

void renderUI(const Player& player);

int main() {
    GameMap map;
    map.loadMap(MAPSIZEX, MAPSIZEY);

    Player p;

    while (true) {
        p.update();

        renderUI(p);
    }
    return 0;
}

void renderUI(const Player& player) {
    utility::gotoScreenPosition(0, MAPSIZEY);

    std::cout << "Level: 1"
              << "\tHP: " << player.getHealth()
              << "\tXP: " << player.getXp();
}
