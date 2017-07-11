#include <iostream>
#include <graphics.h>
#include <conio.h>
using namespace std;

void starting (void);
void main_menu (void);

int main()
{
    initwindow(800, 600, "TASTE OF HONEY",50, 50, false, false);
    starting();
    main_menu();
    getch();
    return 0;
}
