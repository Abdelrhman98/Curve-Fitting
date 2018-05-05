#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#define SCREEN_WIDTH 80
#include <bits/stdc++.h>
#include "template.cpp"
using namespace std;
const char gridCH[] = {218, 196, 191, 179, 192, 217, 195, 194, 180, 193, 197};
const char spc      = ' ';
void printCh(int cnt, char ch);
void printUp(int cnt);
void responsive(int size);
void printUpperCurve(int width);
void printLowerCurve(int width);
void printBOX(VS str);
void main_menu();
int getMaxSz(VS str);
void controller();

#endif // GUI_H_INCLUDED
