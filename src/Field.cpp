#include "Field.h"

Field::Field(int xInput, int yInput)
{
    this->x = xInput;
	this->y = yInput;
	bomb = false;
	hidden = true;
	flag = false;
	bombsAround = 0;
}

void Field::setBomb(){		bomb = true;	}
bool Field::bombHere(){	return bomb;	}


bool Field::unhideHidden(Game* minesweeper){

    if(hidden || bombsAround > 0)   return false;

    bool turnedSthAround = false;
    for(int yCount = y - 1; yCount <= y + 1; yCount++){
        for(int xCount = x - 1; xCount <= x + 1; xCount++){
            if(minesweeper->legal(xCount, yCount)){
                minesweeper->turnAroundBomb(xCount, yCount);
                turnedSthAround = true;
            }
        }
    }
    return turnedSthAround;
}

bool Field::flip(){
		hidden = false;
		if(bomb){
			return false;
		}
		return true;
}

void Field::toggleFlag(){
    if(!hidden) return;
    flag = !flag;
}

string Field::giveSymbol(){
	if(hidden){
		if(flag) return "F";
		return "X";
	}
	if(!bomb){
        if(bombsAround == 0)return "_";
        return to_string(bombsAround);
	}
	return "B";
}

bool Field::changeable(){
	if(hidden) return true;
    return false;
}

void Field::printNotChangeable(){
	if(!hidden)	cout << "The field (" << x << "|" << y << ") is not turnable right now\n";
}


