/*
 *  Lager spillet 024, ,,8
 *
 */

#include <iostream>
#include <iomanip>
#include "E_func.h"
#include <vector>
#include <map>
using namespace std;

// functions

class Game
{
private:
    int _b[16];
    std::string name;
    bool started;

public: 
    Game(); // startup new game, vil legge til nullstilling av spillbrett, får bare segmenation shit
    void board();   //skal brukes hver gang
    void play();
    bool checkStart();
    void gameStart(bool change);
    void set_zero();
};

std::map<std::string, Game *> games;

void g_new(); // starts new game
void g_show_games();
void g_play_game();
void old_g_start(); // start old game
void board();
void menu();

// main program

int main()
{
    char input;
    menu();
    input = r_char("Whitch operation do you want to execute");

    while (input != 'Q')
    {
        switch (toupper(input))
        {
        case 'N':
            g_new();            break;

        case 'S':
            g_show_games();     break;

        case 'B':
            board();            break;

        case 'P':
            g_play_game();      break;

        default:    //actually u retarded, du ser fuckings menyen.
            break;
        }
        menu();
        input = r_char("Whitch operation do you want to execute");
    }
    return 0;
}

// game func

Game::Game(){
    started = true;
}

bool Game::checkStart(){
    return started;
}

void Game::play(){
    for(int i = 0; i < 2; i++)
        Game::board();
}

void Game::set_zero(){  // not work
    _b[0] = 0, _b[1] = 1, _b[2] = 3;
}

// global funcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

void g_new()
{

    Game *n_game;

    n_game = new Game();

    std::string name = r_string("The name for THIS game");

    n_game->set_zero();     //  notwork

    games.insert(std::pair <std::string, Game*> (name, n_game));    //fuc you

    delete n_game;

    return; // when quittig the game.
}

void g_show_games()
{ // Viser alle spilles
    int i = 1;
    if (!games.empty())
    {
        for (const auto & val : games)
        {
            std::cout << i++ << ". " << val.first << std::endl;
        }
    }

    else
        std::cout << "\nNo games started.";
}

void g_play_game(){
    bool input;

    if(!games.empty()){
        g_show_games();

        std::string name= r_string("Which game do you want to run: ");
        for(auto & val : games){

            if(name == val.first){
                val.second->play();
                    
            }else
                std::cout << "\nNo games with that name";
        }
    }else
        std::cout << "\nNo games have started.";
}


void Game::board()
{
    std::cout << "- - - - - - - - - - - - - - - -";
    std::cout << "| " << _b[0] << " | " << _b[1] << " | " << _b[2] << " | " << _b[3] << " |";
    //more
}

void board(){       //finsished board, just need to insert the vector placements. 
    std::cout << "- - - - - - - - - - - - - - - - -, Dette er bare en visuell" << std::endl;
    std::cout  << "| " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " |" << endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout  << "| " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " |" << endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout  << "| " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " |" << endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout  << "| " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " |" << endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
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
