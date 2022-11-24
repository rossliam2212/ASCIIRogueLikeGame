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
    explicit HistoryLogger(const std::string& fileName);
    explicit HistoryLogger(const std::string&& fileName);

    void logItemPickUp(Item* item);
    void logWeaponBought(Item* weapon);
    void logUsedItem(Item* item);
    void logWeaponBroke(Item* weapon);
    void logPlayerXPLevelUp(int xpLevel, int newMaxHealth, int newStrength);

    void logAttackStarted(Monster* monster);
    void logDamageDealtToMonster(Monster* monster, int damageAmount);
    void logDamageDealtToPlayer(Monster* monster, int hp, int damageAmount);
    void logPlayerKilled(Monster* monster);
    void logMonsterKilled(Monster* monster, Weapon* weaponUsed);
    void logLevelChange(int level);
    void logGameOver();
    void logPlayerWinsGame();

private:
    void setUpFile();
    static const char* getDateTime();
};


#endif //CODE_HISTORYLOGGER_H
