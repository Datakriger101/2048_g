#include <iomanip>
#include <iostream>
#include "E_func.h"     // Homemade
#include <vector>

/*
    Class
*/

class Game{
    private:
        int board[16];    //b for board
        std::string name;

    public:
        //void readFile();
        void reset();
        void displayName();
        void displayBoard();
        void playGame();

};

/*
    Decalation of Functions
*/

void menu();
void new_game();
void play_game();
void show_games();

std::vector <Game*> gGames;

int main(){
    char input;

    // check from the files

    menu();
    input = r_char("What operation do you want to execute");

    while(input != 'Q'){
        std::cout << "\n" << input << "\n";
        switch(input){
            case 'N' : new_game();      break;
            case 'P' : play_game();     break;
            case 'S' : show_games();    break;
        }

        menu();
        std::cout << "\ncheck2" << std::endl;
        input = r_char("What operation do you want to execute");
    }
}

void Game::reset(){
    this->name = r_string("What is the name of the game");
    
    for(int i = 0; i < 16; i++){
        board[i] = 0;
    }
}

void Game::displayName(){
    std::cout << this->name;
}

void Game::displayBoard(){
    for(int i = 0; i < 16; i++){
        std::cout << board[i] << " ";
        if(i % 3 == 0) std::cout << "\n";
    }
}

void Game::playGame(){
    displayBoard();
}

/*
    Functions, main
*/

void new_game(){

    std::cout << "\nhey\n" << std::endl;
    Game *temp = new Game();

    std::cout << "\ncheck 1" << std::endl;

    temp->reset();
    gGames.push_back(temp);

}

void play_game(){
    int nr;
    if(!gGames.empty()){
        show_games();
        nr = r_int_bet("Whitch game do you want to play", 0, gGames.size());
        if(nr){
            gGames[nr]->playGame();
        }else
            std::cout << "\nNo games will be played!" << std::endl;

    }else
        std::cout << "No games to play" << std::endl;
}

// Maybe unnecessary
void show_games(){
    if(!gGames.empty()){
        for(int i = 0; i < gGames.size(); i++){
            std::cout << "\n" << i+1 << ". "; gGames[i]->displayName();   
        }
    }else
        std::cout << "\nNo games to show" << std::endl;
}

void menu(){
    std::cout << "\nPossble operations:\n";
    std::cout << "\n\tN - new game";
    std::cout << "\n\tS - show running games";
    std::cout << "\n\tB - show board";
    std::cout << "\n\tP - play existing game";
    std::cout << "\n\t";
    std::cout << "\n\t";
}