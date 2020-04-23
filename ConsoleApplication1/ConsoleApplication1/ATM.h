#pragma once
#include <iostream>
#include <mutex>
#include <random>
class ATM
{
private:
	int money;
	int code;
	mutable std::mutex m;
public:
	ATM(int code);
	void getMoney(int pCode);
	void tookMoney(int pCode, int amountMoney);
	void addMoney(int pCode, int amountMoney);
};

