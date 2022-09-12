#pragma once
#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <cstdio>
#include "mainmenu.h"
#include "games.h"
#include "user.h"

class menu
{
private:
	double setStartingBalance();
public:
	void openBetaGame();
	void loginProcess();
	void registrationProcess();
};

