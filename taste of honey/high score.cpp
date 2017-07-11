#include <iostream>
#include <fstream>
#include <string>
#include <graphics.h>
using namespace std;
void main_menu();
void high_score_2(void);
void high_score_3(void);
void store_high_score_1(int score)
{
    ifstream myFile("scoreone.txt");
    int hs;
    myFile >> hs;
    if(score>hs)
    {
        ofstream highScore("scoreone.txt");
        highScore << score;
        highScore.close();
    }
}


void high_score_1(void)
{
    cleardevice();
    ifstream myFile("scoreone.txt");
    int hs;
    myFile >> hs;
    char score [10];
    itoa (hs,score,10);
    settextstyle(3,0,4);
    setbkcolor(15);
    setcolor(12);
    readimagefile("option//high.jpg",0,0,800,600);
    outtextxy(450,235,score);
    setbkcolor(0);
    high_score_2();
    high_score_3();

}
