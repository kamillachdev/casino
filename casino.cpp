#include <iostream>
#include "mainmenu.h"
#include "user.h"
#include "menu.h"

int main()
{
    mainmenu mainmenu;
    mainmenu.baner(); //bullish casino writting
    while (true)
    {
        mainmenu.mainMenu(); //main menu
    }
    return 0;
}