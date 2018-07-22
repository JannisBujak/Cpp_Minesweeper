
#ifndef FIELD_H
#define FIELD_H

#define X 9
#define Y 9
#define NUMBER_OF_BOMBS 10


#include <iostream>
using namespace std;

class Game;
class Field
{
    private:
        bool bomb;
		bool hidden;
		bool flag;
		int x;
		int y;
		int bombsAround;
    public:
        Field(int xInput, int yInput);
        bool unhideHidden(Game* minesweeper);
        void setBomb();
		bool bombHere();
		bool flip();
		string giveSymbol();
		bool changeable();
		void printNotChangeable();
        void countSurroundingBombs(Game* minesweeper);
        void toggleFlag();
    protected:
};

#include "Game.h"

inline void Field::countSurroundingBombs(Game* minesweeper){
	for(int yCount = y - 1; yCount <= y + 1; yCount++){
		for(int xCount = x - 1; xCount <= x + 1; xCount++){

            if(minesweeper->inBorders(xCount, yCount)){
                if(minesweeper->isBomb(xCount, yCount))   bombsAround++;
            }

		}
	}
}

#endif // FIELD_H
