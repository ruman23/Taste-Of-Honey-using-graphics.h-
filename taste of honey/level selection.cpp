
#include<graphics.h>
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<string.h>

using namespace std;

//void Level_1(void);
//void Level_2(void);
//void Level_2(void);
void main_menu(void);
void new_game(void)
{

    // cleardevice();
    char point_ls;
    int key_ls,l=1;
    readimagefile("level//s1.jpg",0,0,800,600);
    while(1)
    {
        key_ls=l;
        point_ls=getch();
        if(key_ls==1)
        {
            // cleardevice();
            readimagefile("level//s1.jpg",0,0,800,600);
            if(point_ls==80||point_ls=='s')
            {
                readimagefile("level//s2.jpg",0,0,800,600);
                l=2;
            }
            else if(point_ls==72||point_ls=='w')
            {
                readimagefile("level//s4.jpg",0,0,800,600);
                l=4;
            }
            //   else if(point_ls==13)
            //    new_game();

        }
        else if(key_ls==2)
        {
            // cleardevice();
            readimagefile("level//s2.jpg",0,0,800,600);
            if(point_ls==80||point_ls=='s')
            {
                readimagefile("level//s3.jpg",0,0,800,600);
                l=3;
            }
            else if(point_ls==72||point_ls=='w')
            {
                readimagefile("level//s1.jpg",0,0,800,600);
                l=1;
            }
            //  else if(point_ls==13)
            //    option();
        }
        else if(key_ls==3)
        {
            // cleardevice();
            readimagefile("level//s3.jpg",0,0,800,600);
            if(point_ls==80||point_ls=='s')
            {
                readimagefile("level//s4.jpg",0,0,800,600);
                l=4;
            }
            else if(point_ls==72||point_ls=='w')
            {
                readimagefile("level//s2.jpg",0,0,800,600);
                l=2;
            }
            /* else if(point_ls==13)
                 credits();*/
        }
        else if(key_ls==4)
        {
            // cleardevice();
            readimagefile("level//s4.jpg",0,0,800,600);
            if(point_ls==80||point_ls=='s')
            {
                readimagefile("level//s1.jpg",0,0,800,600);
                l=1;
            }
            else if(point_ls==72||point_ls=='w')
            {
                readimagefile("level//s3.jpg",0,0,800,600);
                l=3;
            }
            else if(point_ls==13)
            {
                main_menu();
            }
        }
    }
    getch();
}
