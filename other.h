#include<iostream>
#include"user.h"
#define RESET "\033[0m"
#define RED "\033[31m"
#define ORANGE "\033[38;5;208m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
using namespace std;


void intro(){
system("CLS");
cout<<ORANGE<<"\t================================================================"<<RESET<<endl;
cout<<"\t|                 \033[i WELCOME TO VEHICAL RENTAL SYSTEM            |"<<endl;
cout<<ORANGE<<"\t================================================================"<<RESET<<endl;
 std::cout << "              ______--------___\n"
                 "             /|             / |\n"
                 " o___________|\\__________/__|\n"
                 "]|___     |  |=   ||  =|___  |\"\n"
                 "//   \\\\    |  |____||_///   \\\\|\"\n"
                 "|  X  |\\--------------/|  X  |\\\"\n"
                 " \\___/ 1924 Studebaker  \\___/\n";
    cout<<endl;
    system("pause");                 
}

void headline1(){
     cout<<"   _____________===============================================================\n";
     cout<<" _/_|[][][][][] | - -|                :ADMIN LOGIN PAGE HERE:                  |\n";
    cout<<"(      City Bus | - -==========================================================\n";
    cout<<"=--OO-------OO--=dwb\n"<<RESET;
}

void headline2(){
     cout<<"   _____________===============================================================\n";
     cout<<" _/_|[][][][][] | - -|                :USER LOGIN PAGE HERE:                  |\n";
    cout<<"(      City Bus | - -==========================================================\n";
    cout<<"=--OO-------OO--=dwb\n"<<RESET;
}


 void showmenu(){
    cout<<BLUE<<"=======================================================================\n";
    cout<<YELLOW<<"\t 1. USER LOGIN                      2. ADMIN LOGIN \n\n";
    cout<<YELLOW<<"\t 3. SHOW CARS                       4. SEARCH CAR\n\n";
    cout<<YELLOW<<"\t 5. CREATE USER ACC.                6. EXIT\n\n";
    cout<<YELLOW<<"\t 7. BOOKING                         8. EXIT\n\n";
    cout<<BLUE<<"=======================================================================\n\n\n";
 }



