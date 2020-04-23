#include "ATM.h"

ATM::ATM(int code) : code(code)
{
	money = 15000;
	
}

void ATM::getMoney(int pCode)
{
	m.lock();
	if (pCode == code)
	{
		std::cout << money << '\n';
	}
	else
	{
		std::cout << "wrong code\n";
	}
	m.unlock();
}

void ATM::tookMoney(int pCode, int amountMoney)
{
	m.lock();
	if (pCode == code)
	{
		if (amountMoney <= money)
		{
			money -= amountMoney;
		}
		else
		{
			std::cout << "few money\n";
		}
	}
	else
	{
		std::cout << "wrong code\n";
	}
	m.unlock();
}

void ATM::addMoney(int pCode, int amountMoney)
{
	m.lock();
	if (code == pCode)
	{
		money += amountMoney;
	}
	m.unlock();
}

void ATM::changeCode(int pCode, int newCode)
{
	m.lock();
	if (pCode == code)
	{
		code = newCode;
	}
	m.unlock();
}



