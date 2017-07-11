#include<graphics.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
void option(void)
{
    cleardevice();
    clearviewport();
    char PLAY[60];
    sndPlaySound("sound/click.wav", SND_FILENAME | SND_ASYNC);
    for(int i=8; i<=66; i+=1)
    {
        sprintf(PLAY,"option//play//play %d.jpg",i);
        readimagefile(PLAY,0,0,804,600);
        delay(29);
    }
    sndPlaySound("sound/angry bird2.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    getch();
    cleardevice();
    clearviewport();
}
