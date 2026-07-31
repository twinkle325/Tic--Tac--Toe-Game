#include "Game.h"
#include <iostream>
#include <limits>

Game::Game() = default;

void Game::setup() {
    std::cout << "=== Tic Tac Toe ===\n";
    std::cout << "1. Player vs Player\n";
    std::cout << "2. Player vs AI\n";
    std::cout << "Choose a mode (1 or 2): ";

    int choice = 0;
    while (!(std::cin >> choice) || (choice != 1 && choice != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid choice. Enter 1 or 2: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 1) {
        player1 = std::make_unique<HumanPlayer>("Player 1", 'X');
        player2 = std::make_unique<HumanPlayer>("Player 2", 'O');
    } else {
        player1 = std::make_unique<HumanPlayer>("You", 'X');
        player2 = std::make_unique<AIPlayer>("Computer", 'O', 'X');
    }
}

void Game::playRound() {
    board.reset();
    Player* current = player1.get();

    while (!board.isGameOver()) {
        board.display();
        int move = current->getMove(board);
        board.placeMark(move, current->getMark());
        current = (current == player1.get()) ? player2.get() : player1.get();
    }

    board.display();
    char winner = board.getWinner();
    if (winner == ' ') {
        std::cout << "It's a draw!\n";
    } else {
        Player* winningPlayer = (winner == player1->getMark()) ? player1.get() : player2.get();
        std::cout << winningPlayer->getName() << " wins!\n";
    }
}

bool Game::askPlayAgain() {
    std::cout << "Play again? (y/n): ";
    std::string response;
    std::getline(std::cin, response);
    return !response.empty() && (response[0] == 'y' || response[0] == 'Y');
}

void Game::run() {
    setup();
    do {
        playRound();
    } while (askPlayAgain());

    std::cout << "Thanks for playing!\n";
}
