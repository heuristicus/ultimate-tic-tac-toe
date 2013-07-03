#include <iostream>
#include <exception>
#include <cstdlib>

#ifndef H_BOARD
#define H_BOARD

enum SquareState { empty, circle, cross };

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

class SubBoard
{
public:
    SubBoard(){ solved = false; filledSquares = 0; };
    virtual ~SubBoard(){};
    int setSquare(int index, SquareState state);
    char getSquare(int index);
    bool isSolved();
    void printSquares();
private:
    int filledSquares; // Number of non-empty squares
    Square squares[9]; // The state of each square on the board
    bool solved; // Is the board solved or not
    SquareState winner; // Indicates who won - empty is a draw.
};

class MainBoard
{
public:
    MainBoard(){};
    virtual ~MainBoard(){};
private:
    SubBoard subBoards[9];
};

#endif // H_BOARD
