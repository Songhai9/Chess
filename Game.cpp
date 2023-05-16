#include "Game.hpp"
#include <iostream>
#include <regex>

Game::Game() : currentPlayer(Color::WHITE) {}

void Game::start() {
    board.placePieces();
    board.display();

    std::string move;
    while (true) {
        // std::cout << "Player " << (currentPlayer == Color::WHITE ? "White" : "Black") << ", enter your move: ";
        std::getline(std::cin, move);

        if (move == "/quit") {
            displayGameResult("?-?");
            break;
        } else if (move == "/resign") {
            std::string result = (currentPlayer == Color::WHITE ? "0-1" : "1-0");
            displayGameResult(result);
            break;
        } else if (move == "/draw") {
            displayGameResult("1/2-1/2");
            break;
        } else if (isValidMove(move)) {
            if (makeMove(move)) {
                board.display();
                switchPlayer();
            }
        } else {
            std::cout << "Invalid move. Please try again." << std::endl;
        }
    }
}

void Game::displayGameResult(const std::string& result) {
    std::cout << board.displayResults() << " " << result << std::endl;
}

bool Game::isValidMove(const std::string& move) const {
    std::regex moveRegex("^[a-h][1-8][a-h][1-8]$");
    return std::regex_match(move, moveRegex);
}


bool Game::makeMove(const std::string& move) {
    int fromCol = move[0] - 'a';
    int fromRow = move[1] - '1';
    int toCol = move[2] - 'a';
    int toRow = move[3] - '1';

    Square from(fromRow, fromCol);
    Square to(toRow, toCol);

    Piece* piece = board.getPiece(from.getRow(), from.getCol());

    if (piece == nullptr) {
        std::cout << "There is no piece at the specified position." << std::endl;
        return false;
    }

    if (piece->getColor() != currentPlayer) {
        std::cout << "It's not your turn." << std::endl;
        return false;
    }

    if (!piece->isValidMove(to)) {
        std::cout << "Invalid move for the selected piece." << std::endl;
        return false;
    }

    board.movePiece(from, to);
    return true;
}


void Game::switchPlayer() {
    currentPlayer = (currentPlayer == Color::WHITE) ? Color::BLACK : Color::WHITE;
}