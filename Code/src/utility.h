//
// Created by Liam on 17/10/2022.
//

#ifndef CODE_UTILITY_H
#define CODE_UTILITY_H

#include <windows.h>
#include <iostream>
#include "Point.h"

namespace utility {
    void showConsoleCursor(bool showFlag);

    void gotoScreenPosition(short C, short R);
    void gotoScreenPosition(Point pos);
}


#endif //CODE_UTILITY_H
