#pragma once
#include<vector>
#include<iostream>
#include"Board.h"
class Node
{

public:
	//the node board
	Board *self;
	//the children of the node board
	std::vector<Board*> branches;

	//constructor for this class takes a board and creates a std::vector with all of the posible children of that board
	Node(Board* Input, char player, int alpha, int beta);

	//Alpha Beta values
	int Alpha;
	int Beta;
private:
	//stuff
};

