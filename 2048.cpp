#include <iomanip>
#include <iostream>
#include "E_func.h"     // Homemade
#include <vector>

/*
    Class
*/

class Game{
    private:
        std::vector <int> b;
        std::string name;

    public:
        //void readFile();
        void startup();
        void displayName();
        void displayBoard();
        void playGame();

        Game();

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

Game::Game(){

    this->name = r_string("What is the name of the game");
    for(int i = 0; i < 16; i++){
        b.push_back(0);
    }
}

void Game::startup(){   //in use??

}

void Game::playGame(){
    
    displayBoard();
}

void Game::displayBoard(){
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "| " << std::setw(5) << b[0] << " | " << std::setw(5) << b[1] << " | " << std::setw(5) << b[2] << " | " << std::setw(5) << b[3] << " |" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "| " << std::setw(5) << b[4] << " | " << std::setw(5) << b[5] << " | " << std::setw(5) << b[6] << " | " << std::setw(5) << b[7] << " |" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "| " << std::setw(5) << b[8] << " | " << std::setw(5) << b[9] << " | " << std::setw(5) << b[10] << " | " << std::setw(5) << b[11] << " |" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout << "| " << std::setw(5) << b[12] << " | " << std::setw(5) << b[13] << " | " << std::setw(5) << b[14] << " | " << std::setw(5) << b[15] << " |" << std::endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
}

/*
void Game::n_displayBoard(){

}
*/



void Game::displayName(){
    std::cout << this->name;
}

/*
    Functions, main
*/

void new_game(){

    std::cout << "\nhey\n" << std::endl;
    Game *new_G = new Game();

    std::cout << "\ncheck 1" << std::endl;

    //temp->startup();
    gGames.push_back(new_G);

}

void play_game(){
    int nr;
    if(!gGames.empty()){
        show_games();
        nr = r_int_bet("Whitch game do you want to play", 0, gGames.size());
        if(nr){
            gGames[nr-1]->playGame();
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