#include "games.h"

using std::cout;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

double games::guessingGame()
{
	double result = 0;
	return 0;
}

void games::chooseGame(double currentBalance)
{
	int element = 0, x = 25;
	bool running = true;

	gotoXY(18, 22); cout << "~~ Your current balance: " << currentBalance << " USD ~~";
	gotoXY(18, 23); cout << "~~~ Choose game you want to play  ~~~";
	gotoXY(16, 25); cout << "->";

	while (running)
	{
		gotoXY(18, 25); cout << "~~~~~~~~~ Guessing game ~~~~~~~~~"; //REMEMER ADD LEVEREGE TO EACH GAME
		gotoXY(18, 26); cout << "~~~~~~~~~ In progress ~~~~~~~~~~~";
		gotoXY(18, 27); cout << "~~~~~~~~~ In progress ~~~~~~~~~~~";
		gotoXY(18, 28); cout << "~~~~~~~~~ In progress ~~~~~~~~~~~";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 28) //arrow down pressed
		{
			gotoXY(16, x); cout << "  ";
			x++;
			gotoXY(16, x); cout << "->";
			element++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 25) //arrow up pressed
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
					chooseGame(guessingGame());
					running = false;
					break;
				}
				case 1:
				{
					//next game here
					running = false;
					break;
				}
				case 2:
				{
					//next game here
					running = false;
					break;
				}
				case 3:
				{
					//next game here
					running = false;
				}
			}
		}
	}


}
