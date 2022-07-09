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

char r_char(std::string txt){
    char input;
    std::cout << std::endl << txt << " :";
    std::cin >> input; std::cin.ignore(MAXCHAR, '\n'); //Må være '' ettersom "" forteller at det er en flere char
    return(toupper(input));
}

//This just kinda works 
std::string r_string(std::string txt){
    std::string name;
    std::cout << std::endl << txt << " :";
    getline(std::cin, name);
    return name;
}