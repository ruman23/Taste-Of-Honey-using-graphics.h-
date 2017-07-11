#include<graphics.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <fstream>
using namespace std;
void BEE_CONTROL_3();
void BAR_CONTROL();
void HIVE_1();
void HIVE_2();
void NEW_BEE_3();
void SCORE_3();
void LIFE_3_F();
void SORRY_3();
void CONGRATULATION_3();
void store_high_score_3(int);
int b1y1_3=100,b1y2_3=180,SPEED_3=15,i_3=0,j_3=0,k_3=0,l_3=1,m_3=0,LIFE_3=3,cs=1;
int ba1x1_3=0,ba1x2_3=2500,ba2x1_3=800,ba2x2_3=830,ba3x1_3=1100,ba3x2_3=1180,ba4x1_3=1500,ba4x2_3=1525,scores_3=0;
int ba2y1_3=450,ba3y1_3=400,ba4y1_3=500,h1x1_3=200,h1x2_3=280,h1y1_3=450,h1y2_3=530,h2x1_3=0,h2x2_3=0,h2y1_3=0,h2y2_3=0;
char key_3,cs_3[20],randomy_3[999],randomx_3[999],randomh_3[999],bee_3[10],score_3[5]= {'0','0','0'};
void LEVEL_THREE()
{
     cleardevice();
    clearviewport();
    setfillstyle(3,6);
    line(0,120,800,120);
    settextstyle(3,0,2);
    readimagefile("TL IMG//fullback.jpg",0,0,800,600);
    readimagefile("TL IMG//upback2.jpg",0,0,800,80);
    readimagefile("TL IMG//bee.jpg",0,b1y1_3,80,b1y2_3);
    outtextxy(660,10,"SCORE:");
    outtextxy(0,10,"LIFE:");
    sprintf(score_3,"%d",scores_3);
    outtextxy(730,10,score_3);
    outtextxy(48,10,"3");
    while(i_3<999)
    {
        randomy_3[i_3]=rand()%200;//200 ***********************
        randomx_3[i_3]=rand()%100;
        randomh_3[i_3]=rand()%150;
        i_3++;
    }
    sndPlaySound("sound/level.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    while(LIFE_3>=1)
    {
        if((j_3>999||k_3>99)||(m_3>999))
        {
            j_3=0;
            k_3=0;
            m_3=0;
        }
        BAR_CONTROL();
        HIVE_1();
        HIVE_2();
        while(kbhit())          /// bee control
        {
            key_3=getch();
            BEE_CONTROL_3();
        }
        NEW_BEE_3();
        delay(1);/// prvs 30, *****************
    }
    store_high_score_3(scores_3);
    sndPlaySound("sound/angry bird2.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
    if(scores_3>=250)
        CONGRATULATION_3();
    else
        SORRY_3();
    b1y1_3=100;
    b1y2_3=180;
    SPEED_3=10;
    i_3=0;
    j_3=0;
    k_3=0;
    l_3=1;
    m_3=0;
    LIFE_3=3;
    ba1x1_3=0;
    ba1x2_3=2500;
    ba2x1_3=800;
    ba2x2_3=830;
    ba3x1_3=1100;
    ba3x2_3=1180;
    ba4x1_3=1500;
    ba4x2_3=1525;
    scores_3=0;
    ba2y1_3=450;
    ba3y1_3=400;
    ba4y1_3=500;
    h1x1_3=200;
    h1x2_3=280;
    h1y1_3=450;
    h1y2_3=530;
    h2x1_3=0;
    h2x2_3=0;
    h2y1_3=0;
    h2y2_3=0;
    getch();
}
void HIVE_1()
{
    ///for HIVE 1
    if(h1x2_3<=-2)
    {
        h1x1_3=820;
        h1x2_3=900;
        h1y1_3=randomh_3[m_3]+355;
        h1y2_3=h1y1_3+80;
        m_3++;
    }
    //hive 1+hive 2=hive 1
    else  if(((h1x1_3>=h2x1_3&h1x1_3<=h2x2_3)&(h1y1_3>=h2y1_3&h1y1_3<=h2y2_3)||(h1x2_3>=h2x1_3&h1x2_3<=h2x2_3)&(h1y1_3>=h2y1_3&h1y1_3<=h2y2_3))||
             ((h1x1_3>=h2x1_3&h1x1_3<=h2x2_3)&(h1y2_3>=h2y1_3&h1y2_3<=h2y2_3)||(h1x2_3>=h2x1_3&h1x2_3<=h2x2_3)&(h1y2_3>=h2y1_3&h1y2_3<=h2y2_3)))
    {
        readimagefile("TL IMG//back.jpg",h1x1_3,h1y1_3,h1x2_3,h1y2_3);
        h1x1_3=820;
        h1x2_3=900;
        h1y1_3=randomh_3[m_3]+355;
        h1y2_3=h1y1_3+80;
        m_3++;
    }
    //hive1 + bee=hive
    else  if(((h1x1_3>=0&h1x1_3<=80)&(h1y1_3>=b1y1_3&h1y1_3<=b1y2_3)||(h1x2_3>=0&h1x2_3<=80)&(h1y1_3>=b1y1_3&h1y1_3<=b1y2_3))||
             ((h1x1_3>=0&h1x1_3<=80)&(h1y2_3>=b1y1_3&h1y2_3<=b1y2_3)||(h1x2_3>=0&h1x2_3<=80)&(h1y2_3>=b1y1_3&h1y2_3<=b1y2_3)))
    {
        SCORE_3();
        readimagefile("TL IMG//back.jpg",h1x1_3,h1y1_3,h1x2_3,h1y2_3);
        h1x1_3=820;
        h1x2_3=900;
        h1y1_3=randomh_3[m_3]+355;
        h1y2_3=h1y1_3+80;
        m_3++;
    }

    // new hive and bar=hive
    else if((h1y2_3>=ba2y1_3)&((ba2x1_3+SPEED_3>=h1x1_3&ba2x1_3+SPEED_3<=h1x2_3)||(ba2x2_3+SPEED_3>=h1x1_3&ba2x2_3+SPEED_3<=h1x2_3)))
    {
        readimagefile("TL IMG//back.jpg",h1x1_3,h1y1_3,h1x2_3,h1y2_3);
        h1x1_3=820;
        h1x2_3=900;
        h1y1_3=randomh_3[m_3]+355;
        h1y2_3=h1y1_3+80;
        m_3++;
    }
    else if((h1y2_3>=ba3y1_3)&((ba3x1_3+SPEED_3>=h1x1_3&ba3x1_3+SPEED_3<=h1x2_3)||(ba3x2_3+SPEED_3>=h1x1_3&ba3x2_3+SPEED_3<=h1x2_3)))
    {
        readimagefile("TL IMG//back.jpg",h1x1_3,h1y1_3,h1x2_3,h1y2_3);
        h1x1_3=820;
        h1x2_3=900;
        h1y1_3=randomh_3[m_3]+355;
        h1y2_3=h1y1_3+80;
        m_3++;
    }
    else if((h1y2_3>=ba4y1_3)&((ba4x1_3+SPEED_3>=h1x1_3&ba4x1_3+SPEED_3<=h1x2_3)||(ba4x2_3+SPEED_3>=h1x1_3&ba4x2_3+SPEED_3<=h1x2_3)))
    {
        readimagefile("TL IMG//back.jpg",h1x1_3,h1y1_3,h1x2_3,h1y2_3);
        h1x1_3=820;
        h1x2_3=900;
        h1y1_3=randomh_3[m_3]+355;
        h1y2_3=h1y1_3+80;
        m_3++;
    }
    readimagefile("TL IMG//back.jpg",h1x1_3,h1y1_3,h1x2_3,h1y2_3);
    h1x1_3-=SPEED_3;
    h1x2_3-=SPEED_3;
    readimagefile("TL IMG//hive.jpg",h1x1_3,h1y1_3,h1x2_3,h1y2_3);
}
void HIVE_2()
{
    ///for HIVE 2
    if((h1x2_3>250&h1x2_3<300)&h2x2_3<=0)
    {
        h2x1_3=820;
        h2x2_3=900;
        h2y1_3=randomh_3[m_3]+355;
        h2y2_3=h2y1_3+80;
        m_3++;
    }
    //hive1 + bee=hive
    else  if(((h2x1_3>=0&h2x1_3<=80)&(h2y1_3>=b1y1_3&h2y1_3<=b1y2_3)||(h2x2_3>=0&h2x2_3<=80)&(h2y1_3>=b1y1_3&h2y1_3<=b1y2_3))||
             ((h2x1_3>=0&h2x1_3<=80)&(h2y2_3>=b1y1_3&h2y2_3<=b1y2_3)||(h2x2_3>=0&h2x2_3<=80)&(h2y2_3>=b1y1_3&h2y2_3<=b1y2_3)))
    {
        SCORE_3();
        readimagefile("TL IMG//back.jpg",h2x1_3,h2y1_3,h2x2_3,h2y2_3);
        h2x1_3=820;
        h2x2_3=900;
        h2y1_3=randomh_3[m_3]+355;
        h2y2_3=h2y1_3+80;
        m_3++;
    }

    // new hive and bar=hive
    else if((h2y2_3>=ba2y1_3)&((ba2x1_3+SPEED_3>=h2x1_3&ba2x1_3+SPEED_3<=h2x2_3)||(ba2x2_3+SPEED_3>=h2x1_3&ba2x2_3+SPEED_3<=h2x2_3)))
    {
        readimagefile("TL IMG//back.jpg",h2x1_3,h2y1_3,h2x2_3,h2y2_3);
        h2x1_3=820;
        h2x2_3=900;
        h2y1_3=randomh_3[m_3]+355;
        h2y2_3=h2y1_3+80;
        m_3++;
    }
    else if((h2y2_3>=ba3y1_3)&((ba3x1_3+SPEED_3>=h2x1_3&ba3x1_3+SPEED_3<=h2x2_3)||(ba3x2_3+SPEED_3>=h2x1_3&ba3x2_3+SPEED_3<=h2x2_3)))
    {
        readimagefile("TL IMG//back.jpg",h2x1_3,h2y1_3,h2x2_3,h2y2_3);
        h2x1_3=820;
        h2x2_3=900;
        h2y1_3=randomh_3[m_3]+355;
        h2y2_3=h2y1_3+80;
        m_3++;
    }
    else if((h2y2_3>=ba4y1_3)&((ba4x1_3+SPEED_3>=h2x1_3&ba4x1_3+SPEED_3<=h2x2_3)||(ba4x2_3+SPEED_3>=h2x1_3&+SPEED_3<=h2x2_3)))
    {
        readimagefile("TL IMG//back.jpg",h2x1_3,h2y1_3,h2x2_3,h2y2_3);
        h2x1_3=820;
        h2x2_3=900;
        h2y1_3=randomh_3[m_3]+355;
        h2y2_3=h2y1_3+80;
        m_3++;
    }
    readimagefile("TL IMG//back.jpg",h2x1_3,h2y1_3,h2x2_3,h2y2_3);
    h2x1_3-=SPEED_3;
    h2x2_3-=SPEED_3;
    readimagefile("TL IMG//hive.jpg",h2x1_3,h2y1_3,h2x2_3,h2y2_3);
}
void BAR_CONTROL()
{
// bar(ba1x1_3,560,ba1x2_3,600);
    readimagefile("TL IMG//road.jpg",ba1x1_3,585,ba1x2_3,600);
    ba1x1_3-=SPEED_3;
    ba1x2_3-=SPEED_3;
    if(ba1x2_3<=800)
    {
        ba1x1_3=0;
        ba1x2_3=2500;
    }
    if(ba2x2_3<=0)//2 bar S
    {
        ba2x1_3=800;
        ba2x2_3=820+randomx_3[k_3];
        ba2y1_3=randomy_3[j_3]+390;//*******385
        j_3++;
        k_3++;
    }
    if(ba3x2_3<=0)
    {
        ba3x1_3=1100;
        ba3x2_3=1120+randomx_3[k_3];
        ba3y1_3=randomy_3[j_3]+390;
        j_3++;
        k_3++;
    }
    if(ba4x2_3<=0)//3 bar S
    {
        ba4x1_3=1550;
        ba4x2_3=1570+randomx_3[k_3];
        ba4y1_3=randomy_3[j_3]+390;
        j_3++;
        k_3++;
    }
    readimagefile("TL IMG//back.jpg",ba2x1_3,ba2y1_3,ba2x2_3,585);
    readimagefile("TL IMG//back.jpg",ba3x1_3,ba3y1_3,ba3x2_3,585);
    readimagefile("TL IMG//back.jpg",ba4x1_3,ba4y1_3,ba4x2_3,585);
    ba2x1_3-=SPEED_3;
    ba2x2_3-=SPEED_3;
    ba3x1_3-=SPEED_3;
    ba3x2_3-=SPEED_3;
    ba4x1_3-=SPEED_3;
    ba4x2_3-=SPEED_3;
    readimagefile("TL IMG//bamboo.jpg",ba2x1_3,ba2y1_3,ba2x2_3,585);//***********
    readimagefile("TL IMG//bamboo.jpg",ba3x1_3,ba3y1_3,ba3x2_3,585);
    readimagefile("TL IMG//bamboo.jpg",ba4x1_3,ba4y1_3,ba4x2_3,585);
}
void BEE_CONTROL_3()
{

    if((key_3==72||key_3=='w')&b1y1_3>150)
    {
        readimagefile("TL IMG//back.jpg",0,b1y1_3,80,b1y2_3);
        b1y1_3-=80;
        b1y2_3-=80;


        sprintf(bee_3,"TL IMG//bee//bee%d.jpg",l_3);
        readimagefile(bee_3,0,b1y1_3,80,b1y2_3);
        l_3++;
        if(l_3>5)
            l_3=1;

        readimagefile("TL IMG//back.jpg",0,b1y1_3,80,b1y2_3);
    }
    else if(key_3==32)
        int a=getch();
}
void NEW_BEE_3()
{
    if(b1y2_3>=580||b1y1_3<=89)
    {
        readimagefile("TL IMG//back.jpg",0,b1y1_3,80,b1y2_3);
        b1y1_3=100;
        b1y2_3=180;
        LIFE_3_F();
    }
    //bar2+bee=new bee
    else  if((b1y2_3>=ba2y1_3)&((ba2x1_3>=0&ba2x1_3<=80)||(ba2x2_3>=0&ba2x2_3<=80)))
    {
        readimagefile("TL IMG//back.jpg",0,b1y1_3,80,b1y2_3);
        b1y1_3=100;
        b1y2_3=180;
        LIFE_3_F();

    }
    //bar3+bee=new bee
    else  if((b1y2_3>=ba3y1_3)&((ba3x1_3>=0&ba3x1_3<=80)||(ba3x2_3>=0&ba3x2_3<=80)))
    {
        readimagefile("TL IMG//back.jpg",0,b1y1_3,80,b1y2_3);
        b1y1_3=100;
        b1y2_3=180;
        LIFE_3_F();
    }
    //bar2+bee=new bee
    else  if((b1y2_3>=ba4y1_3)&((ba4x1_3>=0&ba4x1_3<=80)||(ba4x2_3>=0&ba4x2_3<=80)))
    {
        readimagefile("TL IMG//back.jpg",0,b1y1_3,80,b1y2_3);
        b1y1_3=100;
        b1y2_3=180;
        LIFE_3_F();
    }
    else
    {
        readimagefile("TL IMG//back.jpg",0,b1y1_3,80,b1y2_3);
        b1y1_3+=20;
        b1y2_3+=20;
        sprintf(bee_3,"TL IMG//bee//bee%d.jpg",l_3);
        readimagefile(bee_3,0,b1y1_3,80,b1y2_3);
        delay(40);
        l_3++;
        if(l_3>5)
            l_3=1;
    }
}
void SCORE_3()
{
    scores_3+=10;
    sprintf(score_3,"%d",scores_3);
    outtextxy(730,10,score_3);
}
void LIFE_3_F()
{
    LIFE_3-=1;
    if(LIFE_3==2)
        outtextxy(48,10,"2");
    else if(LIFE_3==1)
        outtextxy(48,10,"1");
    else if(LIFE_3==0)
        outtextxy(48,10,"0");
}
void CONGRATULATION_3()
{
    readimagefile("TL IMG//congrts//congratulation1.jpg",0,230,800,600);
    delay(800);
    readimagefile("TL IMG//congrts//congratulation2.jpg",0,230,800,600);
    delay(800);
    readimagefile("TL IMG//congrts//anykey.jpg",0,550,185,600);
    readimagefile("TL IMG//congrts//anykey.jpg",610,550,800,600);
    readimagefile("TL IMG//congrts//tv1.jpg",195,360,604,370);
    readimagefile("TL IMG//congrts//tv1.jpg",195,595,604,600);
    readimagefile("TL IMG//congrts//tv2.jpg",185,360,155,600);
    readimagefile("TL IMG//congrts//tv2.jpg",604,360,614,600);
    while(!kbhit())
    {
        sprintf(cs_3,"SL IMG//end2//%d.jpg",cs);
        readimagefile(cs_3,195,370,604,595);

        cs++;
        if(cs>34)
            cs=1;
        delay(100);
    }
    cleardevice();
    clearviewport();
}

void SORRY_3()
{
    readimagefile("TL IMG//congrts//sorry1.jpg",0,230,800,600);
    delay(800);
    readimagefile("TL IMG//congrts//sorry2.jpg",0,230,800,600);
    delay(800);
    readimagefile("TL IMG//congrts//anykey.jpg",0,550,185,600);
    readimagefile("TL IMG//congrts//anykey.jpg",610,550,800,600);
    readimagefile("TL IMG//congrts//tv1.jpg",195,360,604,370);
    readimagefile("TL IMG//congrts//tv1.jpg",195,595,604,600);
    readimagefile("TL IMG//congrts//tv2.jpg",185,360,155,600);
    readimagefile("TL IMG//congrts//tv2.jpg",604,360,614,600);
    while(!kbhit())
    {
        sprintf(cs_3,"SL IMG//end2//%d.jpg",cs);
        readimagefile(cs_3,195,370,604,595);

        cs++;
        if(cs>34)
            cs=1;
        delay(100);
    }
    cleardevice();
    clearviewport();
}
