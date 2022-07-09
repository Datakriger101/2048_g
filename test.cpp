/*
 *  Lager spillet 024, ,,8
 *
 */

#include <iostream>
#include "E_func.h"
#include <vector>
#include <map>
using namespace std;

//functions

class Game{    
    private:
        std::vector <int> board; // 1-16 spaces.

    public:
        Game();      //startup new game
};

std::map <std::string, Game*> games;

// main program

int main(){

    new Game();

    return 0;
}

//game func


    Game::Game(){
        for(int i = 0; i < 16; i++)
            board[i] = 0;

        return;
    }
