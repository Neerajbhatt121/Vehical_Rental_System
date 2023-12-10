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
    system("CLS");
cout<<BLUE<<"   _____________================================================================\n";
cout<<" _/_|[][][][][] | - -|"<<YELLOW<<"                  :MAIN MENU:                            "<<BLUE<<"|\n";
cout<<"(      City Bus | - -===========================================================\n";
cout<<"=--OO-------OO--=dwb\n"<<RESET;
cout<<BLUE<<"\t========================================================================\n";
       cout<<"\t|                                                                      |\n";
cout<<BLUE<<"\t|"<<YELLOW<<"\t 1. SHOW CARS                       2. SEARCH CAR              "<<BLUE<<"|\n";
       cout<<"\t|                                                                      |\n";
cout<<BLUE<<"\t|"<<YELLOW<<"\t 3. CREATE USER ACC.                4. CREATE ADMIN ACCOUNT    "<<BLUE<<"|\n";
       cout<<"\t|                                                                      |\n";
cout<<BLUE<<"\t|"<<YELLOW<<"\t 5. BOOKING                         6. SHOW TICKET             "<<BLUE<<"|\n";
       cout<<"\t|                                                                      |\n";
cout<<BLUE<<"\t|"<<YELLOW<<"\t 7. ADD CAR                         8. LOGOUT                  "<<BLUE<<"|\n";
      cout<<"\t|                                                                      |\n";
 cout<<BLUE<<"\t========================================================================\n\n\n";
 }






