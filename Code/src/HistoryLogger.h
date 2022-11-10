//
// Created by Liam on 10/11/2022.
//

#ifndef CODE_HISTORYLOGGER_H
#define CODE_HISTORYLOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

enum LogType {
    PickedUpGoldCoin,
    PickUpWeapon,
};

class HistoryLogger {
private:
    std::string fileName;

public:
    HistoryLogger();
    HistoryLogger(const std::string& fileName);
    HistoryLogger(const std::string&& fileName);

    void logGameOver();

private:
    void setUpFile();
    static const char* getDateTime();
};


#endif //CODE_HISTORYLOGGER_H
