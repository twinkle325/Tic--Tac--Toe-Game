# Tic--Tac--Toe-Game


This is the classic Tic Tac Toe game (also called Noughts and Crosses), made to run in the terminal/console using C++. You can play against a friend, or play against the computer.

The computer player is really smart — it never loses. It thinks through every possible move before deciding, so at best you can only tie with it.

What this project can do
Play with a friend (two people take turns on the same computer)
Play against the computer (which plays perfectly every time)
Tells you if a move isn't allowed (like picking a spot that's already taken)
Lets you play as many rounds as you want without restarting
Easy to build and run on any computer (Windows, Mac, or Linux)
How the project is organized

Think of the code as three separate workers, each with one job:

Board – keeps track of the 3x3 grid and checks if someone has won
Player – represents whoever is playing, whether it's a real person typing in moves, or the computer figuring out its own move
Game – runs the whole show: asks what mode you want, keeps track of whose turn it is, and announces the winner
tic-tac-toe-cpp/
├── include/          (the "blueprints" for each part of the game)
├── src/              (the actual code that makes everything work)
├── CMakeLists.txt    (instructions for building the program)
├── LICENSE
└── README.md
How to run it on your computer

You'll need a C++ compiler installed (most computers used for coding already have one, called g++).

Easiest way:

bash
git clone https://github.com/<your-username>/tic-tac-toe-cpp.git
cd tic-tac-toe-cpp
g++ -std=c++17 -Iinclude src/main.cpp src/Board.cpp src/Player.cpp src/Game.cpp -o tictactoe
./tictactoe

That's it — the game will start in your terminal.

How to play
When you start the game, choose:
1 to play with a friend
2 to play against the computer
The board is numbered 1 to 9, like this:
    1 | 2 | 3
   ---+---+---
    4 | 5 | 6
   ---+---+---
    7 | 8 | 9
Type the number of the box you want to mark.
First to get 3 in a row (across, down, or diagonal) wins. If the board fills up with no winner, it's a tie.
After the game ends, it'll ask if you want to play again.
Why the computer never loses

The computer uses a method called Minimax. In simple terms, before making a move, it imagines every possible way the rest of the game could play out — including what you might do in response — and always picks the move that gives it the best possible result. Since Tic Tac Toe is a simple enough game, this means it can always at least force a tie, and it wins immediately if you make a mistake.

Ideas to make it even better (if you want to keep building on it)
Add an "easy mode" where the computer sometimes makes mistakes on purpose
Build a version with a proper graphical window instead of the terminal
Add automatic tests to double-check the game logic always works
