cmake_minimum_required(VERSION 3.10)
project(TicTacToe CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(tictactoe
    src/main.cpp
    src/Board.cpp
    src/Player.cpp
    src/Game.cpp
)
