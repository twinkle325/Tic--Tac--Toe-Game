#include "Player.h"
#include <iostream>
#include <limits>
#include <sstream>

int HumanPlayer::getMove(Board& board) {
    int position = 0;
    while (true) {
        std::cout << name << " (" << mark << "), enter your move (1-9): ";
        std::string line;
        if (!std::getline(std::cin, line)) {
            std::cout << "\nNo more input available. Exiting.\n";
            std::exit(0);
        }
        std::istringstream iss(line);

        if (!(iss >> position)) {
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
            continue;
        }
        if (position < 1 || position > 9) {
            std::cout << "Out of range. Choose a position between 1 and 9.\n";
            continue;
        }
        if (!board.isCellEmpty(position)) {
            std::cout << "That cell is already taken. Try again.\n";
            continue;
        }
        break;
    }
    return position;
}

int AIPlayer::getMove(Board& board) {
    int bestScore = std::numeric_limits<int>::min();
    int bestMove = -1;

    for (int pos : board.getEmptyPositions()) {
        board.placeMark(pos, mark);
        int score = minimax(board, false);
        board.getCells()[pos - 1] = ' '; // undo

        if (score > bestScore) {
            bestScore = score;
            bestMove = pos;
        }
    }
    return bestMove;
}

int AIPlayer::minimax(Board& board, bool isMaximizing) {
    char winner = board.getWinner();
    if (winner == mark) return 10;
    if (winner == opponentMark) return -10;
    if (board.isFull()) return 0;

    if (isMaximizing) {
        int best = std::numeric_limits<int>::min();
        for (int pos : board.getEmptyPositions()) {
            board.getCells()[pos - 1] = mark;
            best = std::max(best, minimax(board, false));
            board.getCells()[pos - 1] = ' ';
        }
        return best;
    } else {
        int best = std::numeric_limits<int>::max();
        for (int pos : board.getEmptyPositions()) {
            board.getCells()[pos - 1] = opponentMark;
            best = std::min(best, minimax(board, true));
            board.getCells()[pos - 1] = ' ';
        }
        return best;
    }
}
