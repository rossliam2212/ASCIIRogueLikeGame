//
// Created by Liam on 10/11/2022.
//

#include "HistoryLogger.h"

HistoryLogger::HistoryLogger()
    : HistoryLogger("../gameSessionHistory.txt") {
}

HistoryLogger::HistoryLogger(const std::string& fileName)
    : fileName{fileName} {
    setUpFile();
}

HistoryLogger::HistoryLogger(const std::string&& fileName)
    : fileName{fileName} {
    setUpFile();
}

/**
 * Sets up the file and prints a game started message to the output file.
 */
void HistoryLogger::setUpFile() {
    std::ofstream outputFile{fileName};
    if (!outputFile)
        return;

    outputFile << "Game Session Started @ " << getDateTime() << "\n";
    outputFile.close();
}

/**
 * Logs item picked up message to the output file.
 * @param item The item that was used.
 */
void HistoryLogger::logItemPickUp(Item *item) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    if (item->getName() == GoldCoin::goldCoinName ||
        item->getName() == HealthPotion::healthPotionName)
        outputFile << getDateTime() << "\t- Picked Up Item -> " << item->getName() << " @ position " << item->getPosition() << "\n";
    else {
        auto w = dynamic_cast<Weapon&>(*item);
        outputFile << getDateTime() << "\t- Picked Up Weapon -> " << w.getName() << "(" << w.attack() << " damage) @ position " << item->getPosition() << "\n";
    }
    outputFile.close();
}

/**
 * Logs weapon bought message to the output file.
 * @param weapon The weapon that was used.
 */
void HistoryLogger::logWeaponBought(Item* weapon) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    auto w = dynamic_cast<Weapon&>(*weapon);
    outputFile << getDateTime() << "\t- Bought Weapon for " << w.getPrice() << " gold coins -> " << w.getName() << "(" << w.attack() << " damage)" << "\n";
    outputFile.close();
}

void HistoryLogger::logPlayerXPLevelUp(int xpLevel, int newMaxHealth, int newStrength) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << getDateTime() << "\t- Leveled Up! New Stats -> XP Level: " << xpLevel << ", Max Health: " << newMaxHealth << ", Strength: " << newStrength << "\n";
    outputFile.close();
}

/**
 * Logs item used message to the output file.
 * @param item The item that was used.
 */
void HistoryLogger::logUsedItem(Item* item) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    if (item->getName() == GoldCoin::goldCoinName ||
        item->getName() == HealthPotion::healthPotionName)
        outputFile << getDateTime() << "\t- Used Item -> " << item->getName() << "\n";
    else {
        outputFile << getDateTime() << "\t- Dropped Weapon -> " << item->getName() << "\n";
    }

    outputFile.close();
}

/**
 * Logs monster killed message to the output file.
 * @param monster The monster that was killed.
 * @param weaponUsed The weapon used to kill the monster.
 */
void HistoryLogger::logMonsterKilled(Monster* monster, Weapon* weaponUsed) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << "\n\t\t- Killed Monster -> " << monster->getName() << "(+" << monster->getDeathXP() << "xp) w/ " << weaponUsed->getName()
                                               << "(" << weaponUsed->getAttacksRemaining() << " attacks remaining) @ position " << monster->getPosition() << "\n";
    outputFile.close();
}

/**
 * Logs attack started message to the output file.
 * @param monster The monster that the player started attacking.
 */
void HistoryLogger::logAttackStarted(Monster* monster) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << "\n" << getDateTime() << "\t- Attack Started -> Attacking " << monster->getName() << " (" << monster->getHealth() << "hp) @ position " << monster->getPosition() << "\n\n";
    outputFile.close();
}

/**
 * Logs the damage dealt the monster that the player started attacking.
 * @param monster The monster that the player is attacking.
 * @param damageAmount The damage amount dealt to the monster.
 */
void HistoryLogger::logDamageDealtToMonster(Monster* monster, int damageAmount) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << "\t\t- Dealt " << damageAmount << " damage to " << monster->getName() << " (" << monster->getHealth() << "hp remaining)\n";
    outputFile.close();
}

/**
 * Logs the damage dealt to the player by the monster they are attacking.
 * @param monster The monster that the player is attacking.
 * @param hp The player remaining hp.
 * @param damageAmount The damage amount dealt to the player.
 */
void HistoryLogger::logDamageDealtToPlayer(Monster* monster, int hp, int damageAmount) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << "\t\t- " << monster->getName() << " dealt " << damageAmount << " damage to You (" << hp << "hp remaining)\n";
    outputFile.close();
}

void HistoryLogger::logPlayerKilled(Monster* monster) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << "\n\t\t You were killed by " << monster->getName() << " (" << monster->getHealth() << "hp remaining)\n";
    outputFile.close();
}

/**
 * Logs level change message to the output file.
 * @param level The current level.
 */
void HistoryLogger::logLevelChange(int level) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << "\n====================================================\n";
    outputFile << getDateTime() << "Moved to Level " << level << "\n";
    outputFile << "====================================================\n";
    outputFile.close();
}

/**
 * Logs game over message to the output file.
 */
void HistoryLogger::logGameOver() {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << "\nGame Over @ " << getDateTime() << "\n";
    outputFile.close();
}

/**
 * Gets the current date and time from when the function was called.
 * @return The current date and time.
 */
const char* HistoryLogger::getDateTime() {
    time_t now = time(nullptr);
    char* dt = ctime(&now);
    return dt;
}