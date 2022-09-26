#include "games.h"

using std::cout;

enum difficulty
{
	easy,
	medium,
	hard,
	very_hard
};

int chooseDifficulty()
{
	mainmenu mainmenu;
	difficulty chosen;
	int menu_element = 0, x = 16;
	bool running = true;

	mainmenu.gotoXY(16, 16); cout << "->";

	while (running)
	{
		mainmenu.gotoXY(18, 15); cout << "Choose your difficulty: ";
		mainmenu.gotoXY(18, 16); cout << "~~~~~~~~~~~ Easy x0.5 ~~~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 17); cout << "~~~~~~~~~~~ Medium x1 ~~~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 18); cout << "~~~~~~~~~~~ Hard x2 ~~~~~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 19); cout << "~~~~~~~~~~~ Very hard x3 ~~~~~~~~~~~~";

		if (GetAsyncKeyState(VK_DOWN) && x != 19) //arrow down pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x++;
			mainmenu.gotoXY(16, x); cout << "->";
			menu_element++;
			continue;
		}
		else if (GetAsyncKeyState(VK_UP) && x != 16) //arrow up pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x--;
			mainmenu.gotoXY(16, x); cout << "->";
			menu_element--;
			continue;
		}
		else if (GetAsyncKeyState(VK_RETURN)) //enter pressed
		{
			switch (menu_element)
			{
				case 0:
				{
					mainmenu.clearingSpace();
					chosen = easy;
					return chosen;
				}
				case 1:
				{
					//next game here
					mainmenu.clearingSpace();
					chosen = medium;
					return chosen;
				}
				case 2:
				{
					//next game here
					mainmenu.clearingSpace();
					chosen = hard;
					return chosen;
				}
				case 3:
				{
					//next game here
					mainmenu.clearingSpace();
					chosen = very_hard;
					return chosen;
				}
			}
		}
	}
}


void games::chooseGame(double currentBalance)
{
	mainmenu mainmenu;

	if (currentBalance <= 0)
	{
		cout << "You don't have any funds anymore! GAME OVER";
		std::cin.get();
		mainmenu.clearingSpace();
	}

	int menu_element = 0, x = 16;
	bool running = true;

	mainmenu.gotoXY(18, 14); cout <<	 "Your current balance: " << currentBalance << " USD";
	mainmenu.gotoXY(18, 15); cout <<	 "~~~ Choose game you want to play  ~~~";
	mainmenu.gotoXY(16, 16); cout <<     "->";

	while (running)
	{
		mainmenu.gotoXY(18, 16); cout << "~~~~~~~~~~~ Guessing game ~~~~~~~~~~~";
		mainmenu.gotoXY(18, 17); cout << "~~~~~~~~~~~ In progress ~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 18); cout << "~~~~~~~~~~~ In progress ~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 19); cout << "~~~~~~~~~~~ Log out  ~~~~~~~~~~~~~~~~";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && x != 19) //arrow down pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x++;
			mainmenu.gotoXY(16, x); cout << "->";
			menu_element++;
			continue;
		}
		else if (GetAsyncKeyState(VK_UP) && x != 16) //arrow up pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x--;
			mainmenu.gotoXY(16, x); cout << "->";
			menu_element--;
			continue;
		}
		else if (GetAsyncKeyState(VK_RETURN)) //enter pressed
		{
			switch (menu_element)
			{
				case 0:
				{
					mainmenu.clearingSpace();
					chooseGame(currentBalance + guessingGame());
					break;
				}
				case 1:
				{
					//next game here
					mainmenu.clearingSpace();
					break;
				}
				case 2:
				{
					//next game here
					mainmenu.clearingSpace();
					break;
				}
				case 3:
				{
					mainmenu.clearingSpace();
					running = false;
				}
			}
		}
		else
		{
			continue;
		}
	}
}


double games::guessingGame()
{
	mainmenu mainmenu;

	double result = 0, win_loss = 0, numbersAmount = 0, lives = 0;

	int mode = chooseDifficulty();
	int drawnNumber = 0, guess = 0;
	bool gameState = 1;

	srand(time(NULL));

	switch (mode)
	{
	case 0:
		win_loss = 10;
		numbersAmount = 10;
		lives = 4;
		drawnNumber = rand() % 10 + 1;
		break;
	case 1:
		win_loss = 50;
		numbersAmount = 50;
		lives = 8;
		drawnNumber = rand() % 50 + 1;
		break;
	case 2:
		win_loss = 100;
		numbersAmount = 100;
		lives = 10;
		drawnNumber = rand() % 100 + 1;
		break;
	case 3:
		win_loss = 300;
		numbersAmount = 200;
		lives = 10;
		drawnNumber = rand() % 200 + 1;
		break;
	default:
		win_loss = 50;
		numbersAmount = 50;
		lives = 8;
		drawnNumber = rand() % 50 + 1;
	}

	while (gameState)
	{
		mainmenu.gotoXY(18, 15); cout << "You have " << lives << " lives, " << "range from 1 to " << numbersAmount << ", guess the number: ";
		std::cin >> guess;
		if (lives > 0)
		{
			if (guess > drawnNumber)
			{
				mainmenu.gotoXY(18, 16); cout << "Smaller number!                                           ";
				lives--;
			}
			else if (guess < drawnNumber)
			{
				mainmenu.gotoXY(18, 16); cout << "Larger number!                                            ";
				lives--;
			}
			else
			{
				gameState = false;
				mainmenu.gotoXY(18, 16); cout << "Congratulation, you guessed the correct number!           ";
				result = win_loss;
			}
		}
		else
		{
			gameState = false;
			mainmenu.gotoXY(18, 16); cout << "You don't have any hearts left, you lost!              ";
			result = win_loss * -1;
		}
		mainmenu.clearingSpace();
	}
	
	return result;
}
