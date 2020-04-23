﻿#include <iostream>
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
    
    
    thread t1(f, ref(user), 1111,1000);
    thread t2(f, ref(user), 1111,2000);
    thread t3(f, ref(user), 1111,3000);
    thread t4(f, ref(user), 1111,4000);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}