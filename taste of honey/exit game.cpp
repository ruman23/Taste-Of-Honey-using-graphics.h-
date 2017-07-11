#include<graphics.h>
#include <iostream>
using namespace std;
//void main_menu(void);
void exit(void)
{
    cleardevice();
    readimagefile("newexit//exit1.jpg",0,0,800,600);
    readimagefile("newexit//exit2.jpg",0,0,800,600);
    getch();
}
