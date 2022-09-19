#include "games.h"

using std::cout;



double games::guessingGame()
{
	double result = 0;
	return 0;
}

void games::chooseGame(double currentBalance)
{
	mainmenu mainmenu;

	int element = 0, x = 16;
	bool running = true;

	mainmenu.gotoXY(18, 14); cout <<	 "Your current balance: " << currentBalance << " USD";
	mainmenu.gotoXY(18, 15); cout <<	 "~~~ Choose game you want to play  ~~~";
	mainmenu.gotoXY(16, 16); cout <<     "->";

	while (running)
	{
		mainmenu.gotoXY(18, 16); cout << "~~~~~~~~~~~ Guessing game ~~~~~~~~~~~"; //REMEMER ADD LEVEREGE TO EACH GAME
		mainmenu.gotoXY(18, 17); cout << "~~~~~~~~~~~ In progress ~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 18); cout << "~~~~~~~~~~~ In progress ~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 19); cout << "~~~~~~~~~~~ In progress ~~~~~~~~~~~~~";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 19) //arrow down pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x++;
			mainmenu.gotoXY(16, x); cout << "->";
			element++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 16) //arrow up pressed
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
					mainmenu.clearingSpace();
					chooseGame(guessingGame());
					running = false;
					break;
				}
				case 1:
				{
					//next game here
					mainmenu.clearingSpace();
					running = false;
					break;
				}
				case 2:
				{
					//next game here
					mainmenu.clearingSpace();
					running = false;
					break;
				}
				case 3:
				{
					//next game here
					mainmenu.clearingSpace();
					running = false;
				}
			}
		}
	}
}
