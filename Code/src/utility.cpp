//
// Created by Liam on 17/10/2022.
//

#include "utility.h"


void utility::showConsoleCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void utility::gotoScreenPosition(short C, short R) {
    COORD xy;
    xy.X = C;
    xy.Y = R;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void utility::gotoScreenPosition(Point pos) {
    gotoScreenPosition((short)pos.getX(), (short)pos.getY());
}