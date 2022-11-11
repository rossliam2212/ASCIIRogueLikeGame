cmake_minimum_required(VERSION 3.21)
project(Code)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(SOURCE_FILES
        src/main.cpp
        src/GameManager.cpp
        src/GameManager.h
        src/GameMap.cpp
        src/GameMap.h
        src/Inventory.cpp
        src/Inventory.h
        src/Player.cpp
        src/Player.h
        src/utility.cpp
        src/utility.h
        src/Monster.cpp
        src/Monster.h
        src/Weapon.cpp
        src/Weapon.h
        src/Skeleton.cpp
        src/Skeleton.h
        src/Zombie.cpp
        src/Zombie.h
        src/Point.cpp
        src/Point.h
        src/HistoryLogger.cpp
        src/HistoryLogger.h
        src/Item.cpp
        src/Item.h src/GoldCoin.cpp src/GoldCoin.h src/HealthPotion.cpp src/HealthPotion.h)

add_executable(Code ${SOURCE_FILES})
