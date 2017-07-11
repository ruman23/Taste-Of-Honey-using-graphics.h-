#include<graphics.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
using namespace std;
//void new_game(void);
void LEVEL_ONE();
void option(void);
void credits (void);
void exit(void);
void high_score_1(void);
void high_score_2(void);
void main_menu()
{

    cleardevice();
    char point_mm;
    int key_mm,l_m=1,brk_mm=1;
    readimagefile("main menu//new1.jpg",0,0,800,600);
    while(brk_mm)
    {
        // readimagefile("main menu//new1.jpg",0,y1,50,y2+t);
        key_mm=l_m;
        point_mm=getch();
        if(key_mm==1)
        {
            // cleardevice();
            readimagefile("main menu//new1.jpg",0,0,800,600);
            if(point_mm==80||point_mm=='s')
            {
                readimagefile("main menu//highscore2.jpg",0,0,800,600);
                l_m=2;
            }
            else if(point_mm==72||point_mm=='w')
            {
                readimagefile("main menu//exit5.jpg",0,0,800,600);
                l_m=5;
            }
            else if(point_mm==13)
            {
                LEVEL_ONE();
                //  main_menu();
                break;
            }

        }
        else if(key_mm==2)
        {
            // cleardevice();
            readimagefile("main menu//highscore2.jpg",0,0,800,600);
            if(point_mm==80||point_mm=='s')
            {
                readimagefile("main menu//option3.jpg",0,0,800,600);
                l_m=3;
            }
            else if(point_mm==72||point_mm=='w')
            {
                readimagefile("main menu//new1.jpg",0,0,800,600);
                l_m=1;
            }
            else if(point_mm==13)
            {
               high_score_1();
                break;
            }
        }
        else if(key_mm==3)
        {
            // cleardevice();
            readimagefile("main menu//option3.jpg",0,0,800,600);
            if(point_mm==80||point_mm=='s')
            {
                readimagefile("main menu//credits4.jpg",0,0,800,600);
                l_m=4;
            }
            else if(point_mm==72||point_mm=='w')
            {
                readimagefile("main menu//highscore2.jpg",0,0,800,600);
                l_m=2;
            }
              else if(point_mm==13)
             option();
        }
        else if(key_mm==4)
        {
            // cleardevice();
            readimagefile("main menu//credits4.jpg",0,0,800,600);
            if(point_mm==80||point_mm=='s')
            {
                readimagefile("main menu//exit5.jpg",0,0,800,600);
                l_m=5;
            }
            else if(point_mm==72||point_mm=='w')
            {
                readimagefile("main menu//option3.jpg",0,0,800,600);
                l_m=3;
            }
            if(point_mm==13)
                credits();

        }
        else if(key_mm==5)
        {
            // cleardevice();
            readimagefile("main menu//exit5.jpg",0,0,800,600);
            if(point_mm==80||point_mm=='s')
            {
                readimagefile("main menu//new1.jpg",0,0,800,600);
                l_m=1;
            }
            else if(point_mm==72||point_mm=='w')
            {
                readimagefile("main menu//credits4.jpg",0,0,800,600);
                l_m=4;
            }
            if(point_mm==13)
            {
                exit();
                break;
            }
        }

    }
}
