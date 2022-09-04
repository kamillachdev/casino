#include <iostream>

using std::string;

class user
{
private:
	string username;
	string password;
	double accountBalance;
public:
	user(); //empty constructor
	user(string un, string pw); //full constructor

	bool loginValidation(string unC, string pwC);

	void showAccountBalance();
	void setStartingBalance(double balance);
	void addBalance(double balance);
	void subtractBalance(double balance);

	~user(); //destructor
};

