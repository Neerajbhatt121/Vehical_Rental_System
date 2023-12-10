#ifndef USER_H
#define USER_H
#include <iostream>
#define GREEN "\033[32m"
#include "admin.h"
#include<string>
#include <fstream>
#include <cstdlib> // Include the necessary header for rand()
#include <ctime>   // Include the necessary header for srand() and time()
using namespace std;

class userAcc
{
public:
    ofstream userAdd;
    string username, userID, userPASS;
    vector<string> Username;
    vector<string> Password;
    vector<string> Userid;
};

class userclass : public type, public userAcc
{
public:
    string name, uname, pass;
    int choice_index , bookNo;
    ifstream sh;
    string comp, mdl, prc, spd , loggedInUsername, loggedInUserID;

    // Function to generate a random booking number
    int generateBookingNumber()
    {
        srand(time(nullptr));         // Seed the random number generator with the current time
        return rand() % 10000 + 1000; // Generate a random number in the range [1000, 9999]
    }

    void userLogin(){
        cout << "\t\tEnter The UserName:  ";
        cin >> uname;
        cout << "\t\tEnter The PassWord:  ";
        cin >> pass;

        ifstream sh;
        sh.open("login.db", ios::in);
        string nAME, uNAME, pASS;
        bool found = false;

        while (sh >> nAME >> uNAME >> pASS)
        {
            if (uNAME == uname and pASS == pass)
            {
                cout << "==================================================" << endl;
                cout << GREEN << "          <<--LOGIN SUCCESSFULL-->>" << RESET << endl;
                cout << "==================================================" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << RED << "==================================================" << endl;
            cout << "        <<--ACCOUNT NOT EXIST-->>" << endl;
            cout << "==================================================" << RESET << endl;
        }

        system("PAUSE");
        
    }

    //--------------------//

    void showCarsFromFile()
    {
        ifstream sh;
        sh.open("storage.db", ios::in);
        string comp, mdl, prc, spd;
        int index = 0;
        cout << YELLOW << "  |============================================================================="
             << "|" << RESET << endl;
        cout << YELLOW << "  |    \t" << BLUE << "COMPANY" << RESET << "\t\t|  " << BLUE << "PRICE  \t" << RESET << "| " << BLUE << "SPEED  \t" << RESET << "| " << BLUE << "MODEL \t\t\t" << RESET << "|" << endl;
        cout << YELLOW << "  |============================================================================="
             << "|" << RESET << endl;
        while (sh >> comp >> mdl >> prc >> spd)
        {

            cout << YELLOW << "  |\t" << RESET << index + 1 << " | " << comp << " \t| " << prc << " \t| " << spd << " \t| " << mdl << endl;
            cout << YELLOW << "  |============================================================================="
                 << "|" << RESET << endl;
            index++;
        }
        sh.close();
    }

    void car_detail()
    {
        cout << "\tEnter Your Choice:  ";
        cin >> choice_index;
        choice_index = choice_index - 1;

        sh.open("storage.db", ios::in);
        if (!sh.is_open())
            cout << "\t\tError Opening File:";

        int index = 0;
        bool found = false;

        while (sh >> comp >> mdl >> prc >> spd)
        {
            if (index == choice_index)
            {
                cout << "  |=====================================|\n";
                cout << "  |" << YELLOW << " \tYOU HAVE SELECTED  : " << comp << RESET << "\t|" << endl;
                cout << "  |=====================================|\n";
                cout << "  |\tModel  :  " << mdl << "\t\t|" << endl;
                cout << "  |\tPrice  :  " << prc << "\t\t|" << endl;
                cout << "  |\tSpeed  :  " << spd << "\t\t\t|" << endl;
                cout << "  |=====================================|";
                found = true;
                break;
            }
            index++;
        }
        sh.close();
        if (!found)
        {
            cout << RED << "\t\tInvalid choice!" << RESET << endl;
        }
        cout << endl;
    }

    //------------------//

    void Search()
    {
        trySearch:
        string name;
        system("CLS");
        cout << "SEARCH BY NAME \n";
        cout << "Enter the name of the car: ";
        cin >> name;

        ifstream sh;
        sh.open("storage.db", ios::in);

        if (!sh.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        string comp, mdl, prc, spd;
        bool found = false;

        while (sh >> comp >> mdl >> prc >> spd)
        {
            if (name == comp)
            {
                cout << YELLOW << "  |============================================================================="
                     << "|" << RESET << endl;
                cout << YELLOW << "  |\t" << RESET << company.size() + 1 << " | " << comp << " \t| " << prc << " \t| " << spd << " \t| " << mdl << endl;
                cout << YELLOW << "  |============================================================================="
                     << "|" << RESET << endl;
                found = true;
                
            }
        }

        if (!found)
        {
            cout << "==================================================" << endl;
            cout << RED << " <<--THIS CAR IS NOT AVAILABLE-->>" << RESET << endl;
            cout << "==================================================" << endl;
            system("PAUSE");
            goto trySearch;
        }
    }

    //------------------//

    void adduserAcc()
    {
        userAdd.open("login.db", ios::in | ios::binary);
        userAdd << "Username:       userID:         Password:" << endl;
        userAdd.close();

        userAdd.open("login.db", ios::in | ios::app | ios::binary);
        for (size_t i = 0; i < Username.size(); i++)
        {
            userAdd << Username[i] << "     " << Userid[i] << "       " << Password[i] << endl;
        }
        userAdd.close();
        cout << endl;
        cout << "  |=====================================|\n";
        cout << "  |" << YELLOW << " \tACCOUNT CREATED SUCESSFULLY : " << RESET << "\t|" << endl;
        cout << BLUE << "  |=====================================|\n"
             << RESET;
        system("PAUSE");
        system("main.exe");
    }

    void createAcc()
    {

        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter userID: ";
        cin >> userID;
        cout << "Enter password: ";
        cin >> userPASS;
        Username.push_back(username);
        Userid.push_back(userID);
        Password.push_back(userPASS);

        adduserAcc();
    }

//-------------------//

    void book()
    {
        
        system("PAUSE");
        
        booking(name, uname, choice_index);
    }

    void booking(const string &loggedInUsername, const string &loggedInUserID, int &choice_index)
    {
        retry:
        int choice;
        int index = 0;
        cout << YELLOW <<"=================================================="<<RESET << endl;
                cout << "          <<--Do You Want To Book?-->>" << endl;
                cout << "==================================================" << RESET << endl;
        cout <<"\t1. YES\t2. NO\n";
        cin >> choice;
        sh.open("storage.db", ios::in);
        bool found = true;

        if (choice == 1)
        {
            found = false;

            while (sh >> comp >> mdl >> prc >> spd)
            {
                // Validate the selected car index
                if (index == choice_index)
                {
                    // Generate a random booking number
                    int bookingNumber = generateBookingNumber();

                    // Open the booking database file
                    ofstream bookingFile("booking.db", ios::app | ios::binary);

                    // Write the booking details (username, userID, car details, and booking number) to the file
                    bookingFile<< loggedInUserID << "   "<< comp<<"   "<<mdl <<"   "<<prc<<"   " << spd << "  " << bookingNumber << endl<<endl;
 
                    // Close the booking file
                    bookingFile.close();
                    sh.close();

    cout <<GREEN  <<"================================================================================" << endl;
            cout << "           <<--Booking successful! Your booking number is:-->> ||  "<<bookingNumber << endl;
            cout << "================================================================================" << RESET << endl;   
                    found = true;
                    break;
                }
                index++;
            }
        }

        if(choice == 2){
            cout << RED <<  "==================================================" << endl;
                    cout << "            <<--NOT BOOKED-->>" << endl;
                    cout << "==================================================" << RESET << endl;
        }

        if (!found)
        {
            cout << RED <<  "==================================================" << endl;
                    cout << "             <<--Invalid choice-->>" << endl;
                    cout << "==================================================" << RESET << endl;
                system("PAUSE");    
                goto retry;
        }
    }

    void showTicket(){
        ifstream sh;
        int regNo;
        bool found = false;
         cout<<"Enter Your Registration no. : ";
         cin>>regNo;
         sh.open("booking.db");
         if (!sh.is_open()){
        cout << "Error opening booking.db file!" << endl;
        return;
    }

            
         while(sh >> loggedInUserID >> comp >> mdl >> prc >> spd >> bookNo){
             
              if(regNo == bookNo){
            cout<<YELLOW<<"============================================================================\n";
            cout<<"|"<<RESET<<"                             YOUR TICKED IS HERE                          "<<YELLOW<<"|\n";
            cout<<YELLOW<<"============================================================================\n";
            cout<<YELLOW<<"|"<<RESET<<"                                                                           \n";
            cout<<YELLOW<<"|"<<RESET<<"                   Registion No.  ==== "<< bookNo<<"\n";
            cout<<YELLOW<<"|"<<RESET<<"                         User Id  ==== "<< loggedInUserID<<"\n";
            cout<<YELLOW<<"|"<<RESET<<"                         Company  ==== "<< comp<<"\n";
            cout<<YELLOW<<"|"<<RESET<<"                                                                           \n";
    cout << YELLOW <<     "|==========================================================================="<< "|" << RESET << endl;
        cout << YELLOW << "|\t   " << RESET << company.size() + 1 << " | " << comp << " \t| " << prc << "\t| " << spd << " \t| " << mdl << endl;
        cout << YELLOW << "|==========================================================================="<< "|" << RESET << endl;
                found = true;
                break;
            }      
        }
          sh.close();
          if(!found){
              cout <<RED << "==================================================" << endl;
                    cout << "     <<--Invalid REGISTRATION NO.-->>" << endl;
                    cout << "==================================================" << RESET << endl;
          }
    }


//-------------------//

};

#endif
