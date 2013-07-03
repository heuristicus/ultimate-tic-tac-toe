#include "board.h"

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
 * Checks whether the given sub-board is solved or not.
 */
bool SubBoard::isSolved()
{
    if (filledSquares < 4)
    // This is too horrible. Find a better way to do it. Also put in checks for times where it is not possible for a board
    // to be solved, or if a solution is impossible (i.e. the board is a draw).
    // Also need to set who is the winner in here.
    for (int i = 0; i < 3; ++i)
	if ((squares[i].getState() == circle && squares[i+3].getState() == circle && squares[i+6].getState() == circle) ||
	    (squares[i].getState() == cross && squares[i+3].getState() == cross && squares[i+6].getState() == cross))
	    return true;
    for (int i = 0; i < 9; i += 3)
	if ((squares[i].getState() == circle && squares[i+1].getState() == circle && squares[i+2].getState() == circle) ||
	    (squares[i].getState() == cross && squares[i+1].getState() == cross && squares[i+2].getState() == cross))
	    return true;

    if ((squares[0].getState() == circle && squares[4].getState() == circle && squares[8].getState() == circle) ||
	(squares[0].getState() == cross && squares[4].getState() == cross && squares[8].getState() == cross))
	return true;
    if ((squares[2].getState() == circle && squares[4].getState() == circle && squares[6].getState() == circle) ||
	(squares[2].getState() == cross && squares[4].getState() == cross && squares[6].getState() == cross))
	return true;

    bool all = true;
    for (int i = 0; i < 9; ++i)
	all = all && squares[i].getState() != empty;

    if (all){
	cout << "Board full" << endl;
	return true;
    }

    return false;
}
