#include<iostream>
#include<cmath>
using namespace std ;
double func ( double num )
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
double decimal_places_calc ( int dp )
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
    dp = decimal_places_calc ( decimal_places ) ;
    do
    {
    x_old = x_new ;
    fx =  func ( x_old ) ;
    f_dash_x =  derivative_1 ( x_old ) ;

    x_new = calc_xnew ( x_old , fx , f_dash_x ) ;


    }while ( abs(x_old - x_new) > dp ) ;

    return x_new ;

}
bool check_number ( double x )
{
    double c ;

    c = abs( (func ( x ) *  derivative_2(x)) / pow(derivative_1(x),2)) ;

    return ( c < 1 ) ;
}

int main ()
{
    double x ;
    int decimal_places ;
    x:cout << "Enter X: \n" ;
    cin >> x ;

    cout << "Enter Decimal Places : \n" ;
        cin >> decimal_places ;

    if ( !(check_number ( x )) )
    {
        cout << "Please Retry Another Number \n" ;
        goto x ;
    }
    else
    {
        cout << "\nX Approximately Equals " << (float)calculate ( x , decimal_places ) ;
    }

    return 0 ;
}
