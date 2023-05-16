#include "Square.hpp"

Square::Square(int row, int col) : row(row), col(col) {}

int Square::getRow() const {
    return 7 - row;
}

int Square::getCol() const {
    return col;
}

void Square::setRow(int row) {
    this->row = 7 - row;
}

void Square::setCol(int col) {
    this->col = col;
}
