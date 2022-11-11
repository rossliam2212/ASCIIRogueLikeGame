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

    outputFile << "\nPicked Up -> " << item->getName() << " @ position " << item->getPosition() << "\n";
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