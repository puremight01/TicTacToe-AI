#include<iostream>
#include<conio.h>
#include<ctime>
#include"Board.h"
#include"Node.h"
#include"MiniMaxAI.h"

// will tell the player to press enter to return and then wait
void WaitForEnter()
{
	int MenuOp;
	std::cout << std::endl << "Press Enter to return." << std::endl;
	do
	{
		MenuOp = (int)_getch();
		//will only exit menu when enter is pressed
	} while (MenuOp != 13);
}

void PlayerVsPlayer()
{
	int pos;
	Board* CurrentGame = new(Board);

	while (CurrentGame->GameWon() == ' ' and !CurrentGame->BoardFull())
	{
		// Display the board 
		CurrentGame->DisplayBoard();
		// wait for the player to input a valid position 
		do
		{
			pos = (int)_getch() - 49;
		} while (!CurrentGame->IsValid(pos));
		//once a move had been made clear the old board
		system("CLS");
	}
	//tells the players who won the game
	if (CurrentGame->GameWon() != ' ') 
	{
		std::cout << CurrentGame->GameWon() << " Has Won!!!";
	}
	else
	{
		std::cout << "It is a Tie!!!";
	}
	//waits to return to main menu 
	WaitForEnter();
}

void PlayerVsRand()
{
	int pos;
	Board* CurrentGame = new(Board);

	while (CurrentGame->GameWon() == ' ' and !CurrentGame->BoardFull())
	{

		// Display the board 
		CurrentGame->DisplayBoard();

		// if it is the Ai's turn find a random blank square 
		if (CurrentGame->GetPlayerTurn() == 'O')
		{
			do {
				pos = rand() % 9;
			} while (!CurrentGame->IsValid(pos));
		}
		else
		{

			// wait for the player to input a valid position 
			do
			{
				pos = (int)_getch() - 49;
			} while (!CurrentGame->IsValid(pos));
		}
		//once a move had been made clear the old board
		system("CLS");
	}
	//tels the player who won the game
	if (CurrentGame->GameWon() != ' ')
	{
		std::cout << CurrentGame->GameWon() << " Has Won!!!";
	}
	else
	{
		std::cout << "It is a Tie!!!";
	}
	//waits to return to main menu 
	WaitForEnter();
}

void PlayerVsAI()
{
	int pos;
	Board* CurrentGame = new(Board);

	while (CurrentGame->GameWon() == ' ' and !CurrentGame->BoardFull()) {
		// Display the board 
		CurrentGame->DisplayBoard();

		// if it is the Ai's turn set our min and max alpha values and calculate the best move 
		if (CurrentGame->GetPlayerTurn() == 'O')
		{
			int MaxAlpha = -10;
			int MinAlpha = 10;
			MiniMaxAI OurAI(CurrentGame, 9, CurrentGame->GetPlayerTurn());
			CurrentGame = new Board(OurAI.NextMove());
		}
		else
		{
			// wait for the player to input a valid position 
			do
			{
				pos = (int)_getch() - 49;
			} while (!CurrentGame->IsValid(pos));
		}
		//once a move had been made clear the old board
		system("CLS");
	}
	//tells the player who won the game 
	if (CurrentGame->GameWon() != ' ')
	{
		std::cout << CurrentGame->GameWon() << " Has Won!!!";
	}
	else
	{
		std::cout << "It is a Tie!!!";
	}
	//waits to return to main menu 
	WaitForEnter();
}

void PlayMenu()
{
	system("CLS");
	int MenuOp;
	std::cout << "Tic-Tac-Toe" << std::endl;
	std::cout << "1) Player vs Player" << std::endl;
	std::cout << "2) Player vs Easy Ai" << std::endl;
	std::cout << "3) Player vs Hard Ai" << std::endl;
	do
	{
		//waits for the player to press one of the valid imputs before moving on
		MenuOp = (int)_getch() - 48;
	} while (MenuOp != 1 and MenuOp != 2 and MenuOp != 3);
	switch (MenuOp)
	{
	case 1:
		//clears the screen before starting a pvp game
		system("CLS");
		PlayerVsPlayer();
		break;
	case 2:
		//clears the screen before starting a pvrand game
		system("CLS");
		PlayerVsRand();
		break;
	case 3:
		//clears the screen before starting a pvAI game
		system("CLS");
		PlayerVsAI();
		break;
	}
}

void rules()
{
	system("CLS");
	std::cout << "Tic-Tac-Toe Rules" << std::endl;

	std::cout << "The aim of the game is to have 3 of your piece in a row." << std::endl;
	std::cout << "This can be done verticaly, diaginoaly or horisontaly." << std::endl;
	std::cout << "players take turns one after another to place a piece." << std::endl;
	std::cout << "The corresponding numbers match to a position on the board." << std::endl;

	//displays board with numbers in squares
	std::cout << "------------" << std::endl;
	for (int YPos = 0; YPos < 3; YPos++)
	{
		for (int XPos = 0; XPos < 3; XPos++)
		{
			std::cout << ' ' << YPos*3 +XPos+1 << " |";
		}
		std::cout << std::endl << "------------" << std::endl;
	}
	// wait till player is done to return 
	WaitForEnter();
}

void MainMenu()
{
	
	bool game = true;
	while (game == true) {
		system("CLS");
		int MenuOp;
		std::cout << "Tic-Tac-Toe" << std::endl;
		std::cout << "1) Play Game" << std::endl;
		std::cout << "2) Rules" << std::endl;
		std::cout << "3) Exit" << std::endl;
		do
		{
			//waits untill the player puts a valid imput
			MenuOp = (int)_getch() - 48;
		} while (MenuOp != 1 and MenuOp != 2 and MenuOp != 3);
		switch (MenuOp)
		{
		case 1:

			PlayMenu();
			//play game menu
			break;
		case 2:
			//rules menu
			rules();
			break;
		case 3:
			//ends the game loop
			game = false;
			break;
		}
	}
}



int main()
{
	srand(time(NULL));
	MainMenu();
	return 0;
}