
#include <iostream>
#include <fstream>
#include <string>
#include <graphics.h>
using namespace std;
void main_menu();
void store_high_score_3(int score)
{
    ifstream myFile("scorethree.txt");
    int hs;
    myFile >> hs;
    if(score>hs)
    {
        ofstream highScore("scorethree.txt");
        highScore << score;
        highScore.close();
    }
}
void high_score_3(void)
{
    ifstream myFile("scorethree.txt");
    int hs;
    myFile >> hs;
    char score [10];
    itoa (hs,score,10);
    settextstyle(3,0,4);
    setbkcolor(15);
    setcolor(12);
    outtextxy(450,378,score);
    setbkcolor(0);
    getch();
    main_menu();
}

