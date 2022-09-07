#include "menu.h"

using std::cout;
using std::cin;
using std::string;


static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
static COORD CursorPosition; // used for goto

std::ofstream writeDatafile;
std::ifstream readDataFile;

string encryptingPassword(string);
string decryptingPassword(string);
double setStartingBalance();

static void gotoXY(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}


void menu::openBetaGame()
{
	games games;
	double balance = setStartingBalance();
	games.chooseGame(balance);
}


void menu::loginProcess()
{

}


void menu::registrationProcess()
{
	std::regex unRegex("^[a-zA-Z0-9\_\.]{3,50}$");
	std::regex pwRegex("^[a-zA-Z0-9\_\.\-]{8,50}$");

	string username = "", password = "";

	bool validation = true;

	while (validation)
	{
		gotoXY(18, 22); cout << "Enter your username: ";
		cin >> username;
		if (!regex_match(username, unRegex))
		{
			gotoXY(18, 23); cout << "Username must be at least 3 characters long(letters, numbers, '_', '.')!";
		}
		else
		{
			writeDatafile.open("data" + username + ".txt");
			if (!writeDatafile.fail()) //checking if user already exists
			{
				gotoXY(18, 23); cout << "Username named " << username << " already exists!";
				cin.ignore();
				cin.get();
				gotoXY(18, 22); cout << "                                                                        "; //clearing the ask
				gotoXY(18, 23); cout << "                                                                        "; //clearing the warning
				continue;
			}
			gotoXY(18, 22); cout << "                                                                        ";
			gotoXY(18, 23); cout << "                                                                        ";
			validation = false;
		}
	}

	validation = true;

	while (validation)
	{
		gotoXY(18, 22); cout << "Enter your password: ";
		cin >> password;
		if (!regex_match(password, pwRegex))
		{
			gotoXY(18, 23); cout << "Password must be minimum eight characters, at least one letter, one number and one special character!";
			gotoXY(39, 22); cout << "                                                         "; //clearing the wrong password
		}
		else
		{
			gotoXY(18, 22); cout << "                                                                                                     "; //clearing the ask
			gotoXY(18, 23); cout << "                                                                                                     "; //clearing the warning
			validation = false;
		}
	}


	string securedPw = encryptingPassword(password);
	double xbalance = setStartingBalance();

	writeDatafile.open("data" + username + ".txt");
	writeDatafile << username << "\n" << securedPw << "\n" << xbalance;
	writeDatafile.close();

	gotoXY(18, 22); cout << "Account created successfully! Now you can login.";

	cin.ignore();
	cin.get(); //wait for the user to press enter

	gotoXY(18, 22); cout << "                                                ";
}


string encryptingPassword(string password)
{
	for (int i = 0; (i < 50 && password[i] != '\0'); i++)
		password[i] = password[i] - 2; //simple encrypting using ASCII table
	return password;
}


string decryptingPassword(string password)
{
	for (int i = 0; (i < 50 && password[i] != '\0'); i++)
		password[i] = password[i] + 2; //simple decrypting using ASCII table
	return password;
}

double setStartingBalance()
{
	int element = 0, x = 24;
	bool running = true;
	double startingBalance[4] = { 10, 100, 1000, 10000 };
	double chosenBalance = 0;

	gotoXY(18, 22); cout << "Choose your starting balance: ";
	gotoXY(16, 24); cout << "->";
	while (running)
	{
		gotoXY(18, 24); cout << "~~~~~~~~~~~~ 10 USD ~~~~~~~~~~~~~";
		gotoXY(18, 25); cout << "~~~~~~~~~~~ 100 USD ~~~~~~~~~~~~~";
		gotoXY(18, 26); cout << "~~~~~~~~~~ 1000 USD ~~~~~~~~~~~~~";
		gotoXY(18, 27); cout << "~~~~~~~~~ 10000 USD ~~~~~~~~~~~~~";

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

	for (int i = 22; i <= 27; i++)
	{
		gotoXY(16, i); cout <<  "                                                        "; //clearing the whole choosing balance menu 
	}
	return chosenBalance;
}