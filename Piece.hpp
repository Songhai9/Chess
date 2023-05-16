#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>
#include "Square.hpp"

enum class Color {
    BLACK,  /**< Couleur noire */
    WHITE /**< Couleur blanche */
};


class Piece {
protected:
    std::string name;     /**< Nom de la pièce */
    Color color;          /**< Couleur de la pièce */
    Square position;      /**< Position de la pièce sur l'échiquier */

public:

    Piece(std::string name, Color color, Square position);

    std::string getName() const;


    Color getColor() const;

    Square getPosition() const;

    void setPosition(const Square& newPosition);


    virtual std::string toString() const;

    virtual bool isValidMove(const Square& destination) const = 0;
};

class Pawn : public Piece {
private:
    bool hasMoved; /**< Indique si le pion a déjà été déplacé */

public:
    Pawn(Color color, Square position);

    bool isValidMove(const Square& destination) const override;
};


class King : public Piece {
public:
    King(Color color, Square position);

    bool isValidMove(const Square& destination) const override;
};

class Queen : public Piece {
public:
    Queen(Color color, Square position);

    bool isValidMove(const Square& destination) const override;
};


class Bishop : public Piece {
public:
    Bishop(Color color, Square position);

    bool isValidMove(const Square& destination) const override;
};


class Knight : public Piece {
public:

    Knight(Color color, Square position);

    bool isValidMove(const Square& destination) const override;
};


class Rook : public Piece {
public:

    Rook(Color color, Square position);

    bool isValidMove(const Square& destination) const override;
};

#endif // PIECE_HPP