#include "Field.h"

#include <iostream>
using namespace std;

#ifndef GAME_H
#define GAME_H

//#define X 9
//#define Y 9
//#define NUMBER_OF_BOMBS 30



class Game
{
    private:
        int x;
		int y;
		bool destroyBombs;
		Field* field[X][Y];
    public:
        Game(int xInput, int yInput);
        //Field* getField()[X][Y]{  return field;   }
        void printField();
		void printInBorders(int x, int y);
		bool inBorders(int x, int y);
		bool move(int x, int y);
		bool legal(int x, int y);
		bool isBomb(int x, int y);
		void fillSurroundedBombs();
		void printBombs();
		void clearEmptyFields();
		void turnAroundBomb(int x, int y);
		void changeMode();
		bool testForWin();
    protected:
};

#include "Field.h"

inline void Game::fillSurroundedBombs(){
    for(int yCount = 0; yCount < Y; yCount++){
        for(int xCount = 0; xCount < X; xCount++){
            field[xCount][yCount]->countSurroundingBombs(this);
        }
	}
}

#endif // GAME_H
