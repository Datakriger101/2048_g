#include <iomanip>
#include <iostream>
#include "E_func.h" // Homemade
#include <vector>

//test
#include <cstdlib>   // for rand() func

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
        void displayBoard();
        void playGame();

        void moveMenu();
        void newRandNumber();

        bool checkValidMove(char tegn);
        bool checkMoveRight();
        bool checkLoss();

        //Better way to do this?
        void moveUp();
        void moveLeft();
        void moveDown();
        void moveRight();

        Game(); //constructor to make to board
};

/*
    Decalation of Functions
*/

void menu();
void new_game();
void play_game();
void show_games();

std::vector<Game *> gGames;

int main()
{
    char input;

    // check from the files

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
}

Game::Game()
{

    this->name = r_string("What is the name of the game");
    this->lost = false;
    for (int i = 0; i < 16; i++)
    {
        b.push_back(0);
    }
}

/*
    Move functions, fuck dette kan ta tid. 
*/

void Game::moveUp(){}

void Game::moveLeft(){}

void Game::moveDown(){}

void Game::moveRight()
{
    std::cout << "\n-5-" << std::endl;
    bool moveRight = true;
    int ant = 0;

    // Lim inn 80% kode her. 

    if(b[3] == 0 && b[2] == 0 && b[1] == 0 && b[0] == 0) moveRight = false;

    std::cout << "\n-7-" << std::endl;

    //Move right line1R
    while(moveRight){

        if(b[3] == 0){
            b[3] = b[2]; b[2] = 0;
            b[2] = b[1]; b[1] = 0;
            b[1] = b[0]; b[0] = 0;
        }
        if(b[2] == 0){
            b[2] = b[1]; b[1] = 0;
            b[1] = b[0]; b[0] = 0;
        }
        if(b[1] == 0){
            b[1] = b[0]; b[0] = 0;
        }

        if(ant == 3){
            moveRight = false;
        }else ant++;

        if(b[2] == b[3] && b[3] != 0){                      // 2 høyre er lik
        b[3] = b[2] + b[3]; b[2] = 0;

            if(b[0] == b[1] && b[1] != 0){                  // 2 venstre også lik
              b[2] = b[0] + b[1]; b[1] = b[0] = 0; moveRight = false;

            }else{                                          // bare 2 høyre var lik
               b[2] = b[1]; b[1] = b[0]; b[0] = 0; moveRight = false; 
            }

        }else if(b[1] == b[2] && b[2] != 0){                // 2 midten var lik
            b[2] = b[2] + b[1]; 
            b[1] = b[0]; b[0] = 0; moveRight = false; 

        }else if(b[0] == b[1] && b[1] != 0){
            b[1] = b[1] + b[0]; b[0] = 0; moveRight = false; 

        }
        
    }

    //Move right line2R
    moveRight = true; ant = 0;
    if(b[7] == 0 && b[6] == 0 && b[5] == 0 && b[4] == 0){ moveRight = false; }

    while(moveRight){

        if(b[7] == 0){
            b[7] = b[6]; b[6] = 0;
            b[6] = b[5]; b[5] = 0;
            b[5] = b[4]; b[4] = 0;
        }
        if(b[6] == 0){
            b[6] = b[5]; b[5] = 0;
            b[5] = b[4]; b[4] = 0;
        }
        if(b[5] == 0){
            b[5] = b[4]; b[4] = 0;
        }

        if(ant == 3){
            moveRight = false;
        }else ant++;

        if(b[6] == b[7] && b[7] != 0){                      // 2 høyre er lik
        b[7] = b[6] + b[7]; b[6] = 0;

            if(b[4] == b[5] && b[5] != 0){                  // 2 venstre også lik
              b[6] = b[4] + b[5]; b[5] = b[5] = 0; moveRight = false; 

            }else{                                          // bare 2 høyre var lik
               b[6] = b[5]; b[5] = b[4]; b[4] = 0; moveRight = false;
            }

        }else if(b[5] == b[6] && b[6] != 0){                // 2 midten var lik
            b[6] = b[6] + b[5]; 
            b[5] = b[4]; b[4] = 0; moveRight = false;

        }else if(b[4] == b[5] && b[5] != 0){
            b[5] = b[5] + b[4]; b[4] = 0; moveRight = false;

        }

    }

    //Move right line3R from top
    moveRight = true; ant = 0;
    if(b[11] == 0 && b[10] == 0 && b[9] == 0 && b[8] == 0){ moveRight = false; }

    while(moveRight){

        if(b[11] == 0){
            b[11] = b[10]; b[10] = 0;
            b[10] = b[9]; b[9] = 0;
            b[9] = b[8]; b[8] = 0;
        }
        if(b[10] == 0){
            b[10] = b[9]; b[9] = 0;
            b[9] = b[8]; b[8] = 0;
        }
        if(b[9] == 0){
            b[9] = b[8]; b[8] = 0;
        }

        if(ant == 3){
            moveRight = false;
        }else ant++;

        if(b[10] == b[11] && b[11] != 0){                   // 2 høyre er lik
        b[11] = b[10] + b[11]; b[10] = 0;

            if(b[8] == b[9] && b[9] != 0){                  // 2 venstre også lik
              b[10] = b[8] + b[9]; b[9] = b[9] = 0; moveRight = false;

            }else{                                          // bare 2 høyre var lik
               b[10] = b[9]; b[9] = b[8]; b[8] = 0; moveRight = false;       
            }

        }else if(b[9] == b[10] && b[10] != 0){                // 2 midten var lik
            b[10] = b[10] + b[9]; 
            b[9] = b[8]; b[8] = 0; moveRight = false;

        }else if(b[8] == b[9] && b[9] != 0){
            b[9] = b[9] + b[8]; b[8] = 0; moveRight = false;

        }

    }

    //Move right line4R from top
    moveRight = true; ant = 0;
    if(b[11] == 0 && b[10] == 0 && b[9] == 0 && b[8] == 0){ moveRight = false; }

    while(moveRight){

        if(b[15] == 0){
            b[15] = b[14]; b[14] = 0;
            b[14] = b[13]; b[13] = 0;
            b[13] = b[12]; b[12] = 0;
        }
        if(b[14] == 0){
            b[14] = b[13]; b[13] = 0;
            b[13] = b[12]; b[12] = 0;
        }
        if(b[13] == 0){
            b[13] = b[13]; b[13] = 0;
        }
 
        if(ant == 3){
            moveRight = false;
        }else ant++;

        if(b[14] == b[15] && b[15] != 0){                      // 2 høyre er lik
        b[15] = b[14] + b[14]; b[14] = 0;

            if(b[12] == b[13] && b[13] != 0){                  // 2 venstre også lik
              b[14] = b[12] + b[13]; b[13] = b[13] = 0; moveRight = false;

            }else{                                             // bare 2 høyre var lik
               b[14] = b[13]; b[13] = b[12]; b[12] = 0; moveRight = false;        
            }

        }else if(b[13] == b[14] && b[14] != 0){                // 2 midten var lik
            b[14] = b[14] + b[13]; 
            b[13] = b[12]; b[12] = 0; moveRight = false; 

        }else if(b[12] == b[13] && b[13] != 0){
            b[13] = b[13] + b[12]; b[12] = 0; moveRight = false; 

        }

    }

}


void Game::playGame()
{
    std::cout << "\n!1!" << std::endl;
    if(!lost){
        displayBoard();
        moveMenu();
    
    //newRandNumber();
        std::cout << "\n!2!" << std::endl;
        char input = r_char("What operation u want to do");
        while (input != 'Q' && lost != true)
        {
            //legge til at hvis ingen posisjoner er 0, så vill spilles avsluttes.

            if (checkValidMove(input))
            {
                std::cout << "\n!3!" << std::endl;
                std::cout << "\nValid - " << input << "\n";

                std::cout << "\n!4!" << std::endl;

                switch(input){
                    case 'W' : moveUp(); break;
                    case 'A' : moveLeft(); break;
                    case 'S' : moveDown(); break;
                    case 'D' : moveRight(); break;
                }

                newRandNumber();
                displayBoard();

            }
            else
                std::cout << "\nInvalid input, try another char\n";
            
            if(checkLoss()){
                std::cout << "\nThe game has ended!" << std::endl;
                lost = true;
            }

            input = r_char("What operation u want to do");

        }
    }else
        std::cout << "\nThis game has ended!" << std::endl;
        displayBoard();
}

bool Game::checkLoss(){
    int ant = 0;
    for(int i = 0; i < 16; i++){
        if(b[i] != 0)ant++;
    }
    //std::cout << "\n - " << ant << " - \n";

    return(ant == 16 ? true : false);
}

void Game::newRandNumber()
{
    int pos, nr;

    do{
        pos = rand() % 16;
        std::cout << "\n -- " << pos << " --\n";
    }while(b[pos] != 0);
    nr = rand() % 2;
    b[pos] = (nr % 2 == 1) ? 2 : 4;
}

bool Game::checkValidMove(char t)
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
    std::cout << this->name;
}

void Game::moveMenu()
{
    std::cout << "\nup - W | left - A | down - S | D - right";
}

/*
    Functions, main
*/

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
        for (int i = 0; i < gGames.size(); i++)
        {
            std::cout << "\n"
                      << i + 1 << ". ";
            gGames[i]->displayName();
        }
    }
    else
        std::cout << "\nNo games to show" << std::endl;
}

void menu()
{
    std::cout << "\nPossble operations:\n";
    std::cout << "\n\tN - new game";
    std::cout << "\n\tS - show running games";
    std::cout << "\n\tB - show board";
    std::cout << "\n\tP - play existing game";
    std::cout << "\n\t";
    std::cout << "\n\t";
}