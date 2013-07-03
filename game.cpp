#include "board.h"

using namespace std;

SquareState turn = cross;

void nextTurn()
{
    switch(turn){
    case cross: turn = circle;
	break;
    case circle: turn = cross;
	break;
    default: cout << "Illegal turn state: " << turn << endl;
	exit(1);
    }
}

int getMove()
{
    int move;
    cout << "Enter your move as an integer between 0 and 8." << endl;
    cin >> move;
    return move;
}

int main(int argc, char *argv[])
{
    SubBoard b;
    cout << "You are playing Tic Tac Toe. Enter a number to place your token in that location. the board looks like this:" << endl;
    for (int i = 0; i < 9; ++i)
    {
	if (i%3 == 0 && i != 0)
	    cout << '\n';
	cout << i;
    }
    cout << endl;
    
    while(!b.isSolved()){
	b.printSquares();
	cout << "It is " << turn << "'s turn." << endl;
	if (b.setSquare(getMove(), turn) != 0){
	    cout << "Illegal move." << endl;
	    continue;
	}

	nextTurn();
    }

    cout << "Final result:" << endl;

    b.printSquares();

    return 0;
}
