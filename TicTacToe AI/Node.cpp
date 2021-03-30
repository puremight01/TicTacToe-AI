#include "Node.h"

Node::Node(Board *Input, char player, int alpha, int beta)
{
	Alpha = alpha;
	Beta = beta;
	self = Input;
	//loop through every character in the board code
	for (std::string::size_type i = 0; i < self->AIStringOut().size(); i++)
	{
		if (self->AIStringOut()[i] == ' ')
		{
			//make a new string to hold new code
			std::string Code;
			for (std::string::size_type j = 0; j < self->AIStringOut().size(); j++)
			{
				//this makes the new board code with the changed char that was originaly blank
				if (i != j)
				{
					Code += self->AIStringOut()[j];
				}
				else
				{
					Code += player;
				}
			}
			branches.push_back(new Board(Code));
			//make a board with the char changed an adds it to the list 
		}
		
	}
}
