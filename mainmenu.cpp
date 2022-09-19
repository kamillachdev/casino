#include "mainmenu.h"

using std::cout;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto


void mainmenu::baner()
{
    //the appearance of the menu
    system("Color 0A");
    cout << "\n=======================================================================";
    cout << "\n BBBBBBB   UU   UU   LL       LL      IIIIIIIII    SSSSSSSSS   HH    HH";
    cout << "\n BB   BB   UU   UU   LL       LL         III       SS          HH    HH";
    cout << "\n BBBBBB    UU   UU   LL       LL         III       SSSSSSSSS   HHHHHHHH";
    cout << "\n BB   BB   UU   UU   LL       LL         III              SS   HH    HH";
    cout << "\n BBBBBBB    UUUUU    LLLLLL   LLLLLL  IIIIIIIII    SSSSSSSSS   HH    HH";
    cout << "\n=======================================================================";
    cout << "\n   CCCCC       A        SSSSSSSSS    IIIIIIIII   NN     NN    OOOOOOOO ";
    cout << "\n CC           A  A      SS              III      NN N   NN   OO      OO";
    cout << "\nCC           A    A     SSSSSSSSS       III      NN  N  NN   OO      OO";
    cout << "\n CC         AAAAAAAA           SS       III      NN   N NN   OO      OO";
    cout << "\n   CCCCC   A        A   SSSSSSSSS    IIIIIIIII   NN     NN    OOOOOOOO ";
    cout << "\n=======================================================================";
}

void mainmenu::mainMenu()
{
    menu menu;
    int menu_element = 0, x = 16;
    bool running = true;

    gotoXY(16, 16); cout << "->";

    while (running)
    {
        gotoXY(18, 16); cout << "~~~~  PLAY AS A DEMO USER    ~~~~";
        gotoXY(18, 17); cout << "~~~~  LOG IN TO YOUR ACCOUNT ~~~~";
        gotoXY(18, 18); cout << "~~~~  CREATE A NEW ACCOUNT   ~~~~";
        gotoXY(18, 19); cout << "~~~~       QUIT CASINO       ~~~~";

        system("pause>nul"); // the >nul bit causes it the print no message

        if (GetAsyncKeyState(VK_DOWN) && x != 19) //arrow down pressed
        {
            gotoXY(16, x); cout << "  ";
            x++;
            gotoXY(16, x); cout << "->";
            menu_element++;
            continue;
        }

        if (GetAsyncKeyState(VK_UP) && x != 16) //arrow up pressed
        {
            gotoXY(16, x); cout << "  ";
            x--;
            gotoXY(16, x); cout << "->";
            menu_element--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN)) //enter pressed
        {
            switch (menu_element)
            {
                case 0:
                {
                    clearingSpace();
                    menu.openBetaGame();
                    break;
                }
                case 1:
                {
                    clearingSpace();
                    menu.loginProcess();
                    break;
                }
                case 2:
                {
                    clearingSpace();
                    menu.registrationProcess();
                    break;
                }
                case 3:
                {
                    exit(1);
                }
            }
        }
    }
}

void mainmenu::gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void mainmenu::clearingSpace()
{
    for (int i = 14; i <= 28; i++)
    {
        gotoXY(16, i); cout << "                                                                                                          "; //clearing the space
    }
}