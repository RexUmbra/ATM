#include <iostream>
#include "ATM.h"
#include <thread>
using namespace std;
void f(ATM& user,int pCode,int money)
{
    user.getMoney(pCode);
    user.tookMoney(pCode,money);
    user.getMoney(pCode);
}
int main()
{
    ATM user(1111);
    ATM user2(2222);
    /*
    thread t1(f, ref(user), 1111,1000);
    thread t2(f, ref(user), 1111,2000);
    thread t3(f, ref(user), 1111,3000);
    thread t4(f, ref(user), 1111,4000);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    user.changeCode(1111,0000);
    user.getMoney(1111);
    user.getMoney(0000);
    */
    user.getMoney(1111);
    user2.getMoney(2222);
    user.transferMoney(user2,1111,1000);
    user.getMoney(1111);
    user2.getMoney(2222);
    return 0;
}
