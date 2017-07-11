#include<graphics.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <fstream>
using namespace std;
void BEE_CONTROL_2();
void BIRD_PRINT_2();
void FLOWER_PRINT_2();
void NEW_BIRD_2();
void NEW_FLOWER_2();
void BACK_COVER();
void LIFE_2();
void CONGRATULATION_2();
void SORRY_2();
void store_high_score_2(int);
void LEVEL_THREE();
int point_2=4,outrandom_2[1000],r_2=4,j,b1_2=1,b2_2=1,b3_2=1,b4_2=1,b5_2=1,SPEED_2=15,i_2=0,dly_2=1,life_2=3,k_2=1;
int b1x1_2,b1x2_2,b2x1_2,b2x2_2,b3x1_2,b3x2_2,b4x1_2,b4x2_2,b5x1_2,b5x2_2,scores_2=0,beey1_2=223,beey2_2=277,beespeed_2=100;
int fn_2=1,f1x1_2=-90,f1x2_2=0,f1y1_2,f1y2_2,randomflwr_2=4;
char key_2,bird_2[20],flower[20],bee_2[20],score_2[5]= {'0','0','0'};
void LEVEL_TWO()
{
    while(i_2<1000)
    {
        outrandom_2[i_2]=rand()%1200+150;
        i_2++;
    }
    cleardevice();
    clearviewport();
    sndPlaySound("sound/level.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    readimagefile("SL IMG//back//background.jpg",0,0,800,600); /// full back cover
    /// new bird_2 adding er sathe sathe r er value 1 increase krte hbe
    b1x1_2=-outrandom_2[0];
    b1x2_2=b1x1_2+101;
    b2x1_2=-outrandom_2[1]-300;
    b2x2_2=b2x1_2+101;
    b3x1_2=-outrandom_2[2];
    b3x2_2=b3x1_2+101;
    b4x1_2=-outrandom_2[3];
    b4x2_2=b4x1_2+101;
    b5x1_2=-outrandom_2[4];
    b5x2_2=b5x1_2+101;
    readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
    readimagefile("SL IMG//back//topback.jpg",0,0,800,100);
    setbkcolor(WHITE);
    setcolor(RED);
    settextstyle(1,0,4);
    line(0,100,800,100);
    readimagefile("SL IMG//lifeT//life3.jpg",50,0,210,35); ///life 3
    while(life_2)/// life
    {
        sprintf(score_2,"%d",scores_2);
        outtextxy(670,0,score_2);
        if(SPEED_2>=50)///max speed condition
            SPEED_2=50;
        if(r_2>999)
            r_2=1;
        BIRD_PRINT_2();
        FLOWER_PRINT_2();
        BACK_COVER();
        NEW_FLOWER_2();
        NEW_BIRD_2();

        ///killing bird condition and new bird print
        while(kbhit())          /// bee control
        {
            key_2=getch();
            BEE_CONTROL_2();
        }
        BACK_COVER();
        delay(dly_2);
    }
    readimagefile("SL IMG//back//background.jpg",0,100,800,600);
    store_high_score_2(scores_2);
    sndPlaySound("sound/angry bird2.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    if(scores_2>=300)
    {
        CONGRATULATION_2();
        LEVEL_THREE();
    }

    else
        SORRY_2();
    point_2=4;
    r_2=4;
    b1_2=1;
    b2_2=1;
    b3_2=1;
    b4_2=1;
    b5_2=1;
    SPEED_2=15;
    i_2=0;
    dly_2=1;
    life_2=3;
    k_2=1;
    scores_2=0;
    beey1_2=223;
    beey2_2=277;
    beespeed_2=100;
    fn_2=1;
    f1x1_2=-90;
    f1x2_2=0;
    randomflwr_2=4;
}
void BIRD_PRINT_2()
{
    sprintf(bird_2,"SL IMG//bird//%d.jpg",b1_2);
    readimagefile(bird_2,b1x1_2,510,b1x2_2,600);/// bird 1
    readimagefile("SL IMG//back//back.jpg",b1x1_2-101,510,b1x2_2-101,600);///back 1
    sprintf(bird_2,"SL IMG//bird//%d.jpg",b2_2);
    readimagefile(bird_2,b2x1_2,410,b2x2_2,500);/// bird 2 mid position
    readimagefile("SL IMG//back//back.jpg",b2x1_2-101,410,b2x2_2-101,500);///back 2
    sprintf(bird_2,"SL IMG//bird//%d.jpg",b3_2);
    readimagefile(bird_2,b3x1_2,310,b3x2_2,400);/// bird 3 top position
    readimagefile("SL IMG//back//back.jpg",b3x1_2-101,310,b3x2_2-101,400);///back 3
    sprintf(bird_2,"SL IMG//bird//%d.jpg",b4_2);
    readimagefile(bird_2,b4x1_2,210,b4x2_2,300);/// bird 4 top position
    readimagefile("SL IMG//back//back.jpg",b4x1_2-101,210,b4x2_2-101,300);///back 4
    sprintf(bird_2,"SL IMG//bird//%d.jpg",b5_2);
    readimagefile(bird_2,b5x1_2,110,b5x2_2,200);/// bird 5 top position
    readimagefile("SL IMG//back//back.jpg",b5x1_2-101,110,b5x2_2-101,200);///back 5
}
void FLOWER_PRINT_2()
{
    if(randomflwr_2==1&((b1x2_2+90<f1x1_2)||(f1x2_2<b1x1_2-101)))
    {
        sprintf(flower,"SL IMG//LS FLOWER//flower%d.jpg",fn_2);
        readimagefile(flower,f1x1_2,510,f1x2_2,600);
        readimagefile("SL IMG//back//back.jpg",f1x1_2-90,510,f1x2_2-90,600);
        f1x1_2+=SPEED_2;
        f1x2_2+=SPEED_2;
    }
    else if(randomflwr_2==2&((b2x2_2+90<f1x1_2)||(f1x2_2<b2x1_2-101)))
    {
        sprintf(flower,"SL IMG//LS FLOWER//flower%d.jpg",fn_2);
        readimagefile(flower,f1x1_2,410,f1x2_2,500);
        readimagefile("SL IMG//back//back.jpg",f1x1_2-90,410,f1x2_2-90,500);
        f1x1_2+=SPEED_2;
        f1x2_2+=SPEED_2;
    }
    else if(randomflwr_2==3&((b3x2_2+90<f1x1_2)||(f1x2_2<b3x1_2-101)))
    {
        sprintf(flower,"SL IMG//LS FLOWER//flower%d.jpg",fn_2);
        readimagefile(flower,f1x1_2,310,f1x2_2,400);
        readimagefile("SL IMG//back//back.jpg",f1x1_2-90,310,f1x2_2-90,400);
        f1x1_2+=SPEED_2;
        f1x2_2+=SPEED_2;
    }
    else if(randomflwr_2==4&((b4x2_2+90<f1x1_2)||(f1x2_2<b4x1_2-101)))
    {
        sprintf(flower,"SL IMG//LS FLOWER//flower%d.jpg",fn_2);
        readimagefile(flower,f1x1_2,210,f1x2_2,300);
        readimagefile("SL IMG//back//back.jpg",f1x1_2-90,210,f1x2_2-90,300);
        f1x1_2+=SPEED_2;
        f1x2_2+=SPEED_2;
    }
    else if(randomflwr_2==5&((b5x2_2+90<f1x1_2)||(f1x2_2<b5x1_2-101)))
    {
        sprintf(flower,"SL IMG//LS FLOWER//flower%d.jpg",fn_2);
        readimagefile(flower,f1x1_2,110,f1x2_2,200);
        readimagefile("SL IMG//back//back.jpg",f1x1_2-90,110,f1x2_2-90,200);
        f1x1_2+=SPEED_2;
        f1x2_2+=SPEED_2;
    }
}
void NEW_FLOWER_2()
{
    if(fn_2>11)
        fn_2=1;
    if(f1x2_2>=730&f1x1_2<=800)
    {
        if(randomflwr_2==1&point_2==1)
        {
            readimagefile("SL IMG//back//back.jpg",600,510,800,600);
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            randomflwr_2=(rand()%5)+1;
            fn_2++;
            if(fn_2>11)
                fn_2=1;
            f1x1_2=-90;
            f1x2_2=0;
            scores_2+=10;
        }
        else if(randomflwr_2==2&point_2==2)
        {
            readimagefile("SL IMG//back//back.jpg",600,410,800,500);
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            randomflwr_2=(rand()%5)+1;
            fn_2++;
            f1x1_2=-90;
            f1x2_2=0;
            scores_2+=10;
        }
        else if(randomflwr_2==3&point_2==3)
        {
            readimagefile("SL IMG//back//back.jpg",600,310,800,400);
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            randomflwr_2=(rand()%5)+1;
            fn_2++;
            f1x1_2=-90;
            f1x2_2=0;
            scores_2+=10;
        }
        else if(randomflwr_2==4&point_2==4)
        {
            readimagefile("SL IMG//back//back.jpg",600,210,800,300);
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            randomflwr_2=(rand()%5)+1;
            fn_2++;
            f1x1_2=-90;
            f1x2_2=0;
            scores_2+=10;
        }
        else if(randomflwr_2==5&point_2==5)
        {
            readimagefile("SL IMG//back//back.jpg",600,110,800,200);
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            randomflwr_2=(rand()%5)+1;
            fn_2++;
            f1x1_2=-90;
            f1x2_2=0;
            scores_2+=10;
        }
    }
    else if(f1x2_2>=1000+SPEED_2)
    {
        randomflwr_2=(rand()%5)+1;
        fn_2++;
        f1x1_2=-90;
        f1x2_2=0;
    }
}

void NEW_BIRD_2()
{
    b1_2++;/// bird 1 start
    if(b1_2>=42)
        b1_2=1;
    if(b1x1_2>=800||(b1x2_2>=730&&b1x1_2<=800&&point_2==1))
    {
        if(b1x2_2>=730&&b1x1_2<=800&&point_2==1)
        {
            readimagefile("SL IMG//back//back.jpg",b1x1_2,510,800,600);///back 1
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            LIFE_2();
        }
        r_2++;
        b1x1_2=-outrandom_2[r_2];
        b1x2_2=b1x1_2+101;
        SPEED_2+=1;
    }
    b1x1_2+=SPEED_2;
    b1x2_2+=SPEED_2;
    /// bird 1 end
    b2_2++;/// bird 2 start
    if(b2_2>=42)
        b2_2=1;
    if(b2x1_2>=800||(b2x2_2>=730&&b2x1_2<=800&&point_2==2))
    {
        if(b2x2_2>=730&&b2x1_2<=800&&point_2==2)
        {
            readimagefile("SL IMG//back//back.jpg",b2x1_2,410,800,500);///back 2
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            LIFE_2();
        }
        r_2++;
        b2x1_2=-outrandom_2[r_2];
        b2x2_2=b2x1_2+101;
        SPEED_2+=1;
    }
    b2x1_2+=SPEED_2;
    b2x2_2+=SPEED_2;
    /// bird 2 end
    b3_2++;/// bird 3 start
    if(b3_2>=42)
        b3_2=1;
    if(b3x1_2>=800||(b3x2_2>=730&&b3x1_2<=800&&point_2==3))
    {
        if(b3x2_2>=730&&b3x1_2<=800&&point_2==3)
        {
            readimagefile("SL IMG//back//back.jpg",b3x1_2,310,800,400);///back 3
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            LIFE_2();
        }
        r_2++;
        b3x1_2=-outrandom_2[r_2];
        b3x2_2=b3x1_2+101;
        SPEED_2+=1;
    }
    b3x1_2+=SPEED_2;
    b3x2_2+=SPEED_2;
    /// bird 3 end
    b4_2++;/// bird 4 start
    if(b4_2>=42)
        b4_2=1;
    if(b4x1_2>=800||(b4x2_2>=730&&b4x1_2<=800&&point_2==4))
    {
        if(b4x2_2>=730&&b4x1_2<=800&&point_2==4)
        {
            readimagefile("SL IMG//back//back.jpg",b4x1_2,210,800,300);///back 4
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            LIFE_2();
        }
        r_2++;
        b4x1_2=-outrandom_2[r_2];
        b4x2_2=b4x1_2+101;
        SPEED_2+=1;
    }
    b4x1_2+=SPEED_2;
    b4x2_2+=SPEED_2;
    /// bird 4 end
    b5_2++;/// bird 5 start
    if(b5_2>=42)
        b5_2=1;
    if(b5x1_2>=800||(b5x2_2>=730&&b5x1_2<=800&&point_2==5))
    {
        if(b5x2_2>=730&&b5x1_2<=800&&point_2==5)
        {
            readimagefile("SL IMG//back//back.jpg",b5x1_2,110,800,200);///back 5
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            LIFE_2();
        }
        r_2++;
        b5x1_2=-outrandom_2[r_2];
        b5x2_2=b5x1_2+101;
        SPEED_2+=1;
    }
    b5x1_2+=SPEED_2;
    b5x2_2+=SPEED_2;
    /// bird 5 end
}

void BEE_CONTROL_2()
{
    if(key_2==72||key_2=='w')
    {
        if(beey1_2>200)
        {
            readimagefile("SL IMG//back//back.jpg",730,beey1_2,800,beey2_2);
            beey1_2-=beespeed_2;
            beey2_2-=beespeed_2;
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            point_2++;
        }
    }
    else if(key_2==80||key_2=='s')
    {
        if(beey2_2<=530)
        {
            readimagefile("SL IMG//back//back.jpg",730,beey1_2,800,beey2_2);
            beey1_2+=beespeed_2;
            beey2_2+=beespeed_2;
            readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
            point_2--;
        }
    }
    else if(key_2==32)
        int a=getch();
}
void BACK_COVER()
{
    if((f1x1_2-90>=730&f1x1_2-90<=800)||(f1x2_2-90>=730&f1x2_2-90<=800))
    {

        readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
    }
    else if((((b1x1_2-101>=730&b1x1_2-101<=800)||(b1x2_2-101>=730&b1x2_2-101<=800))||((b2x1_2-101>=730&b2x1_2-101<=800)||(b2x2_2-101>=730&b2x2_2-101<=800)))||
            ((((b3x1_2-101>=730&b3x1_2-101<=800)||(b3x2_2-101>=730&b3x2_2-101<=800))||((b4x1_2-101>=730&b4x1_2-101<=800)||(b4x2_2-101>=730&b4x2_2-101<=800)))||
             ((b5x1_2-101>=730&b5x1_2-101<=800)||(b5x2_2-101>=730&b5x2_2-101<=800))))
    {

        readimagefile("SL IMG//bee//bee.jpg",730,beey1_2,800,beey2_2);
    }
}
void LIFE_2()
{
    life_2-=1;
    if(life_2==2)
        readimagefile("SL IMG//lifeT//life2.jpg",50,0,210,35); ///life 2
    else if(life_2==1)
        readimagefile("SL IMG//lifeT//life1.jpg",50,0,210,35); ///life 1
    else if(life_2==0)
    {
        readimagefile("SL IMG//lifeT//life0.jpg",50,0,210,35); ///life 0
    }
}
void CONGRATULATION_2()
{
    readimagefile("SL IMG//congrts//congratulation1.jpg",0,230,800,600);
    delay(800);
    readimagefile("SL IMG//congrts//congratulation2.jpg",0,230,800,600);
    delay(800);
    readimagefile("SL IMG//congrts//tv1.jpg",195,360,604,370);
    readimagefile("SL IMG//congrts//tv1.jpg",195,595,604,600);
    readimagefile("SL IMG//congrts//tv2.jpg",185,360,155,600);
    readimagefile("SL IMG//congrts//tv2.jpg",604,360,614,600);
    while(!kbhit())
    {
        sprintf(bee_2,"SL IMG//end2//%d.jpg",k_2);
        readimagefile(bee_2,195,370,604,595);

        k_2++;
        if(k_2>34)
            k_2=1;
        delay(100);
    }
}

void SORRY_2()
{
    readimagefile("SL IMG//congrts//sorry1.jpg",0,230,800,600);
    delay(800);
    readimagefile("SL IMG//congrts//sorry2.jpg",0,230,800,600);
    delay(800);
    readimagefile("SL IMG//congrts//anykey.jpg",0,550,185,600);
    readimagefile("SL IMG//congrts//anykey.jpg",610,550,800,600);
    readimagefile("SL IMG//congrts//tv1.jpg",195,360,604,370);
    readimagefile("SL IMG//congrts//tv1.jpg",195,595,604,600);
    readimagefile("SL IMG//congrts//tv2.jpg",185,360,155,600);
    readimagefile("SL IMG//congrts//tv2.jpg",604,360,614,600);
    while(!kbhit())
    {
        sprintf(bee_2,"SL IMG//end2//%d.jpg",k_2);
        readimagefile(bee_2,195,370,604,595);

        k_2++;
        if(k_2>34)
            k_2=1;
        delay(100);
    }
    cleardevice();
}

