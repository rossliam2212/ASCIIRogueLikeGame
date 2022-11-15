//
// Created by Liam on 10/11/2022.
//

#ifndef CODE_HISTORYLOGGER_H
#define CODE_HISTORYLOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Item.h"
#include "GoldCoin.h"
#include "HealthPotion.h"
#include "Weapon.h"
#include "Monster.h"

class HistoryLogger {
private:
    std::string fileName;

public:
    HistoryLogger();
    HistoryLogger(const std::string& fileName);
    HistoryLogger(const std::string&& fileName);

    void logItemPickUp(Item* item);
    void logUsedItem(Item* item);
    void logMonsterKill(Monster* monster, Weapon* weaponUsed);
    void logGameOver();

private:
    void setUpFile();
    static const char* getDateTime();
};


#endif //CODE_HISTORYLOGGER_H
