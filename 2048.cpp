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
    std::vector<int> _b; // 1-16 spaces.
    std::string name;

public:
    Game(){}; // startup new game
    void board();
};

std::map<std::string, Game *> games;

void g_new(); // starts new game
void g_show_games();
void g_play();
void old_g_start(); // start old game
void board();

// main program

int main()
{
    char input;
    input = r_char("Whitch operation do you want to execute");
    while (input != 'Q')
    {
        switch (toupper(input))
        {
        case 'N':
            g_new();
            std::cout << "fuck";
            break;
        case 'S':
            g_show_games();
            break;
        case 'B':
            board();
            break;
        // funksjoner som skal lages
        default:
            std::cout << "\nRetard\n";
            break;
        }
        input = r_char("Whitch operation do you want to execute");
    }
    return 0;
}

// game func
/*
Game::Game(){
    for(int i = 0; i < 16; i++)
        board[i] = 0;

    return;
}
*/

// global funcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

void g_new()
{

    std::cout << "------------";
    Game *n_game;

    n_game = new Game();

    std::cout << "\n2";
    std::string name = r_string("The name for THIS game");
    // games.insert(std::pair <std::string, Game*> (name, n_game));    //fuc you

    delete n_game;
    std::cout << "\n3";

    return; // when quittig the game.
}

void g_show_games()
{ // Viser alle spilles
    if (!games.empty())
    {
        for (auto val : games)
        {
            std::cout << val.first << std::endl;
        }
    }
    else
        std::cout << "\nNo games started.";

    return;
}

void Game::board()
{
    std::cout << "- - - - - - - - - - - - - - - -";
    std::cout << "| " << _b[0] << " | " << _b[1] << " | " << _b[2] << " | " << _b[3] << " |";
}

void board(){       //finsished board, just need to insert the vector placements. 
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout  << "| " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " |" << endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout  << "| " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " |" << endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout  << "| " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " |" << endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
    std::cout  << "| " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " | " << std::setw(5) << "x" << " |" << endl;
    std::cout << "- - - - - - - - - - - - - - - - -" << std::endl;
}
