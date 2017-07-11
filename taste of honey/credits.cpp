#include<graphics.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
void main_menu(void);
void credits()
{
    cleardevice();
    char credit[45];
    sndPlaySound("sound/click.wav", SND_FILENAME | SND_ASYNC);
    for(int i=1; i<=48; i+=1)
    {
        sprintf(credit,"credits//credit//credit %d.jpg",i);
        readimagefile(credit,0,0,804,600);
        delay(65);
    }
    sndPlaySound("sound/angry bird2.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    getch();
    cleardevice();
    clearviewport();
}
