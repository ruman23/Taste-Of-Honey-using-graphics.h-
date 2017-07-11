#include <iostream>
#include <fstream>
#include <string>
#include <graphics.h>
using namespace std;
void main_menu();
void store_high_score_2(int score)
{
    ifstream myFile("scoretwo.txt");
    int hs;
    myFile >> hs;
    if(score>hs)
    {
        ofstream highScore("scoretwo.txt");
        highScore << score;
        highScore.close();
    }
}


void high_score_2(void)
{
    // cleardevice();
    ifstream myFile("scoretwo.txt");
    int hs;
    myFile >> hs;
    char score [10];
    itoa (hs,score,10);
    settextstyle(3,0,4);
    setbkcolor(15);
    setcolor(12);
    outtextxy(450,306,score);
    setbkcolor(0);
}

