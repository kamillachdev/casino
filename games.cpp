#include "games.h"

using std::cout;



double games::guessingGame()
{
	mainmenu mainmenu;

	double result = 0;
	return 0;
}

void games::chooseGame(double currentBalance)
{
	mainmenu mainmenu;

	int element = 0, x = 25;
	bool running = true;

	mainmenu.gotoXY(18, 22); cout << "~~ Your current balance: " << currentBalance << " USD ~~";
	mainmenu.gotoXY(18, 23); cout << "~~~ Choose game you want to play  ~~~";
	mainmenu.gotoXY(16, 25); cout << "->";

	while (running)
	{
		mainmenu.gotoXY(18, 25); cout << "~~~~~~~~~ Guessing game ~~~~~~~~~"; //REMEMER ADD LEVEREGE TO EACH GAME
		mainmenu.gotoXY(18, 26); cout << "~~~~~~~~~ In progress ~~~~~~~~~~~";
		mainmenu.gotoXY(18, 27); cout << "~~~~~~~~~ In progress ~~~~~~~~~~~";
		mainmenu.gotoXY(18, 28); cout << "~~~~~~~~~ In progress ~~~~~~~~~~~";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 28) //arrow down pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x++;
			mainmenu.gotoXY(16, x); cout << "->";
			element++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 25) //arrow up pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x--;
			mainmenu.gotoXY(16, x); cout << "->";
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
	for (int i = 22; i <= 29; i++)
	{
		mainmenu.gotoXY(16, i); cout << "                                                        "; //clearing space
	}

}
