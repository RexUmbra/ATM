#include <iostream>
#include "ATM.h"
#include <thread>
#include <string>
using namespace std;
void f(ATM& user,int pCode,int money)
{
    user.getMoney(pCode);
    user.tookMoney(pCode,money);
    user.getMoney(pCode);
}
void transferMoney(ATM& user1, ATM& user2, int code1, int code2, int money)
{
    user1.tookMoney(code1,money);
    user2.addMoney(code2, money);
}
int main()
{
    int code, id;
    cout << "Write code and ID\n";
    cin >> code >> id;
    ATM user(code);
    while (true)
    {
        
        cout << "Do you will make move?(yes/no)\n";
        string str;
        cin >> str;
        system("cls");
        if (str == "yes")
        {
            cout << "1-look at amount money.\n2-took money.\n3-add money.\n4-change password\n";
            int f;
            cin >> f;
            system("cls");
            if (f == 1)
            {
                int pass;
                cout << "write password\n";
                cin >> pass;
                user.getMoney(pass);
            }
            else if(f ==2)
            {
                int pass,money;
                cout << "write password\n";
                cin >> pass;
                system("cls");
                cout << "write amount money\n";
                cin >> money;
                system("cls");
                user.tookMoney(pass, money);
            }
            else if (f == 3)
            {
                int pass, money;
                cout << "write password\n";
                cin >> pass;
                system("cls");
                cout << "write amount money\n";
                cin >> money;
                system("cls");
                user.addMoney(pass,money);
            }
            else if (f == 4)
            {
                int pass, npass; 
                cout << "write password\n";
                cin >> pass;
                system("cls");
                cout << "write new pass";
                cin >> npass;
                user.changeCode(pass, npass);
            }

        }
        else
        {
            break;
        }
        
        
    }
    
    return 0;
}
