#include "Game.h"
#include <stdio.h>
#include <time.h>

Game::Game(int xInput, int yInput){
    x = xInput;
	y = xInput;
    destroyBombs = true;
	for(int yCount = 0; yCount < y; yCount++){
		for(int xCount = 0; xCount < x; xCount++){
			field[xCount][yCount] = new Field(xCount, yCount);
		}
	}
	for(int i = 0; i < NUMBER_OF_BOMBS; i++){

		srand(time(NULL));

		int chosedX = rand() % X;
		int chosedY = rand() % Y;
		if(!field[chosedX][chosedY]->bombHere()){
            cout << "(" << chosedX << "|" << chosedY << ")\n";
            field[chosedX][chosedY]->setBomb();
		}else{
            i--;
        }
	}
}


void  Game::printField(){
	cout << " |";
	for(x = 0; x < X; x++){
		cout << (x + 1) << "|";
	}
	cout << endl;
	for(int y = 0; y < Y; y++){
		cout << (y + 1);
		for(int x = 0; x < X; x++){
			cout << "|" << field[x][y]->giveSymbol();
		}
		cout << "|\n";
	}
}

void Game::printInBorders(int x, int y){
	if(x < 0)	cout << "x-Coordinate too small\n";
	if(y < 0)	cout << "y-Coordinate too small\n";
	if(x >= X)	cout << "x-coordinate too big\n";
	if(y >= Y)	cout << "y-coordinate too big\n";
}
bool Game::inBorders(int x, int y){
	return (x >= 0 && y >= 0 && x < X && y < Y);
}
bool Game::legal(int x, int y){
	return inBorders(x, y) && field[x][y]->changeable();
}

void Game::turnAroundBomb(int x, int y){
    field[x][y]->flip();
}

bool Game::move(int x, int y){

	printInBorders(x, y);
	if(inBorders(x, y)){
        field[x][y]->printNotChangeable();
		if(legal(x, y)){

			if(destroyBombs){
                return field[x][y]->flip();
			}else{
                field[x][y]->toggleFlag();
                return true;
			}
		}
	}
	return true;
}

bool Game::isBomb(int x, int y){
    return field[x][y]->bombHere();
}
void Game::changeMode(){
    destroyBombs = !destroyBombs;
    if(destroyBombs){
        cout << "Destroying bombs now\n";
    }else{
        cout << "Setting flags now\n";
    }
}

void Game::printBombs(){

    cout << " |";
	for(x = 0; x < X; x++){
		cout << (x + 1) << "|";
	}
	cout << endl;
	for(int y = 0; y < Y; y++){
		cout << (y + 1);
		for(int x = 0; x < X; x++){
			cout << "|";
			if(field[x][y]->bombHere()){
                cout << "B";
			}else{
                cout << "_";
			}
		}
		cout << "|\n";
	}

}

void Game::clearEmptyFields(){
    bool test;
    while(true){
        test = false;
        for(int y = 0; y < Y; y++){
            for(int x = 0; x < X; x++){
                if(field[x][y]->unhideHidden(this))    test = true;
            }
        }
        if(!test) break;
    }
}


bool Game::testForWin(){
    for(int y = 0; y < Y; y++){
        for(int x = 0; x < X; x++){
            if(!field[x][y]->bombHere() && field[x][y]->changeable())   return false;
        }
    }
    return true;
}



