#include <iostream>
using namespace std;

#include "src/Game.h"

int main(){
    Game* minesweeper = new Game(9, 9);
    minesweeper->fillSurroundedBombs();

    minesweeper->printField();

    string xString;
    string yString;
    while(true){
        cout << "Insert x\n";
        cin >> xString;
        if(!xString.compare("mode")){
            minesweeper->changeMode();
            continue;
        }
        cout << "Insert y\n";
        cin >> yString;
        if(!yString.compare("mode")){
            minesweeper->changeMode();
            continue;
        }
        int x = stoi(xString);
        int y = stoi(yString);
        cout << x << " + " << y << endl;
        //continue;
        x--; y--;

        if(!minesweeper->move(x, y)){
            //Game over
            minesweeper->printBombs();
            cout << "Game over" << endl;
            break;
        }
        minesweeper->clearEmptyFields();
        minesweeper->printField();
        if(minesweeper->testForWin()){
            cout << "Congratulations, you won!";
            break;
        }
    }
    cin.sync();
    cin.get();
    delete(minesweeper);

    return 0;
}
