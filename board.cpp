#include <iostream>
#include <exception>
#include <cstdlib>

using namespace std;

enum SquareState { empty, circle, cross };

SquareState turn = cross;

class Square
{
public:
    Square(SquareState state = empty){ this->state = state; };
    virtual ~Square(){};
    void setState(SquareState state){ this->state = state; };
    SquareState getState(){ return state; };
    char stateChar();
private:
    SquareState state;
};

char Square::stateChar()
{
    switch(state){
    case empty: return ' ';
    case circle: return 'O';
    case cross: return 'X';
	// Fix this to throw exception rather than just exit.
    default: cout << "Illegal state \"" << state << "\", terminating." << endl;
	exit(1);
    }
}

class SubBoard
{
public:
    SubBoard(){};
    virtual ~SubBoard(){};
    void setSquare(int index, SquareState state);
    char getSquare(int index);
    bool isSolved();
    char winner();
    void printSquares();
private:
    Square squares[9];
};

void SubBoard::setSquare(int index, SquareState state)
{
    if (index < 0 || index >= 9){
	cout << "Illegal SubBoard index: " << index << endl;
	exit(1);
    }
    squares[index].setState(state);
}

void SubBoard::printSquares()
{
    for (int i = 0; i < 9; ++i)
    {
	if((i+1)%3 == 0)
	    cout << '\n';
	cout << squares[i].stateChar();
    }
}

class MainBoard
{
public:
    MainBoard(){};
    virtual ~MainBoard(){};
private:
    SubBoard subBoards[9];
};

int main(int argc, char *argv[])
{
    SubBoard b;
    b.setSquare(0, cross);
    b.setSquare(3, circle);
    b.setSquare(5, circle);
    b.setSquare(7, circle);
    b.setSquare(4, cross);

    b.printSquares();

    return 0;
}
