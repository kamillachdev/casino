#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

using std::string;

class user
{
public:
	void showAccountBalance();
	void addBalance(double balance);
	void subtractBalance(double balance);
};

