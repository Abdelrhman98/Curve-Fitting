#include "GUI.h"
#include "BISECTION-METHOD.h"
#include "Curve-Fitting.h"
#include "Newtons_Method.h"
#include <bits/stdc++.h>
#include "template.cpp"
#include <unistd.h>
#include <windows.h>
using namespace std;
void printCh(int cnt, char ch){lp(i, cnt)pfch(ch);}
void printUp(int cnt){printCh(cnt, gridCH[1]);}
void responsive(int size){printCh((int)((SCREEN_WIDTH - size)/2), spc);}
void printUpperCurve(int width)
{
    printCh(1, gridCH[0]);
    printCh(width-2, gridCH[1]);
    printCh(1, gridCH[2]);
}
void printLowerCurve(int width)
{
    printCh(1, gridCH[4]);
    printCh(width-2, gridCH[1]);
    printCh(1, gridCH[5]);
}
int getMaxSz(VS str){
    int mx=0;
    lp(i, sz(str))
        if(mx < (int)str[i].length())
            mx = (int)str[i].length();
    return mx;
}
void printBOX(VS str)
{
    int size = getMaxSz(str);
    responsive(size);
    printUpperCurve(size+2);
    end;
    lp(i, sz(str)){
        responsive(size);
        printCh(1, gridCH[3]);
        cout<<str[i];
        lp(j, size-str[i].length())
            pf(" ");
        printCh(1, gridCH[3]);
        end;
    }

    responsive(size);
    printLowerCurve(size+2);

}


void main_menu()
{
    VS vec;
    vec.pb("\3\3 CHOOSE \3\3");
    printBOX(vec);
    vec.clear();
    end;
    vec.pb(" 1 - BISECTION-METHOD ");
    vec.pb(" 2 - CURVE-FITTING ");
    vec.pb(" 3 - NEWTONS-METHOD ");
    printBOX(vec);
    end;
}

void controller(){
    a:
        cls;
        main_menu();
        int cho;
        responsive(1);
        sfi1(cho);
    switch(cho){
        case 1:
            solveBISECITION();
            break;
        case 2:
            solveCURVE_FITTING();
            break;
        case 3:
            solveNEWTONS_METHOD ();
            break;
        default:
            VS vec;
            vec.pb(" \1\1 NOT VALID \1\1 ");
            printBOX(vec);
            Sleep(2000);
            end;
            goto a;
        break;
    }
}
