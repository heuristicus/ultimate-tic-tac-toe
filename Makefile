CXXFLAGS=-Wall -Werror -O2
CXX=g++

all: game

game: game.h game.o square.o subBoard.o
	$(CXX) $(CXXFLAGS) -o $@ game.o square.o subBoard.o

game.o: game.h
	$(CXX) $(CXXFLAGS) -c game.cpp

square.o: game.h
	$(CXX) $(CXXFLAGS) -c square.cpp

subBoard.o: game.h
	$(CXX) $(CXXFLAGS) -c subBoard.cpp

clean:
	rm *.o game