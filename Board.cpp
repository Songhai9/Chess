#include "Board.hpp"

Board::Board() {
    board = new Piece**[8];
    for (int i = 0; i < 8; i++) {
        board[i] = new Piece*[8];
        for (int j = 0; j < 8; j++) {
            board[i][j] = nullptr;
        }
    }
}

Board::~Board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete[] board;
}

Piece* Board::getPiece(int row, int col) {
    return board[7 - row][col];
}

void Board::placePieces() {
    // Placement des pièces blanches
    for (int i = 0; i < 8; i++) {
        board[6][i] = new Pawn(Color::BLACK, Square(6, i));
    }
    board[7][0] = new Rook(Color::BLACK, Square(7, 0));
    board[7][1] = new Knight(Color::BLACK, Square(7, 1));
    board[7][2] = new Bishop(Color::BLACK, Square(7, 2));
    board[7][3] = new Queen(Color::BLACK, Square(7, 3));
    board[7][4] = new King(Color::BLACK, Square(7, 4));
    board[7][5] = new Bishop(Color::BLACK, Square(7, 5));
    board[7][6] = new Knight(Color::BLACK, Square(7, 6));
    board[7][7] = new Rook(Color::BLACK, Square(7, 7));

    // Placement des pièces noires
    for (int i = 0; i < 8; i++) {
        board[1][i] = new Pawn(Color::WHITE, Square(1, i));
    }
    board[0][0] = new Rook(Color::WHITE, Square(0, 0));
    board[0][1] = new Knight(Color::WHITE, Square(0, 1));
    board[0][2] = new Bishop(Color::WHITE, Square(0, 2));
    board[0][3] = new Queen(Color::WHITE, Square(0, 3));
    board[0][4] = new King(Color::WHITE, Square(0, 4));
    board[0][5] = new Bishop(Color::WHITE, Square(0, 5));
    board[0][6] = new Knight(Color::WHITE, Square(0, 6));
	board[0][7] = new Rook(Color::WHITE, Square(0, 7));
}

void Board::movePiece(const Square& from, const Square& to) {
	Piece* piece = board[7 - from.getRow()][from.getCol()];
	if (piece == nullptr) {
		std::cout << "Il n'y a pas de pièce à déplacer à la position donnée." << std::endl;
		return;
	}

	if (piece->isValidMove(to)) {
		// Supprime la pièce à la destination si elle existe
		if (board[7 - to.getRow()][to.getCol()] != nullptr) {
			delete board[7 - to.getRow()][to.getCol()];
		}

		// Déplace la pièce
		board[7 - to.getRow()][to.getCol()] = piece;
		board[7 - from.getRow()][from.getCol()] = nullptr;

		// Met à jour la position de la pièce
		piece->setPosition(to);
	}
	else {
		std::cout << "Ce mouvement est invalide pour cette pièce." << std::endl;
	}
}

void Board::display() const {
	std::cout << "    a     b     c     d     e     f     g     h" << std::endl;
	std::cout << " +-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;

	for (int i = 7; i >= 0; --i) { // Inverser la numérotation des lignes
		for (int j = 0; j < 8; ++j) {
			if (j == 0) {
				std::cout << " | ";
			}
			if (board[i][j] == nullptr) {
				std::cout << "     | ";
			}
			else {
				std::cout << " " << board[i][j]->toString() << " | ";
			}
		}
		std::cout << std::endl;
		std::cout << " +-----+-----+-----+-----+-----+-----+-----+-----+" << std::endl;
	}
}

std::string Board::displayResults() const {
    std::string result = "";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != nullptr) {
                result += board[i][j]->getColor() == Color::WHITE ? "w" : "b";
                if (board[i][j]->getName() == "\u2659") {
                    result += "P";
                } else if (board[i][j]->getName() == "\u2654") {
                    result += "K";
                } else if (board[i][j]->getName() == "\u2655") {
                    result += "Q";
                } else if (board[i][j]->getName() == "\u2657") {
                    result += "B";
                } else if (board[i][j]->getName() == "\u2658") {
                    result += "N";
                } else if (board[i][j]->getName() == "\u2656") {
                    result += "R";
                }
            }
            result += ",";
        }
    }
    return result;
}