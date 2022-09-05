#include "menu.h"

using std::cout;

static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
static COORD CursorPosition; // used for goto

static void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

menu::menu()
{

}

void menu::openBetaGame()
{
	games games;
	int element = 0, x = 24;
	bool running = true;
	double startingBalance[4] = { 10, 100, 1000, 10000 };
	double chosenBalance = 0;

	gotoXY(18, 22);cout << "Choose your starting balance: ";
	gotoXY(16, 24); cout << "->";
	while (running)
	{
		gotoXY(18, 24);cout << "~~~~~~~~~~~~ 10 USD ~~~~~~~~~~~~~";
		gotoXY(18, 25);cout << "~~~~~~~~~~~ 100 USD ~~~~~~~~~~~~~";
		gotoXY(18, 26);cout << "~~~~~~~~~~ 1000 USD ~~~~~~~~~~~~~";
		gotoXY(18, 27);cout << "~~~~~~~~~ 10000 USD ~~~~~~~~~~~~~";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 27) //arrow down pressed
		{
			gotoXY(16, x); cout << "  ";
			x++;
			gotoXY(16, x); cout << "->";
			element++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 24) //arrow up pressed
		{
			gotoXY(16, x); cout << "  ";
			x--;
			gotoXY(16, x); cout << "->";
			element--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) //enter pressed
		{
			switch (element)
			{
				case 0:
				{
					chosenBalance = startingBalance[0];
					running = false;
					break;
				}
				case 1:
				{
					chosenBalance = startingBalance[1];
					running = false;
					break;
				}
				case 2:
				{
					chosenBalance = startingBalance[2];
					running = false;
					break;
				}
				case 3:
				{
					chosenBalance = startingBalance[3];
					running = false;
				}
			}
		}
	}
	games.chooseGame(chosenBalance);
}

void menu::loginProcess()
{

}

void menu::registrationProcess()
{

}

menu::~menu()
{

}