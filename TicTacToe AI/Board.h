#pragma once
#include<iostream>
class Board
{

public:
	//default construtor
	Board();

	//constructor with board components
	Board(std::string input);

	//displays the board on the console window
	void DisplayBoard();

	//checks the board to see if anyone has 3 in a row returns either X, O or ' '
	char GameWon();

	//checks if the players move is valid at the position specified
	bool IsValid(int pos);

	//outputs the string code for the AI
	std::string AIStringOut();

	//a container that the AI uses to share huristic values to each other
	int Hval;

	//a way for the ai to get the current player turn 
	char GetPlayerTurn();

	// checks if the board if 
	bool BoardFull();


private:

	//plays the piece into the square and changes player 
	void PlacePiece(int pos);

	// char array to store the data in the board
	char board[3][3];

	//stores what players turn it is
	char playerturn;

};

