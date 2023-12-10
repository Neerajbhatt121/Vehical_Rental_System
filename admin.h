// adding_car.cpp

#include <iostream>
#include <vector>
#include <fstream>
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
using namespace std;

//--------------------------//

class type{
    public:
    vector<string> company;
    vector<string> model;
    vector<string> price;
    vector<string> speed;
};

//--------------------------//

class admin : public type{
string comp, mdl, prc, spd;
    ofstream carAdd;
    ifstream carSee;
    ofstream adminAdd;
    string adminName, adminID, adminPass;


public: 

void addAdminAcc(){
     adminAdd.open("admin_login.db",  ios::in | ios::binary );
    adminAdd << "AdminName:       AdminID:         Password:"<<endl;
    adminAdd.close();

    adminAdd.open("admin_login.db",  ios::in   | ios::app  | ios::binary );
      
adminAdd<< adminName << "     "<<adminID<<"       " << adminPass << endl;
        
    adminAdd.close();
}

void createAdminAcc(){
     
        cout << "Enter Username: ";
        cin.ignore();
        getline(cin, adminName);
        cout<<"Enter userID: ";
        cin>>adminID;
        cout << "Enter password: ";
        cin >>adminPass;
      
     
     addAdminAcc();
}


void adminlogin(){
    retry:
    string  adminname, pass;
    cout<<"\t\tEnter The UserName:  "; cin>>adminname;
    cout<<"\t\tEnter The PassWord:  "; cin>>pass;


    ifstream sh;
    sh.open("admin_login.db" , ios::in);
    string nNAME,uNAME, pASS;
    bool found = false;

    while(sh >> nNAME >> uNAME >> pASS){
        if(uNAME == adminname  and  pASS == pass){
        cout << "==================================================" << endl;
    cout << GREEN << "          <<--LOGIN SUCCESSFULL-->>" << RESET << endl;
        cout << "==================================================" << endl;
            found = true;
            break;
        }
       
    }
     if(!found){
         cout << "==================================================" << endl;
    cout << RED << "         <<--LOGIN FAILED-->>" << RESET << endl;
        cout << "=====s=============================================" << endl;
            goto retry;
        }
       
    }    


void AddNewCar(){
    carAdd.open("storage.db",  ios::in |  ios::app  | ios::binary);
      for (size_t i = 0; i < company.size(); i++) {
carAdd << company[i] << "     " << model[i] << "       " << price[i] << "       " << speed[i] << endl;
        }
    carAdd.close();
     system("main.exe");
}

void addCarCompany() {
    int n;
    cout << "Enter how many cars you want to add: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
     
        cout << "Enter Company: ";
        cin.ignore();  // Ignore any newline character in the buffer
        getline(cin, comp);  // Allowing spaces in company name
        cout << "Enter Model: ";
        cin.ignore();  // Ignore any newline character in the buffer
        getline(cin, mdl);
        cout << "Enter Price: ";
        cin >> prc;
        cout << "Enter Speed: ";
        cin >> spd;

        company.push_back(comp);
        model.push_back(mdl);
        price.push_back(prc);
        speed.push_back(spd);
    }
    AddNewCar();
}




};



