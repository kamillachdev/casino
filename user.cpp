#include "user.h"

using std::cout;

user::user()
{
	username = "";
	password = "";
	accountBalance = 0;
}

user::user(string un, string pw)
{
	username = un;
	password = pw;
	accountBalance = setStartingBalance();
}

bool user::loginValidation(string unC, string pwC)
{
	return true;
}

void user::showAccountBalance()
{

}

double user::setStartingBalance()
{
	double startingBalance[4] = { 10, 100, 1000, 10000 };
	double chosenBalance = 0;
	cout << "Choose your starting balance";
	cout << "->";
	cout << "~~~~~~~~~~ 10 USD ~~~~~~~~~~";
	cout << "~~~~~~~~~ 100 USD ~~~~~~~~~~";
	cout << "~~~~~~~~ 1000 USD ~~~~~~~~~~";
	cout << "~~~~~~~ 10000 USD ~~~~~~~~~~";

	chosenBalance = startingBalance[0];
	return chosenBalance;
}


void user::addBalance(double balance)
{

}

void user::subtractBalance(double balance)
{

}

user::~user()
{

}