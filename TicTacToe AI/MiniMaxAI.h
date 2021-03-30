#pragma once
#include<iostream>
#include<vector>
#include"Node.h"
#include"Board.h"
class MiniMaxAI
{
public:
	//constructs the ai and triggers the AIMinMax 
	MiniMaxAI(Board *node, int depth, char maximizingPlayer);

	//outputs the Board String
	std::string NextMove();
	

private:
	//Board pointer for the current best move
	Board *BestMove;

	//Alpha Beta values
	int Alpha;
	int Beta;

	//gives a node its huristic value
	int heuristicVal(Board curboard);

	// finds the max board of the current position 
	Board *AIMax(Board* curboard, char player, int depth, int alpha, int beta);

	// finds the min board of the current poistion
	Board *AIMin(Board* curboard, char player, int depth, int alpha, int beta);

	// Returns true if the current maximiser needs to be pruned
	bool PruneMax(int childalpha, int parentbeta);

	// Returns false if the current maximiser needs to be pruned
	bool PruneMin(int childalpha, int parentbeta);

	
};

