//
// Created by Liam on 10/11/2022.
//

#include "HistoryLogger.h"

HistoryLogger::HistoryLogger()
    : HistoryLogger("../GameSessionHistory.txt") {
}

HistoryLogger::HistoryLogger(const std::string& fileName)
    : fileName{fileName} {
    setUpFile();
}

HistoryLogger::HistoryLogger(const std::string&& fileName)
    : fileName{fileName} {
    setUpFile();
}

void HistoryLogger::setUpFile() {
    std::ofstream outputFile{fileName};

    if (!outputFile)
        return;

    outputFile << "Game Session Started @ " << getDateTime() << "\n";
    outputFile.close();
}

void HistoryLogger::logItemPickUp(Item *item) {
    std::ofstream outputFile{fileName, std::ios::app};

    if (!outputFile)
        return;

    if (item->getName() == GoldCoin::goldCoinName ||
        item->getName() == HealthPotion::healthPotionName)
        outputFile << "\nPicked Up Item -> " << item->getName() << " @ position " << item->getPosition() << "\n";
    else {
//        auto w = dynamic_cast<Weapon&>(*item);
//        outputFile << "\nPicked Up -> " << w.getName() << "(" << w.attack() << " damage) @ position " << item->getPosition() << "\n";
    }
    outputFile.close();
}

void HistoryLogger::logUsedItem(Item* item) {
    std::ofstream outputFile{fileName, std::ios::app};

    if (!outputFile)
        return;

    if (item->getName() == GoldCoin::goldCoinName ||
        item->getName() == HealthPotion::healthPotionName)
        outputFile << "\nUsed Item -> " << item->getName() << " @ " << getDateTime() << "\n";
    else
        outputFile << "\nDropped Weapon -> " << item->getName() << " @ " << getDateTime() << "\n";

    outputFile.close();
}

void HistoryLogger::logGameOver() {
    std::ofstream outputFile{fileName, std::ios::app};

    if (!outputFile)
        return;

    outputFile << "\nGame Over @ " << getDateTime() << "\n";
    outputFile.close();
}

const char* HistoryLogger::getDateTime() {
    time_t now = time(nullptr);
    char* dt = ctime(&now);
    return dt;
}