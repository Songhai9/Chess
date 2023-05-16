#ifndef SQUARE_HPP
#define SQUARE_HPP

class Square {
private:
    int row;
    int col;

public:
    Square(int row, int col);

    int getRow() const;
    int getCol() const;
    void setRow(int row);
    void setCol(int col);
};

#endif // SQUARE_HPP
