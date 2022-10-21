/*
 *  Lager spillet 024, ,,8
 *
 */

#include <iostream>
#include <iomanip>
#include "E_func.h"
#include <vector>
#include <map>

#include <cstdlib>
using namespace std;

//functions, yes

int main(){

    int nr;
    int antall1[16];
    int antall2[16];



    for(int i = 0; i < 16; i++){
        antall1[i] = 0;
        antall2[i] = 0;
    }

    for(int i = 0; i < 1000; i++){
        nr = rand() % 16;
        antall1[nr] += 1;
    }

    for(int i = 0; i < 1000; i++){
        nr = rand() % 16;
        antall2[nr] += 1;
    }

    for(int i = 0; i < 16; i++){
        cout << setw(2) << i << ". " << antall1[i] << "\t\t" << setw(2) << i << ". " << antall2[i] << "\n";
    }

    //Conclusion, can not use arrow keys with terminal. fuck
}