#include "other.h"
#include "user.h"
// #include"admin.h"
using namespace std;

int main()
{
    userclass uc;
    admin ad;
    intro();
// Refresh
Refresh:
    showmenu();
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        system("CLS");
        headline2();
        uc.userLogin();
        system("CLS");
        goto Refresh;
        break;

    case 2:
        headline1();
        ad.adminlogin();
        break;

    case 3:
        system("CLS");
        uc.showCarsFromFile();
        uc.car_detail();
        uc.book();
        break;

    case 4:
        uc.Search();
        break;

    case 5:
        uc.createAcc();
        break;

    case 6:
        system("main.exe");
        break;

    case 7:
        uc.book();
        break;

    default:
        cout << RED << "==================================================" << endl;
        cout << RED << "         <<--SELECT CORRECT OPTION-->>" << RESET << endl;
        cout << RED << "==================================================" << endl;
        system("pause");
        system("main.exe");
        break;
    }
}