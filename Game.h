#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include <memory>

class Game {
public:
    Game();
    void run();

private:
    Board board;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;

    void setup();
    void playRound();
    bool askPlayAgain();
};

#endif // GAME_H
