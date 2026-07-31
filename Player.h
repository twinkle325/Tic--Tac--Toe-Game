#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <string>

class Player {
public:
    Player(std::string name, char mark) : name(std::move(name)), mark(mark) {}
    virtual ~Player() = default;

    virtual int getMove(Board& board) = 0;
    const std::string& getName() const { return name; }
    char getMark() const { return mark; }

protected:
    std::string name;
    char mark;
};

class HumanPlayer : public Player {
public:
    HumanPlayer(const std::string& name, char mark) : Player(name, mark) {}
    int getMove(Board& board) override;
};

class AIPlayer : public Player {
public:
    AIPlayer(const std::string& name, char mark, char opponentMark)
        : Player(name, mark), opponentMark(opponentMark) {}
    int getMove(Board& board) override;

private:
    char opponentMark;
    int minimax(Board& board, bool isMaximizing);
};

#endif // PLAYER_H
