#include "MiniMaxAI.h"


MiniMaxAI::MiniMaxAI(Board *node, int depth, char maximizingPlayer)
{
    
   BestMove = AIMax(node, maximizingPlayer, depth, -10, 10);
}



std::string MiniMaxAI::NextMove()
{
    return BestMove->AIStringOut();
}

int MiniMaxAI::heuristicVal(Board curboard)
{
    if (curboard.GameWon() == ' ')
    { 
        return 0;
    }
    else if (curboard.GameWon() == 'X')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


Board* MiniMaxAI::AIMax(Board* curboard, char player, int depth, int alpha, int beta)
{
    Node MaxNode(curboard, player,alpha, beta);
    
    std::string CurrentMaxBoard;
    if (curboard->AIStringOut().find(' ') == std::string::npos)
    {
        curboard->Hval = 0;
        return curboard;
    }
    int MaxHVal = -2;
    for (auto i = MaxNode.branches.begin();i!=MaxNode.branches.end();i++)
    {
        auto z = *i;
        if (z->GameWon() != ' ')
        {
            z->Hval = 1;
            return z;
            //do this move cos this is a win 
        }
        else if(depth > 0)
        {
            //create a holder for the min Board returned
            Board* BHolder;

            //find the min for the next turn
            if (player == 'X')
            {
                
                BHolder = AIMin(z, 'O', depth - 1, MaxNode.Beta, MaxNode.Alpha);
            }
            else
            {
                BHolder = AIMin(z, 'X', depth - 1, MaxNode.Beta, MaxNode.Alpha);
            }


            //if the new board has a better huristic value than the old best change it 
            if (BHolder->Hval > MaxHVal)
            {
                MaxHVal = BHolder->Hval;
                CurrentMaxBoard = z->AIStringOut();
            }
            //can choose random if they are the same
        }

        //calculate hurisics for each child and return the max value
        else
        {
            if (heuristicVal(*z) > MaxHVal)
            {
                MaxHVal = heuristicVal(*z);
                CurrentMaxBoard = z->AIStringOut();
            }
            //can choose random if they are the same
        }

        //copy alpha
        if (MaxNode.Alpha < MaxHVal)
        {
            MaxNode.Alpha = MaxHVal;
        }

        // pruning 
        if (PruneMax(MaxHVal,MaxNode.Beta))
        {
            Board* output = new Board(CurrentMaxBoard);
            output->Hval = MaxHVal;
            return output;
        }
    }
    Board *output = new Board(CurrentMaxBoard);
    output->Hval = MaxHVal;
    return output;
}

Board *MiniMaxAI::AIMin(Board* curboard, char player, int depth, int alpha, int beta)
{
    Node MinNode(curboard, player, alpha, beta);
    std::string CurrentMinBoard;
    int MinHVal = 2;
    for (auto i = MinNode.branches.begin(); i != MinNode.branches.end(); i++)
    {
        auto z = *i;

        //winning board
        if (z->GameWon() != ' ')
        {
            z->Hval = -1;
            return z;
            //do this move cos this is a win 
        }

        //branch 
        else if (depth > 0)
        {
            //create a holder for the min Board returned
            Board* BHolder;

            //find the min for the next turn
            if (player == 'X')
            {

                BHolder = AIMax(z, 'O', depth - 1, MinNode.Beta, MinNode.Alpha);
            }
            else
            {
                BHolder = AIMax(z, 'X', depth - 1, MinNode.Beta, MinNode.Alpha);
            }


            //if the new board has a better huristic value than the old best change it 
            if (BHolder->Hval < MinHVal)
            {
                MinHVal = BHolder->Hval;
                CurrentMinBoard = z->AIStringOut();
            }
            //can choose random if they are the same
        }

        //calculate hurisics for each child and return the max value
        else
        {
            if (heuristicVal(*z) < MinHVal)
            {
                MinHVal = heuristicVal(*z);
                CurrentMinBoard = z->AIStringOut();
            }
            //can choose random if they are the same
        }

        //copy alpha
        if (MinNode.Alpha > MinHVal)
        {
            MinNode.Alpha = MinHVal;
        }

        // pruning 
        if (PruneMin(MinHVal, MinNode.Beta))
        {
            Board* output = new Board(CurrentMinBoard);
            output->Hval = MinHVal;
            return output;
        }

    }
    Board *output= new Board(CurrentMinBoard);
    output->Hval = MinHVal;
    return output;
}

bool MiniMaxAI::PruneMax(int childalpha, int parentbeta)
{
    
    if (childalpha >= parentbeta)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MiniMaxAI::PruneMin(int childalpha, int parentbeta)
{
    if (childalpha <= parentbeta)
    {
        return true;
    }
    else
    {
        return false;
    }
}
