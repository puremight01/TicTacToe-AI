#pragma once
#include<iostream>
#include<vector>
#include"Node.h"
#include"Board.h"
class MiniMaxAI
{
public:
	MiniMaxAI(Board *node, int depth, char maximizingPlayer);
	std::string NextMove();
	

private:
	Board *BestMove;
	int heuristicVal(Board curboard);
	Board *AIMax(Board* curboard, char player, int depth);
	Board *AIMin(Board* curboard, char player, int depth);

	
};

