#pragma warning(disable : 4996)
#include "menu.h"

using std::cout;
using std::cin;
using std::string;

std::ofstream writeDatafile;
std::ifstream readDataFile;

string encryptingPassword(string);
string decryptingPassword(string);

std::vector<string> lines;
string usernameGet, passwordGet, balanceGet;


void menu::openBetaGame()
{
	games games;
	double balance = setStartingBalance();
	games.chooseGame(balance);
}


void menu::loginProcess()
{
	mainmenu mainmenu;

	string username = "";
	string password = "";
	
	mainmenu.gotoXY(18, 16); cout << "Enter your name: ";
	cin >> username;
	mainmenu.gotoXY(18, 17); cout << "Enter your password: ";
	cin >> password;
	mainmenu.clearingSpace();

	readDataFile.open("data" + username + ".txt");

	if (readDataFile.fail())
	{
		mainmenu.gotoXY(18, 16); cout << "There is no user named " << username << "!";
		cin.ignore();
		cin.get();
		mainmenu.clearingSpace();

		char* filename1 = new char[username.length() + 1];
		strcpy(filename1, "data");

		char* filename2 = new char[username.length() + 1];
		strcpy(filename2, username.c_str());

		char* filename3 = new char[username.length() + 1];
		strcpy(filename3, ".txt");

		char* filename = new char[username.length() + 1];
		strcpy(filename, filename1);
		strcpy(filename, filename2);
		strcpy(filename, filename3);


		remove(filename);
		delete[] filename1;
		delete[] filename2;
		delete[] filename3;
		delete[] filename;
		return;
	}

	getline(readDataFile, usernameGet);
	getline(readDataFile, passwordGet);
	getline(readDataFile, balanceGet);
	readDataFile.close();

	if (username == usernameGet && password == decryptingPassword(passwordGet))
	{
		mainmenu.gotoXY(18, 16); cout << "You logged in!";
		cin.ignore();
		cin.get();
		mainmenu.clearingSpace();

		games games;

		double balance = stod(balanceGet);
		games.chooseGame(balance);
	}
	else
	{
		mainmenu.gotoXY(18, 16); cout << "Wrong password!";
		cin.ignore();
		cin.get();
		mainmenu.clearingSpace();
		return;
	}
}


void menu::registrationProcess()
{
	mainmenu mainmenu;

	std::regex unRegex("^[a-zA-Z0-9\_\.]{3,50}$");
	std::regex pwRegex("^[a-zA-Z0-9\_\.\-]{8,50}$");

	string username = "", password = "";

	bool validation = true;

	while (validation)
	{
		mainmenu.gotoXY(18, 16); cout << "Enter your username: ";
		cin >> username;
		mainmenu.clearingSpace();
		if (!regex_match(username, unRegex))
		{
			mainmenu.gotoXY(18, 16); cout << "Username must be at least 3 characters long(letters, numbers, '_', '.')!";
			cin.ignore();
			cin.get();
			mainmenu.clearingSpace();
			continue;
		}
		else
		{
			writeDatafile.open("data" + username + ".txt");
			if (!writeDatafile.fail()) //checking if user already exists
			{
				mainmenu.gotoXY(18, 16); cout << "Username named " << username << " already exists!";
				cin.ignore();
				cin.get();
				mainmenu.clearingSpace();
				continue;
			}

			validation = false;
		}
	}

	validation = true;

	while (validation)
	{
		mainmenu.gotoXY(18, 16); cout << "Enter your password: ";
		cin >> password;
		mainmenu.clearingSpace();
		if (!regex_match(password, pwRegex))
		{
			mainmenu.gotoXY(18, 16); cout << "Password must be minimum eight characters, at least one letter, one number and one special character!";
			cin.ignore();
			cin.get();
			mainmenu.clearingSpace();
			continue;
		}
		else
		{
			validation = false;
		}
	}


	string securedPw = encryptingPassword(password);
	double balance = setStartingBalance();

	writeDatafile.open("data" + username + ".txt");
	writeDatafile << username << "\n" << securedPw << "\n" << balance;
	writeDatafile.close();

	mainmenu.gotoXY(18, 16); cout << "Account created successfully! Now you can login.";

	cin.ignore();
	cin.get(); //wait for the user to press enter

	mainmenu.clearingSpace();
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

double menu::setStartingBalance()
{
	mainmenu mainmenu;

	int menu_element = 0, x = 17;
	bool running = true;

	double startingBalance[4] = { 10, 100, 1000, 10000 };
	double chosenBalance = 0;

	mainmenu.gotoXY(18, 16); cout << "Choose your starting balance: ";
	mainmenu.gotoXY(16, 17); cout << "->";

	while (running)
	{
		mainmenu.gotoXY(18, 17); cout << "~~~~~~~~~~~~ 10 USD ~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 18); cout << "~~~~~~~~~~~ 100 USD ~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 19); cout << "~~~~~~~~~~ 1000 USD ~~~~~~~~~~~~~";
		mainmenu.gotoXY(18, 20); cout << "~~~~~~~~~ 10000 USD ~~~~~~~~~~~~~";

		system("pause>nul"); // the >nul bit causes it the print no message

		if (GetAsyncKeyState(VK_DOWN) && x != 20) //arrow down pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x++;
			mainmenu.gotoXY(16, x); cout << "->";
			menu_element++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && x != 17) //arrow up pressed
		{
			mainmenu.gotoXY(16, x); cout << "  ";
			x--;
			mainmenu.gotoXY(16, x); cout << "->";
			menu_element--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN)) //enter pressed
		{
			switch (menu_element)
			{
				case 0:
				{
					mainmenu.clearingSpace();
					running = false;
					chosenBalance = startingBalance[0];
					break;
				}
				case 1:
				{
					mainmenu.clearingSpace();
					running = false;
					chosenBalance = startingBalance[1];
					break;
				}
				case 2:
				{
					mainmenu.clearingSpace();
					running = false;
					chosenBalance = startingBalance[2];
					break;
				}
				case 3:
				{
					mainmenu.clearingSpace();
					running = false;
					chosenBalance = startingBalance[3];
					break;
				}
			}
		}
	}

	return chosenBalance;
}