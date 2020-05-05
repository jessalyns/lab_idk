CXX_FLAG = --std=c++11 -g -Wall

all: cards.o testcards game

cards.o: cards.cpp cards.h
	g++ $(CXX_FLAG) -c cards.cpp

testcards: testcards.cpp cards.o
	g++ $(CXX_FLAG) -o testcards testcards.cpp cards.o

game: main.cpp cards.o
	g++ $(CXX_FLAG) -o game main.cpp cards.o

clean:
	rm cards.o testcards game
