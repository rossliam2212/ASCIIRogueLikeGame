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
void HistoryLogger::logMonsterKill(Monster* monster, Weapon* weaponUsed) {
    std::ofstream outputFile{fileName, std::ios::app};
    if (!outputFile)
        return;

    outputFile << getDateTime() << "\t- Killed Monster -> " << monster->getName() << "(+" << monster->getDeathXP() << "xp) w/ " << weaponUsed->getName() << " @ position " << monster->getPosition() << "\n";
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