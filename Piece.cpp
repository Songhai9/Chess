#include "Piece.hpp"



Piece::Piece(std::string name, Color color, Square position)
	: name(name), color(color), position(position) {}

std::string Piece::getName() const {
	return name;
}

Color Piece::getColor() const {
	return color;
}

Square Piece::getPosition() const {
	return position;
}

void Piece::setPosition(const Square& newPosition) {
	position = newPosition;
}

std::string Piece::toString() const {
	return name;
}



Pawn::Pawn(Color color, Square position)
	: Piece("\u2659", color, position), hasMoved(false) {}

bool Pawn::isValidMove(const Square& destination) const {
	int rowDiff = destination.getRow() - position.getRow();
	int colDiff = std::abs(destination.getCol() - position.getCol());
	if (color == Color::WHITE) {
		if (rowDiff == 1 && colDiff == 0) {
			return true;
		}
		else if (rowDiff == 2 && colDiff == 0 && !hasMoved) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (rowDiff == -1 && colDiff == 0) {
			return true;
		}
		else if (rowDiff == -2 && colDiff == 0 && !hasMoved) {
			return true;
		}
		else {
			return false;
		}
	}
}



King::King(Color color, Square position)
	: Piece("\u2654", color, position) {}

bool King::isValidMove(const Square& destination) const {
	int rowDiff = std::abs(position.getRow() - destination.getRow());
	int colDiff = std::abs(position.getCol() - destination.getCol());
	return (rowDiff <= 1 && colDiff <= 1);
}



Queen::Queen(Color color, Square position)
	: Piece("\u2655", color, position) {}

bool Queen::isValidMove(const Square& destination) const {
	int rowDiff = std::abs(position.getRow() - destination.getRow());
	int colDiff = std::abs(position.getCol() - destination.getCol());
	return (rowDiff == colDiff) || (position.getRow() == destination.getRow()) || (position.getCol() == destination.getCol());
}



Bishop::Bishop(Color color, Square position)
	: Piece("\u2657", color, position) {}

bool Bishop::isValidMove(const Square& destination) const {
	int rowDiff = std::abs(position.getRow() - destination.getRow());
	int colDiff = std::abs(position.getCol() - destination.getCol());
	return (rowDiff == colDiff);
}



Knight::Knight(Color color, Square position)
	: Piece("\u2658", color, position) {}

bool Knight::isValidMove(const Square& destination) const {
	int rowDiff = std::abs(position.getRow() - destination.getRow());
	int colDiff = std::abs(position.getCol() - destination.getCol());
	return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);
}


Rook::Rook(Color color, Square position)
	: Piece("\u2656", color, position) {}

bool Rook::isValidMove(const Square& destination) const {
	return (position.getRow() == destination.getRow()) || (position.getCol() == destination.getCol());
}