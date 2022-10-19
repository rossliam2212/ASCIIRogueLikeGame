cmake_minimum_required(VERSION 3.21)
project(Code)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES src/main.cpp
        src/GameMap.cpp
        src/utility.cpp
        src/Player.cpp
        src/GameManager.cpp
        src/Monster.cpp)

set(HEADER_FILES src/GameMap.h
        src/utility.h
        src/Player.h
        src/GameManager.h
        src/Monster.h)

add_executable(Code ${SOURCE_FILES} ${HEADER_FILES})
