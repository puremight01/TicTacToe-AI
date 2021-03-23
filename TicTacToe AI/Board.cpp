#include "Board.h"

Board::Board()
{
	playerturn = 'X';
	//fills the board with space chars
	for (int YPos = 0; YPos < 3; YPos++)
	{
		for (int XPos = 0; XPos < 3; XPos++)
		{
			board[XPos][YPos] = ' ';
		}
	}
}

Board::Board(std::string input)
{
	playerturn = 'X';

	//this makes sure the string isn't to long and isn't empty
	for (int i = 0; input[i] != NULL and i<9; i++)
	{
		//this then puts the string into the correct position on the array 
		board[i%3][int(i/3)] = input[i];
		// test code
		//std::cout << "working" << std::endl;
	}
}

void Board::DisplayBoard()
{
	//prints out a small grid and chars
	std::cout << "------------" << std::endl;
	for (int YPos = 0; YPos < 3; YPos++)
	{
		for (int XPos = 0; XPos < 3; XPos++)
		{
			std::cout << ' ' << char(board[XPos][YPos]) << " |";
		}
		std::cout << std::endl << "------------" << std::endl;
	}
}

char Board::GameWon()
{
	//diagonal check for non ' ' Char
	if (board[0][0] == board[1][1] and board[0][0] == board[2][2] or board[2][0] == board[1][1] and board[2][0] == board[0][2] and board[1][1] != ' ')
	{
		return  board[1][1];
	}

	//vertical check for each column for non ' ' Char 
	for (int XPos = 0; XPos < 3; XPos++)
	{
		if (board[XPos][0] == board[XPos][1] and board[XPos][0] == board[XPos][2] and board[XPos][1] != ' ')
		{
			return board[XPos][1];
		}
	}

	//horizontal check for each row for non ' ' Char
	for (int YPos = 0; YPos < 3; YPos++)
	{
		if (board[0][YPos] == board[1][YPos] and board[0][YPos] == board[2][YPos] and board[1][YPos] != ' ')
		{
			return board[1][YPos];
		}
	}

	// default return if no winner is found
	return ' ';
}

bool Board::IsValid(int pos)
{
	//if board postion is empty 
	if (board[pos % 3][int(pos / 3)] == ' ')
	{
		PlacePiece(pos);
		return true;
	}
	return false;
}

std::string Board::AIStringOut()
{
	// creates a temp string and adds every board char to it 
	std::string tempstr = "";
	for (int YPos = 0; YPos < 3; YPos++)
	{
		for (int XPos = 0; XPos < 3; XPos++)
		{
			tempstr +=  char(board[XPos][YPos]);
		}
	}
	return tempstr;
}

char Board::GetPlayerTurn()
{
	return playerturn;
}

void Board::PlacePiece(int pos)
{
	//place the piece
	board[pos % 3][int(pos / 3)] = playerturn;
	//swap player turn
	playerturn = (playerturn == 'X') ? 'O' : 'X';
}
