#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <string>
#include <regex>
#include "Piece.hpp"

class Board {
private:
    Piece*** board; /**< Tableau à deux dimensions représentant l'échiquier */

public:

    Board();

    ~Board();

 
    Piece* getPiece(int row, int col);

    void placePieces();

  
    void movePiece(const Square& from, const Square& to);

    void display() const;

    std::string displayResults() const;
};

#endif // BOARD_HPP