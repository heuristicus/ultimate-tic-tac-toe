CXXFLAGS=-Wall -Werror -O2
CXX=g++

all: game

game: board.h game.o square.o subBoard.o
	$(CXX) $(CXXFLAGS) -o $@ game.o square.o subBoard.o

game.o: board.h
	$(CXX) $(CXXFLAGS) -c game.cpp

square.o: board.h
	$(CXX) $(CXXFLAGS) -c square.cpp

subBoard.o: board.h
	$(CXX) $(CXXFLAGS) -c subBoard.cpp	