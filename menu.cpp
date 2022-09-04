#include <iostream>
#include "menu.h"
#include "games.h"
#include "user.h"

using std::cout;

void openBetaGame()
{
	games games;
	double startingBalance[4] = { 10, 100, 1000, 10000 };
	double chosenBalance = 0;
	cout << "Choose your starting balance";
	cout << "->";
	cout << "~~~~~~~~~~ 10 USD ~~~~~~~~~~";
	cout << "~~~~~~~~~ 100 USD ~~~~~~~~~~";
	cout << "~~~~~~~~ 1000 USD ~~~~~~~~~~";
	cout << "~~~~~~~ 10000 USD ~~~~~~~~~~";

	chosenBalance = startingBalance[0];
	games.chooseGame(chosenBalance);

}
