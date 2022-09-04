#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using std::cout;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int, int);

int main()
{
    int menu_element = 0, x = 16;
    bool running = true;

    //the appearance of the menu
    system("Color 0A");
    cout << "\n=======================================================================";
    cout << "\n BBBBBBB   UU   UU   LL       LL      IIIIIIIII    SSSSSSSSS   HH    HH";
    cout << "\n BB   BB   UU   UU   LL       LL         III       SS          HH    HH ";
    cout << "\n BBBBBB    UU   UU   LL       LL         III       SSSSSSSSS   HHHHHHHH ";
    cout << "\n BB   BB   UU   UU   LL       LL         III              SS   HH    HH ";
    cout << "\n BBBBBBB    UUUUU    LLLLLL   LLLLLL  IIIIIIIII    SSSSSSSSS   HH    HH ";
    cout << "\n=======================================================================";
    cout << "\n   CCCCC       A        SSSSSSSSS    IIIIIIIII   NN     NN    OOOOOOOO  ";
    cout << "\n CC           A  A      SS              III      NN N   NN   OO      OO ";
    cout << "\nCC           A    A     SSSSSSSSS       III      NN  N  NN   OO      OO ";
    cout << "\n CC         AAAAAAAA           SS       III      NN   N NN   OO      OO ";
    cout << "\n   CCCCC   A        A   SSSSSSSSS    IIIIIIIII   NN     NN    OOOOOOOO  ";
    cout << "\n=======================================================================";

    gotoXY(60, 16); cout << "->";

    while (running)
    {
        gotoXY(62, 16); cout << "~~~~  PLAY AS A DEMO USER    ~~~~";
        gotoXY(62, 17); cout << "~~~~  LOG IN TO YOUR ACCOUNT ~~~~";
        gotoXY(62, 18); cout << "~~~~  CREATE A NEW ACCOUNT   ~~~~";
        gotoXY(62, 19); cout << "~~~~       QUIT CASINO       ~~~~";

        system("pause>nul"); // the >nul bit causes it the print no message

        if (GetAsyncKeyState(VK_DOWN) && x != 19) //arrow down pressed
        {
            gotoXY(60, x); cout << "  ";
            x++;
            gotoXY(60, x); cout << "->";
            menu_element++;
            continue;
        }

        if (GetAsyncKeyState(VK_UP) && x != 16) //arrow up pressed
        {
            gotoXY(60, x); cout << "  ";
            x--;
            gotoXY(60, x); cout << "->";
            menu_element--;
            continue;
        }

        if (GetAsyncKeyState(VK_RETURN)) //enter pressed
        {
            switch (menu_element)
            {
                case 0:
                {
                    //here gon be function
                    break;
                }
                case 1:
                {
                    //here gon be function
                    break;
                }
                case 2:
                {
                    //here gon be function
                    break;
                }
                case 3:
                {
                    //here gon be function
                    running = false;
                }
            }
        }
    }
    return 0;
}

void gotoXY(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}