/*
 *  Eskil Refsgaard with all the functions he needs.
 *
 * 
 */

#include <iostream>
#include <string>

const int MAXCHAR = 200;

char r_char(std::string txt);
std::string r_string(std::string txt);
int r_int(std::string txt);
int r_int_bet(std::string txt, int min, int max);
bool y_or_no(std::string txt);

char r_char(std::string txt){
    char input;
    std::cout << std::endl << txt << " :";
    std::cin >> input; std::cin.ignore(MAXCHAR, '\n'); //Må være '' ettersom "" forteller at det er en flere char
    return(toupper(input));
}

//This just kinda works 
std::string r_string(std::string txt){
    std::string name;
    std::cout << std::endl << txt << ": ";
    getline(std::cin, name);
    return name;
}

int r_int(std::string txt){
    int nr;
    std::cout << std::endl << txt << ":";
    std::cin >> nr; std::cin.ignore(MAXCHAR, '\n');
    return nr;
}

int r_int_bet(std::string txt, int min, int max){
    int nr;
    while(nr < min || nr > max){
        std::cout << std::endl << txt << "(" << min << " - " << max << "): ";
        std::cin >> nr; std::cin.ignore(MAXCHAR, '\n');
    }
    return nr;
}

bool y_or_n(std::string txt){
    char input;
    std::cout << std::endl << txt << ": ";
    std::cin >> input; std::cin.ignore(MAXCHAR, '\n');
    if(input == 'Y' || input == 'y')
        return true;
    else
        return false;
}