#include "Board.h"
#include <iostream>

Board::Board() {
    reset();
}

void Board::reset() {
    for (auto& c : cells) c = ' ';
}

std::array<char, 9>& Board::getCells() {
    return cells;
}

void Board::display() const {
    std::cout << "\n";
    for (int row = 0; row < 3; ++row) {
        std::cout << " ";
        for (int col = 0; col < 3; ++col) {
            int idx = row * 3 + col;
            char c = cells[idx];
            std::cout << (c == ' ' ? std::to_string(idx + 1) : std::string(1, c));
            if (col < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (row < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

bool Board::placeMark(int position, char mark) {
    if (position < 1 || position > 9) return false;
    int idx = position - 1;
    if (cells[idx] != ' ') return false;
    cells[idx] = mark;
    return true;
}

bool Board::isCellEmpty(int position) const {
    if (position < 1 || position > 9) return false;
    return cells[position - 1] == ' ';
}

bool Board::isFull() const {
    for (char c : cells)
        if (c == ' ') return false;
    return true;
}

char Board::getWinner() const {
    static const int lines[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };

    for (const auto& line : lines) {
        char a = cells[line[0]];
        char b = cells[line[1]];
        char c = cells[line[2]];
        if (a != ' ' && a == b && b == c) return a;
    }
    return ' ';
}

bool Board::isGameOver() const {
    return getWinner() != ' ' || isFull();
}

std::vector<int> Board::getEmptyPositions() const {
    std::vector<int> positions;
    for (int i = 0; i < 9; ++i)
        if (cells[i] == ' ') positions.push_back(i + 1);
    return positions;
}
