#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <vector>

class Board {
public:
    Board();

    void display() const;
    bool placeMark(int position, char mark);   // position: 1-9
    bool isFull() const;
    bool isCellEmpty(int position) const;
    char getWinner() const;                    // 'X', 'O', or ' ' if none
    bool isGameOver() const;
    std::vector<int> getEmptyPositions() const;
    void reset();
    std::array<char, 9>& getCells();

private:
    std::array<char, 9> cells; // index 0-8 maps to positions 1-9
};

#endif // BOARD_H
