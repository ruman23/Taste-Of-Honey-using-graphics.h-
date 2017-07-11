#include<graphics.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <fstream>
using namespace std;
void BEE_CONTROL();
void BIRD_PRINT();
void NEW_BIRD();
void KILLING_BIRD();
void LIFE();
void CONGRATULATION();
void SORRY();
void main_menu();
void LEVEL_TWO();
void store_high_score_1(int);
int point_1=2,outrandom_1[1000],r_1=2,j_1,b1_1=1,b2_1=1,b3_1=1,SPEED_1=15,i_1=0,dly_1=2,life_1=3,k_1=1;
int b1x1_1,b1x2_1,b2x1_1,b2x2_1,b3x1_1,b3x2_1,scores_1=0;
char key_1,bird_1[20],bee_1[20],score_1[5]= {'0','0','0'};
void LEVEL_ONE()
{
    cleardevice();
    clearviewport();
    while(i_1<1000)
    {
        outrandom_1[i_1]=rand()%500+150;
        i_1++;
    }
    //  sndPlaySound("sound/angry bird2.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    sndPlaySound("sound/level.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);

    readimagefile("SL IMG//img//background.jpg",0,0,800,600); /// full back cover
    readimagefile("SL IMG//img//sky3.jpg",0,0,800,230);
    /// new bird adding er sathe sathe r er value 1 increase krte hbe
    b1x1_1=-outrandom_1[0];
    b1x2_1=b1x1_1+124;
    b2x1_1=(-outrandom_1[1]-200);
    b2x2_1=b2x1_1+124;
    b3x1_1=-outrandom_1[2];
    b3x2_1=b3x1_1+124;
    readimagefile("SL IMG//img//sword 2.jpg",657,355,800,465);         ///img in posn 2
    readimagefile("SL IMG//img//life3.jpg",74,0,300,75); ///life 3
    setbkcolor(WHITE);
    setcolor(RED);
    settextstyle(1,0,4);
    while(life_1)/// life
    {
        sprintf(score_1,"%d",scores_1);
        outtextxy(680,10,score_1);
        if(SPEED_1>=40)///max SPEED_1 condition
            SPEED_1=40;
        BIRD_PRINT();
        NEW_BIRD();///+ dying bee
        ///killing bird condition and new bird print
        KILLING_BIRD();
        while(kbhit())          /// bee control
        {
            key_1=getch();
            BEE_CONTROL();
        }
        delay(dly_1);
    }
    store_high_score_1(scores_1);
    sndPlaySound("sound/angry bird2.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    if(scores_1>=300)
    {
        CONGRATULATION();
        LEVEL_TWO();
    }

    else
        SORRY();
    point_1=2;
    r_1=2;
    b1_1=1;
    b2_1=1;
    b3_1=1;
    SPEED_1=15;
    i_1=0;
    dly_1=2;
    life_1=3;
    k_1=1;
    scores_1=0;
    main_menu();
}
void BEE_CONTROL()
{
    if(key_1==72||key_1=='w')
    {
        if(point_1==2)
        {
            point_1=3;
            readimagefile("SL IMG//img//back.jpg",657,355,800,465);///back in 2
            readimagefile("SL IMG//img//sword 2.jpg",657,230,800,340);///img in posn 3
        }
        else if(point_1==1)
        {

            point_1=2;
            readimagefile("SL IMG//img//back.jpg",657,480,800,590);///back in 1
            readimagefile("SL IMG//img//sword 2.jpg",657,355,800,465);///img in posn 2
        }
    }
    else if(key_1==80||key_1=='s')
    {
        if(point_1==3)
        {
            point_1=2;
            readimagefile("SL IMG//img//back.jpg",657,230,800,340);///back in 3
            readimagefile("SL IMG//img//sword 2.jpg",657,355,800,465);///img in posn 2
        }
        else if(point_1==2)
        {
            readimagefile("SL IMG//img//back.jpg",657,355,800,465);///img in 2
            point_1=1;
            readimagefile("SL IMG//img//sword 2.jpg",657,480,800,590);///img in posn 1
        }
    }
    else if(key_1==32)
    {
        // outtextxy(385,300,"PAUSED");
        int a=getch();
    }
}
void BIRD_PRINT()
{
    sprintf(bird_1,"SL IMG//bird1//%d.jpg",b1_1);
    readimagefile(bird_1,b1x1_1,480,b1x2_1,590);/// bird 1 bottom position
    readimagefile("SL IMG//img//back.jpg",b1x1_1-124,480,b1x2_1-124,590);///back 1
    sprintf(bird_1,"SL IMG//bird1//%d.jpg",b2_1);
    readimagefile(bird_1,b2x1_1,355,b2x2_1,465);/// bird 2 mid position
    readimagefile("SL IMG//img//back.jpg",b2x1_1-124,355,b2x2_1-124,465);///back 2
    sprintf(bird_1,"SL IMG//bird1//%d.jpg",b3_1);
    readimagefile(bird_1,b3x1_1,230,b3x2_1,340);/// bird 3 top position
    readimagefile("SL IMG//img//back.jpg",b3x1_1-124,230,b3x2_1-124,340);///back 3
}
void NEW_BIRD()
{
    b1_1++;/// bird 1 start
    if(b1_1>=42)
        b1_1=1;
    if(b1x2_1>=730)
    {
        LIFE();///**********////
        readimagefile("SL IMG//img//back.jpg",b1x1_1,480,b1x2_1,590);///back 1
        readimagefile("SL IMG//img//swordcross.jpg",657,480,800,590);///sword cross in posn 1
        delay(30);
        if(point_1==1)
            readimagefile("SL IMG//img//sword 2.jpg",657,480,800,590);///sword in posn 1
        else
            readimagefile("SL IMG//img//back.jpg",657,480,800,590);///back 1
        r_1++;
        b1x1_1=-outrandom_1[r_1];
        b1x2_1=b1x1_1+124;
        SPEED_1+=1;
    }
    b1x1_1+=SPEED_1;
    b1x2_1+=SPEED_1;
    /// bird 1 end
    b2_1++;/// bird 2 start
    if(b2_1>=42)
        b2_1=1;
    if(b2x2_1>=730)
    {
        LIFE();///**********////
        readimagefile("SL IMG//img//back.jpg",b2x1_1,355,b2x2_1,465);///back 2
        readimagefile("SL IMG//img//swordcross.jpg",657,355,800,465);///sword cross in posn 2
        delay(30);
        if(point_1==2)
            readimagefile("SL IMG//img//sword 2.jpg",657,355,800,465);///sword in posn 2
        else
            readimagefile("SL IMG//img//back.jpg",657,355,800,465);///img in 2
        r_1++;
        b2x1_1=(-outrandom_1[r_1]);
        b2x2_1=b2x1_1+124;
        ///dly-=1;
    }
    b2x1_1+=SPEED_1;
    b2x2_1+=SPEED_1;
    /// bird 2 end
    b3_1++;/// bird 3 start
    if(b3_1>=42)
        b3_1=1;
    if(b3x2_1>=730)
    {
        LIFE();///**********////
        readimagefile("SL IMG//img//back.jpg",b3x1_1,230,b3x2_1,340);///back 3
        readimagefile("SL IMG//img//swordcross.jpg",657,230,800,340);///sword cross in posn 3
        delay(30);
        if(point_1==3)
            readimagefile("SL IMG//img//sword 2.jpg",657,230,800,340);///sword in posn 3
        else
            readimagefile("SL IMG//img//back.jpg",657,230,800,340);///img in 3
        r_1++;
        b3x1_1=-outrandom_1[r_1];
        b3x2_1=b3x1_1+124;
        /// dly-=1;
    }
    b3x1_1+=SPEED_1;
    b3x2_1+=SPEED_1;
    /// bird 3 end
}
void KILLING_BIRD()
{
    if(b1x2_1>=657&&b1x1_1<730&&point_1==1)///bottom
    {
        scores_1+=10;
        SPEED_1+=1;
        // readimagefile("SL IMG//img//blood1.jpg",b1x1_1-SPEED_1,480,b1x2_1-SPEED_1,590);///blood in 1
        // delay(8);
        readimagefile("SL IMG//img//blood2.jpg",b1x1_1-SPEED_1,480,b1x2_1-SPEED_1,590);///blood in 1
        delay(8);
        readimagefile("SL IMG//img//blood2.jpg",b1x1_1-SPEED_1,480,b1x2_1-SPEED_1,590);///blood in 1
        delay(8);
        readimagefile("SL IMG//img//back.jpg",b1x1_1-SPEED_1,480,b1x2_1-SPEED_1,590);///back 1
        readimagefile("SL IMG//img//sword 2.jpg",657,480,800,590);///sword in posn 1
        r_1++;
        b1x1_1=-outrandom_1[r_1];
        b1x2_1=b1x1_1+124;
    }
    else if(b2x2_1>=657&&b2x1_1<730&&point_1==2)///mid
    {
        scores_1+=10;
        //  readimagefile("SL IMG//img//blood1.jpg",b2x1_1-SPEED_1,355,b2x2_1-SPEED_1,465);///blood in 2
        //  delay(8);
        readimagefile("SL IMG//img//blood2.jpg",b2x1_1-SPEED_1,355,b2x2_1-SPEED_1,465);///blood in 2
        delay(8);
        readimagefile("SL IMG//img//blood2.jpg",b2x1_1-SPEED_1,355,b2x2_1-SPEED_1,465);///blood in 2
        delay(8);
        readimagefile("SL IMG//img//back.jpg",b2x1_1-SPEED_1,355,b2x2_1-SPEED_1,465);///back 1
        readimagefile("SL IMG//img//sword 2.jpg",657,355,800,465);///sword in posn 2
        r_1++;
        b2x1_1=-outrandom_1[r_1];
        b2x2_1=b2x1_1+124;
    }
    else if(b3x2_1>=657&&b3x1_1<730&&point_1==3)///top
    {
        scores_1+=10;
        // readimagefile("SL IMG//img//blood1.jpg",b3x1_1-SPEED_1,230,b3x2_1-SPEED_1,340);///blood in 3
        // delay(8);
        readimagefile("SL IMG//img//blood2.jpg",b3x1_1-SPEED_1,230,b3x2_1-SPEED_1,340);///blood in 3
        delay(8);
        readimagefile("SL IMG//img//blood2.jpg",b3x1_1-SPEED_1,230,b3x2_1-SPEED_1,340);///blood in 3
        delay(8);
        readimagefile("SL IMG//img//back.jpg",b3x1_1-SPEED_1,230,b3x2_1-SPEED_1,340);///back 1
        readimagefile("SL IMG//img//sword 2.jpg",657,230,800,340);///sword in posn 3
        r_1++;
        b3x1_1=-outrandom_1[r_1];
        b3x2_1=b3x1_1+124;
    }
}
void LIFE()
{
    life_1-=1;
    if(life_1==2)
        readimagefile("SL IMG//img//life2.jpg",74,0,300,75); ///life 2
    else if(life_1==1)
        readimagefile("SL IMG//img//life1.jpg",74,0,300,75); ///life 1
    else if(life_1==0)
    {
        readimagefile("SL IMG//img//life0.jpg",74,0,300,75); ///life 0
        //  delay(100);
    }
}

void CONGRATULATION()
{
    readimagefile("SL IMG//img//congratulation1.jpg",0,230,800,600);
    delay(800);
    readimagefile("SL IMG//img//congratulation2.jpg",0,230,800,600);
    readimagefile("SL IMG//img//tv1.jpg",195,360,604,370);
    readimagefile("SL IMG//img//tv1.jpg",195,595,604,600);
    readimagefile("SL IMG//img//tv2.jpg",185,360,155,600);
    readimagefile("SL IMG//img//tv2.jpg",604,360,614,600);
    while(!kbhit())
    {
        sprintf(bee_1,"SL IMG//end2//%d.jpg",k_1);
        readimagefile(bee_1,195,370,604,595);

        k_1++;
        if(k_1>34)
            k_1=1;
        delay(100);
    }
    return;
}
void SORRY()
{
    readimagefile("SL IMG//img//sorry1.jpg",0,230,800,600);
    delay(800);
    readimagefile("SL IMG//img//sorry2.jpg",0,230,800,600);
    readimagefile("SL IMG//img//tv1.jpg",195,360,604,370);
    readimagefile("SL IMG//img//tv1.jpg",195,595,604,600);
    readimagefile("SL IMG//img//tv2.jpg",185,360,155,600);
    readimagefile("SL IMG//img//tv2.jpg",604,360,614,600);
    while(!kbhit())
    {
        sprintf(bee_1,"SL IMG//end2//%d.jpg",k_1);
        readimagefile(bee_1,195,370,604,595);

        k_1++;
        if(k_1>34)
            k_1=1;
        delay(100);
    }
    cleardevice();
    return;
}
