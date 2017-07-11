#include<graphics.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
void starting (void)
{
    int i,x;
    cleardevice();
    char img_name[10];
    sndPlaySound("sound/wolverine.wav", SND_FILENAME | SND_ASYNC);
    //add wolverine sound
    for(int i=0; i<4; i=i+1)
    {
        sprintf(img_name,"wolverin3d//%d.jpg",i);
        readimagefile(img_name,0,0,800,600);
        delay(1000);
    }
    //flying bee video
    delay(500);
    cleardevice();
    clearviewport();
    char flying_img[260];
    sndPlaySound("sound/bee.wav", SND_FILENAME | SND_ASYNC );
    for(i=1; i<=243&&!kbhit(); i++)
    {
        sprintf(flying_img,"beevideo//bee %d.jpg",i);
        readimagefile(flying_img,0,0,800,600);
        delay(58);
    }
    if(kbhit())
        char nothing=getch();
    //  loading
    //add loading sound
    sndPlaySound("sound/angry bird2.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    cleardevice();
    clearviewport();
    char load[45];
    for(i=25; i<=64; i++)
    {

        sprintf(load,"loading//loading %d.jpg",i);
        readimagefile(load,0,0,800,600);
        delay(40);
    }
    setcolor(8);
    delay(700);
    for( x=51; x<602; x=x+3)
    {

        readimagefile("loading//loading.jpg",x,536 ,x+55,589);
        setbkcolor(4);
        bar(x, 535,x+1, 589);
        setfillstyle(rand()%3,2);
        delay(1);
    }
    //welcome load>>>>>>>
    //add welcm sound

    char wl_cm[60];
    for(i=1; i<=60; i++)
    {
        sprintf(wl_cm,"welcome//welcome %d.jpg",i);
        readimagefile(wl_cm,0,0,800,600);
        delay(6);
    }
    cleardevice();
    clearviewport();
}
