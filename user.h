#ifndef USER_H
#define USER_H
#include<iostream>
#define GREEN "\033[32m"
#include"admin.h"
#include<fstream>
using namespace std;

class userAcc{
    public:
    ofstream userAdd;
    string username, userID, userPASS;
    vector<string> Username;
    vector<string> Password;
    vector<string> Userid;

};

class userclass : public type, public userAcc{
    public:


void userLogin(){
    string name, uname, pass;
    cout<<"\t\tEnter The UserName:  "; cin>>name;
    cout<<"\t\tEnter The PassWord:  "; cin>>pass;


    ifstream sh;
    sh.open("login.db" , ios::in);
    string nAME ,uNAME, pASS;
    bool found = false;

    while(sh >> nAME >> uNAME >> pASS){
        if(uNAME == name  and  pASS == pass){
        cout << "==================================================" << endl;
    cout << GREEN << "          <<--LOGIN SUCCESSFULL-->>" << RESET << endl;
        cout << "==================================================" << endl;
            found = true;
            break;
        }
       
    }
    if(!found){
        cout << "==================================================" << endl;
    cout << GREEN << "        <<--ACCOUNT NOT EXIST-->>" << RESET << endl;
        cout << "==================================================" << endl;
    }  

}

void bookingCar(){
    int choice;
    cout<<"Do You Want To Book";
    cout<<"\t1. YES \t2.NO";
    cin>>choice;
    if(choice!=1)
    showCarsFromFile();

    ifstream bk;
    bk.open("booking.db", ios::app | ios::binary);
    //bk.

}


//-------------------//
void showCarsFromFile() {
        ifstream sh;
        sh.open("storage.db", ios::in);
            string comp, mdl, prc, spd;
            int index = 0;
            cout << YELLOW << "  |=============================================================================" << "|" << RESET << endl;
            cout << YELLOW << "  |    \t" << BLUE << "COMPANY" << RESET << "\t\t|  " << BLUE << "PRICE  \t" << RESET << "| " << BLUE << "SPEED  \t" << RESET << "| " << BLUE << "MODEL \t\t\t" << RESET << "|" << endl;
            cout << YELLOW << "  |=============================================================================" << "|" << RESET << endl;
            while (sh >> comp >> mdl >> prc >> spd) {
                
                cout << YELLOW << "  |\t" << RESET << index+1 << " | " << comp << " \t| " << prc << " \t| " << spd << " \t| " << mdl << endl;
                cout << YELLOW << "  |=============================================================================" << "|" << RESET << endl;
                index++;
            }
            sh.close();
        
    }

void car_detail(){
    int choice;  cout<<"\tEnter Your Choice:  ";
    cin>>choice; choice=choice-1;

    ifstream sh;
    sh.open("storage.db" , ios::in);
    if(!sh.is_open()) cout<<"\t\tError Opening File:";

    string comp, mdl, prc, spd;
        int index = 0;
        bool found = false;

while(sh >> comp >> mdl >> prc >> spd){
        if(index==choice){
        cout<<"  |=====================================|\n";
cout<<"  |"<<YELLOW<<" \tYOU HAVE SELECTED  : "<<comp<<RESET<<"\t|"<<endl;
        cout<<"  |=====================================|\n";
        cout<<"  |\tModel  :  "<<mdl<<"\t\t|"<<endl;
        cout<<"  |\tPrice  :  "<<prc<<"\t\t|"<<endl;
        cout<<"  |\tSpeed  :  "<<spd<<"\t\t\t|"<<endl;
        cout<<"  |=====================================|";
            found = true;
            break;
        }
        index++;
    }
    sh.close();
     if (!found) {
        cout << RED << "\t\tInvalid choice!" << RESET << endl;
    }
}

//------------------//

void Search() {
    string name;
    system("CLS");
    cout << "SEARCH BY NAME \n";
    cout << "Enter the name of the car: ";
    cin >> name;

     ifstream sh;
        sh.open("storage.db", ios::in);

    if (!sh.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string comp, mdl, prc, spd;
    bool found = false;

    while (sh >> comp >> mdl >> prc >> spd) {
        if (name == comp) {
            cout << YELLOW << "  |=============================================================================" << "|" << RESET << endl;
            cout << YELLOW << "  |\t" << RESET << company.size()+1 << " | " << comp << " \t| " << prc << " \t| " << spd << " \t| " << mdl << endl;
            cout << YELLOW << "  |=============================================================================" << "|" << RESET << endl;
            found = true;
            break; // Assuming you want to stop searching after finding the first match
        }
    }

    if (!found) {
        cout << "==================================================" << endl;
        cout << RED << " <<--THIS CAR IS NOT AVAILABLE-->>" << RESET << endl;
        cout << "==================================================" << endl;
    }
}

//------------------//

void adduserAcc(){
     userAdd.open("login.db",  ios::in | ios::binary );
    userAdd << "Username:       userID:         Password:"<<endl;
    userAdd.close();

    userAdd.open("login.db",  ios::in   | ios::app  | ios::binary );
      for (size_t i = 0; i < Username.size(); i++) {
userAdd<< Username[i] << "     "<<Userid[i]<<"       " << Password[i] << endl;
        }
    userAdd.close();
}

void createAcc(){
     
        cout << "Enter Username: ";
        getline(cin, username);
        cout<<"Enter userID: ";
        cin>>userID;
        cout << "Enter password: ";
        cin >>userPASS;
        Username.push_back(username);
        Userid.push_back(userID);
        Password.push_back(userPASS);
     
     adduserAcc();
}

//------------------//

void booking(){
    showCarsFromFile();
    car_detail();
    system("PAUSE");
}






};


#endif
