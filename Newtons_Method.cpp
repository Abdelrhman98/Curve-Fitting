#include "Newtons_Method.h"
#include <bits/stdc++.h>
#include "GUI.h"
#include "template.cpp"
#include <windows.h>
using namespace std ;
template <typename T>
string toString2(T temp){
    stringstream ss;
    ss << temp;
    return ss.str();
}
double func2 ( double num )
{
    return ( num - cos(num) ) ;
}
double derivative_1 ( double num )
{
    return ( 1 + sin(num) ) ;
}
double derivative_2 ( double num )
{
    return ( cos(num) ) ;
}
double decimal_places_calc2 ( int dp )
{
    return ( (double)( pow(0.1,dp) ) ) ;
}
double calc_xnew ( double x , double fx , double f_dash_x )
{
    double x_new ;
    x_new = x - fx / f_dash_x ;
    return x_new ;
}
double calculate ( double x , int decimal_places )
{

    double x_old , fx , f_dash_x , x_new , dp ;
    dp = decimal_places_calc2 ( decimal_places ) ;
    do
    {
    x_old = x_new ;
    fx =  func2 ( x_old ) ;
    f_dash_x =  derivative_1 ( x_old ) ;

    x_new = calc_xnew ( x_old , fx , f_dash_x ) ;


    }while ( abs(x_old - x_new) > dp ) ;

    return x_new ;

}
bool check_number ( double x )
{
    double c ;

    c = abs( (func2 ( x ) *  derivative_2(x)) / pow(derivative_1(x),2)) ;

    return ( c < 1 ) ;
}

int solveNEWTONS_METHOD ()
{
    double x ;
    int decimal_places ;

    x:
        cls;
        VS vec;
        vec.pb(" \6\6 Enter X \6\6 ");
        printBOX(vec);
        vec.clear();
        end;
        responsive(1);
    cin >> x ;

        vec.pb(" Enter Decimal Places ");
        printBOX(vec);
        vec.clear();
        end;
        responsive(1);
        cin >> decimal_places ;

    if ( !(check_number ( x )) )
    {
        vec.pb(" !! Please Retry Another Number !! ");
        printBOX(vec);
        vec.clear();
        end;
        Sleep(2000);
        goto x ;
    }
    else
    {
        vec.pb("X Approximately Equals " + toString2((float)calculate ( x , decimal_places )));
        printBOX(vec);
        vec.clear();
        end;
    }
    return 0 ;
}
