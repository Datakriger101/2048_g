/*
 * This is the first version of the kinda finished game, v1 if you want. 
 * This may very well be exploited #CTF
 */

#include <iomanip>
#include <iostream>
#include "E_func.h"     // Homemade
//#include "moveFunc2028.h"   // Declaration, maybe later for better overview.
#include <vector>
#include <cstdlib>      // for rand() func
#include <fstream>      // File access shit

/*
    Class
*/

class Game
{
    private:
        std::vector<int> b;
        std::string name;
        bool lost;

    public:
        // void readFile();
        void startup();
        void displayName();
        void displayLoss();
        void displayBoard();
        void playGame();

        void moveMenu();
        int newRandNumber();
        void removeNumber(int nr);

        bool checkValidChar(char t);
        bool checkLoss();
        bool checkNoMoves(int nr0, int nr1, int nr2, int nr3);

        //Better way to do this?
        bool moveUp();
        bool moveLeft();
        bool moveDown();
        bool moveRight();

        bool move(int nr0, int nr1, int nr2, int nr3);

        void toFile(std::ofstream & out);

        Game(); //constructor to make to board
        Game(std::ifstream & in);
};

/*
    Decalation of Functions
*/

void menu();
void new_game();
void play_game();
void show_games();

void writeToFile();
void readFromFile();

std::vector<Game *> gGames;

/*
 *  The Game
 */

int main()
{
    char input;

    readFromFile();

    menu();
    input = r_char("What operation do you want to execute");

    while (input != 'Q')
    {
        switch (input)
        {
        case 'N' : new_game();      break;
        case 'P' : play_game();     break;
        case 'S' : show_games();    break;
        }

        menu();

        input = r_char("What operation do you want to execute");
    }

    writeToFile();
}

Game::Game()
{
    this->name = r_string("What is the name of the game");
    this->lost = false;

    for (int i = 0; i < 16; i++) b.push_back(0);
    
}

Game::Game(std::ifstream & in)
{
    int numb;

    in >> numb;
    (numb == 1) ? lost = true : lost = false;

    for(int i = 0; i < 16; i++){
        in >> numb;
        b.push_back(numb);
    }
    in.ignore();
    getline(in, name);
}

/*
    Move functions, fuck dette kan ta tid. 
*/

void Game::toFile(std::ofstream & out)
{   
    out << ((lost) ? "1" : "0"); 
    
    for(int i = 0; i < 16; i++){
        out << " " << b[i];
    }
    out << " " << name << "\n";
}

bool Game::moveUp()
{
    bool check = false;

    for(int i = 0; i < 4 ; i++){
        if(!check){
            check = move(i, i+4, i+8, i+12);
        }else
            move(i, i+4, i+8, i+12);
    }
    return(check);
}

bool Game::moveLeft()
{
    bool check = false;

    for(int i = 0; i <= 12; i+=4){
        if(!check){
            check = move(i, i+1, i+2, i+3);
        }else
            move(i, i+1, i+2, i+3);
    }
    return(check);
}

bool Game::moveDown()
{
    bool check = false;

    for(int i = 12; i <= 15; i++){
        if(!check){
            check = move(i, i-4, i-8, i-12);
        }else
            move(i, i-4, i-8, i-12);
    }
    return(check);
}

bool Game::moveRight()
{
    bool check = false;
    
    for(int i = 3; i <= 15; i+=4){
        if(!check){
            check = move(i, i-1, i-2, i-3);
        }else
            move(i, i-1, i-2, i-3);
    }
    return(check);
}

bool Game::move(int nr3, int nr2, int nr1, int nr0)
{
    bool move = true;
    bool check = false;
    int ant = 0;

    if(b[nr3] == 0 && b[nr2] == 0 && b[nr1] == 0 && b[nr0] == 0) move = false;

    //Move right line1R
    while(move){

        if(b[nr3] == 0){
            b[nr3] = b[nr2]; b[nr2] = 0;
            b[nr2] = b[nr1]; b[nr1] = 0;
            b[nr1] = b[nr0]; b[nr0] = 0;
            check = true;
        }
        if(b[nr2] == 0){
            b[nr2] = b[nr1]; b[nr1] = 0;
            b[nr1] = b[nr0]; b[nr0] = 0;
            check = true;
        }
        if(b[nr1] == 0){
            b[nr1] = b[nr0]; b[nr0] = 0;
            check = true;
        }

        if(ant == 3){
            move = false;
        }else ant++;
    }

    if(b[nr2] == b[nr3] && b[nr3] != 0){                      // 2 høyre er lik
        b[nr3] = b[nr2] + b[nr3]; b[nr2] = 0;
        check = true;

        if(b[nr0] == b[nr1] && b[nr1] != 0){                  // 2 venstre også lik
            b[nr2] = b[nr0] + b[nr1]; b[nr1] = b[nr0] = 0;

        }else{                                          // bare 2 høyre var lik
            b[nr2] = b[nr1]; b[nr1] = b[nr0]; b[nr0] = 0;
        }

    }else if(b[nr1] == b[nr2] && b[nr2] != 0){                // 2 midten var lik
        b[nr2] = b[nr2] + b[nr1]; 
        b[nr1] = b[nr0]; b[nr0] = 0;
        check = true;

    }else if(b[nr0] == b[nr1] && b[nr1] != 0){
        b[nr1] = b[nr1] + b[nr0]; b[nr0] = 0;
        check = true;
    }
    return(check);
}

void Game::playGame()
{
    int temp_nr;
    bool valid;

    if(!lost){

        temp_nr = newRandNumber();
        displayBoard();
        moveMenu();
    
        char input = r_char("What operation u want to do");
        while (input != 'Q' && lost != true)
        {
            //legge til at hvis ingen posisjoner er 0, så vill spilles avsluttes.

            if (checkValidChar(input))
            {
                std::cout << "\nValid - " << input << "\n";

                switch(input){
                    case 'W' : valid = moveUp(); break;
                    case 'A' : valid = moveLeft(); break;
                    case 'S' : valid = moveDown(); break;
                    case 'D' : valid = moveRight(); break;
                }   

                if(valid){temp_nr = newRandNumber();};    //bare nytt nummer hvis noe har beveget seg.
                
                displayBoard();

            }
            else
                std::cout << "\nInvalid input, try another char\n";
            
            if(checkLoss()){
                std::cout << "\nThe game has ended!" << std::endl;
                lost = true;
            }else
                input = r_char("What operation u want to do");

        }
            removeNumber(temp_nr);
    }else
        std::cout << "\nThis game has ended!" << std::endl;
        displayBoard();
}

bool Game::checkNoMoves(int nr3, int nr2, int nr1, int nr0)
{
    bool playable = false;     //false == not lost / true == lost
    int ant = 0;

    if(b[nr2] == b[nr3] && b[nr3] != 0){
        playable = true;

        if(b[nr0] == b[nr1] && b[nr1] != 0){
            //b[nr2] = b[nr0] + b[nr1]; b[nr1] = b[nr0] = 0;

        }else{
            //b[nr2] = b[nr1]; b[nr1] = b[nr0]; b[nr0] = 0;
        }

    }else if(b[nr1] == b[nr2] && b[nr2] != 0){
        playable = true;

    }else if(b[nr0] == b[nr1] && b[nr1] != 0){
        playable = true;
    }

    return(playable);
}

bool Game::checkLoss(){
    int ant = 0;

    for(int i = 0; i < 16; i++){
        if(b[i] != 0){
            ant++;
        }
    }

    if(ant == 16){

        std::cout << "1-";
        for(int i = 0; i < 4; i++){
            std::cout << "2-";
            if(checkNoMoves(i, i+4, i+8, i+12)) return false;   // not lost
        }
        for(int i = 0; i <= 12; i+=4){
            std::cout << "3-";
            if(checkNoMoves(i, i+1, i+2, i+3)) return false;    // and not lost
        }
        for(int i = 12; i <= 15; i++){
            std::cout << "4-";
            if(checkNoMoves(i, i-4, i-8, i-12)) return false;   // nope
        }
        for(int i = 3; i <= 15; i+=4){
            std::cout << "5-";
            if(checkNoMoves(i, i-1, i-2, i-3)) return false;    // no
        }
            
    }else
        return false;       // Not enough numbers on board

    return true;            // Game Over!
}

int Game::newRandNumber()
{
    int pos, nr;

    do{
        pos = rand() % 16;
    }while(b[pos] != 0);
    nr = rand() % 2;
    b[pos] = (nr % 2 == 1) ? 2 : 4;

    return pos; //Returns the posision on board that might be deleted if no moves are played
}

void Game::removeNumber(int nr)
{
    b[nr] = 0;
}

bool Game::checkValidChar(char t)
{
    return ((t == 'W' || t == 'A' || t == 'S' || t == 'D') ? true : false);
}

void Game::displayBoard()
{
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
void Game::displayName()
{
    std::cout << std::left << std::setw(10) << this->name;
}

void Game::displayLoss()
{
    std::cout << ((lost) ? " - x" : "");
}

void Game::moveMenu()
{
    std::cout << "\nup - W | left - A | down - S | D - right";
}

/*
    Functions, main
*/

void writeToFile()
{
    int num = gGames.size();
    std::ofstream out("gameData.dta");

    if(out){
        out << num << "\n";
        for(int i = 0; i < num; i++){
            gGames[i]->toFile(out);
        }
        if(num){ std::cout << "\nWrote " << num << " games to file\n";
        }else std::cout << "\nWrote nothing to file\n";
        
    }else
        std::cout << "\nDid not find file\n";
}

void readFromFile()
{
    int nr;
    Game* newG;
    std::ifstream in("gameData.dta");

    in >> nr; in.ignore(); //Neste linje??

    if(in){
        for(int i = 0; i < nr; i++){
            newG = new Game(in);
            gGames.push_back(newG);
        }
        if(nr){ std::cout << "\nRead " << nr << " of games from file\n";
        }else std::cout << "\nNo games saved!\n";
        
    }else
        std::cout << "\nDid not read anything from file\n";
}

void new_game()
{

    Game *new_G = new Game();

    std::cout << "\ncheck 1" << std::endl;

    // temp->startup();
    gGames.push_back(new_G);
}

void play_game()
{
    int nr;
    if (!gGames.empty())
    {
        show_games();
        nr = r_int_bet("Whitch game do you want to play", 0, gGames.size());
        if (nr)
        {
            gGames[nr - 1]->playGame();
        }
        else
            std::cout << "\nNo games will be played!" << std::endl;
    }
    else
        std::cout << "No games to play" << std::endl;
}

// Maybe unnecessary
void show_games()
{
    if (!gGames.empty())
    {
        std::cout << "\n\tX means the game has ended, no more moves!\n\n";
        
        for (int i = 0; i < gGames.size(); i++)
        {
            std::cout << "\n"
                      << i + 1 << ". ";
            gGames[i]->displayName();
            gGames[i]->displayLoss();
        }
    }
    else
        std::cout << "\nNo games to show" << std::endl;

    std::cout << "\n";
}
    

void menu()
{
    std::cout << "\nPossble operations:\n";
    std::cout << "\n\tN - new game";
    std::cout << "\n\tS - show running games";
    std::cout << "\n\tP - play existing game";
}