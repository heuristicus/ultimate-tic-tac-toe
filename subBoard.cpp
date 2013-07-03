#include "game.h"

using namespace std;

/*
 * Sets the state of the square at the specified index to the state passed to the function.
 * If the square is empty, the square is set to the state passed, and 0 is returned.
 * If the square is not empty, a non-zero value is returned.
 * The index should be between 0 and 8 inclusive
 */
int SubBoard::setSquare(int index, SquareState state)
{
    if (index < 0 || index >= 9){
	// Change this to throw an exception instead.
	cout << "Illegal SubBoard index: " << index << endl;
	exit(1);
    } else if (squares[index].getState() != empty) {
	// Use exceptions to indicate illegal moves.
	return -1;
    } else {
	squares[index].setState(state);
    }
    
    filledSquares++;
    return 0;
}

void SubBoard::printSquares()
{
    for (int i = 0; i < 9; ++i)
    {
	if (i%3 == 0 && i != 0)
	    cout << '\n';
	cout << squares[i].stateChar();
    }
    cout << endl;
}

/*
 * Checks whether the given sub-board is solved or not. Checks the 3 rows and columns, and the 2 diagonals
 * The check is only made if five or more squares are filled - only at this stage is a win possible.
 */
bool SubBoard::isSolved()
{
    if (filledSquares < 5){ // Only check if a player can have played 3 times
	return false;
    } else if (filledSquares == 9){
	// If all the squares are filled, then this subBoard is a draw.
	// Count this as a "solved" board.
	winner = empty;
	return true;
    }

    // bool all = true;
    // for (int i = 0; i < 9; ++i)
    // 	all = all && squares[i].getState() != empty;

    // if (all){
    // 	cout << "Board full" << endl;
    // 	winner = empty;
    // 	return true;
    // }

    return solveHelper(cross) || solveHelper(circle);
}

/*
 * Helper function for the isSolved() function. Does the checks for a specific squarestate/player.
 * Also sets the winner if there is one.
 */
bool SubBoard::solveHelper(SquareState s)
{
    // This is still quite horrible. Also put in checks for times where it is not possible for a board
    // to be solved, or if a solution is impossible (i.e. the board is a draw).
    // Also need to set who is the winner in here.
    bool solved = false;
    
    if (squares[0].getState() == s && squares[4].getState() == s && squares[8].getState() == s)
	solved = true;
    if (squares[2].getState() == s && squares[4].getState() == s && squares[6].getState() == s)
	solved = true;
    for (int i = 0; i < 3; ++i){
	if (squares[i].getState() == s && squares[i+3].getState() == s && squares[i+6].getState() == s){
	    solved = true;
	    break;
	}
    }
    
    for (int i = 0; i < 9; i += 3){
	if (squares[i].getState() == s && squares[i+1].getState() == s && squares[i+2].getState() == s){
	    solved = true;
	    break;
	}
    }
    
    if (solved)
	winner = s;

    return solved;
}
