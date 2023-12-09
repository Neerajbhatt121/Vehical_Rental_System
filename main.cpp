#include "other.h"
#include "user.h"
// #include"admin.h"
using namespace std;

int main()
{
    userclass uc;
    admin ad;
    retry:
    intro();

    int ch;
    cout<<"\n\n\t 1.User Login           2.Admin Login\n\n";
    cout<<" Enter Your Choice : ";
    cin >> ch;
    cout<<endl;
    switch (ch)
    {
    case 1:
    uc.userLogin();

    break;
    case2:
    ad.adminlogin();
    break;

    default:
        cout << RED << "==================================================" << endl;
        cout << RED << "         <<--SELECT CORRECT OPTION-->>" << RESET << endl;
        cout << RED << "==================================================" << endl;
        system("pause");
        goto retry;
        break;
    }

//-------------------------------------------------------//
    Refresh:
    showmenu();
    int cho;
    cin>>cho;
    switch(cho){
        case 1:
        system("CLS");
        uc.showCarsFromFile();
        uc.car_detail();
        uc.book();
        system("PAUSE");
        goto Refresh;
        break;

    case 2:
        uc.Search();
        system("PAUSE");
        goto Refresh;
    break;    

    case 3:
        uc.createAcc();
        system("PAUSE");
        goto Refresh;
    break;    

    case 4:
        ad.adminlogin();
        ad.createAdminAcc();
        system("PAUSE");
        goto  Refresh;
    break;

    case 5:
    uc.showCarsFromFile();
    uc.car_detail();
    uc.book();
    system("PAUSE");
    goto Refresh;
    break;

    case 6:
    system("CLS");
    uc.showTicket();
    system("PAUSE");
    goto Refresh;
    break;

    case 7:
    ad.adminlogin();
    ad.addCarCompany();
    system("PAUSE");
    goto Refresh;
    break;

    case 8:
    cout<<"\t YOU ARE LOGOUT\n";
    system("PAUSE");
    system("main.exe");
    break;

    default:
cout<<RED<<"   _____________===============================================================\n";
     cout<<" _/_|[][][][][] | - -|                :INVALID CHOICE RETRY:                  |\n";
    cout<<"(      City Bus | - -==========================================================\n";
    cout<<"=--OO-------OO--=dwb\n"<<RESET;
    system("PAUSE");
    goto Refresh;
    break;

    }
}