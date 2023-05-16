CC = g++
CFLAGS = -std=c++11

all: echecs

echecs: main.o Game.o Board.o Piece.o Square.o
	$(CC) $(CFLAGS) main.o Game.o Board.o Piece.o Square.o -o echecs

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Game.o: Game.cpp Game.hpp
	$(CC) $(CFLAGS) -c Game.cpp

Board.o: Board.cpp Board.hpp
	$(CC) $(CFLAGS) -c Board.cpp

Piece.o: Piece.cpp Piece.hpp
	$(CC) $(CFLAGS) -c Piece.cpp

Square.o: Square.cpp Square.hpp
	$(CC) $(CFLAGS) -c Square.cpp

clean:
	rm -rf *.o echecs
