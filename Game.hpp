#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"

class Game {
private:
    Board board; /**< Plateau de jeu */
    Color currentPlayer; /**< Joueur courant */

public:
    Game();

    void start();

private:
    void displayGameResult(const std::string& result);

    bool isValidMove(const std::string& move) const;

    bool makeMove(const std::string& move);

    void switchPlayer();
};

#endif // GAME_HPP