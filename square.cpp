#include "game.h"

using namespace std;

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
