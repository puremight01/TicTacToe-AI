#include<iostream>
#include"Board.h"
#include"Node.h"
#include"MiniMaxAI.h"
int main()
{
	int pos;
	Board *CurrentGame = new(Board);
	
	while (CurrentGame->GameWon() == ' ') {

		if (CurrentGame->GetPlayerTurn() == 'O') 
		{
			MiniMaxAI OurAI(CurrentGame, 9, CurrentGame->GetPlayerTurn());
			CurrentGame = new Board(OurAI.NextMove());
		}

		CurrentGame->DisplayBoard();
		do
		{
			std::cin >> pos;
		} while (!CurrentGame->IsValid(pos));
		system("CLS");
	}

	return 0;
}