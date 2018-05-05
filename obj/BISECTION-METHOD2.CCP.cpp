#include<iostream>
#include<cmath>
using namespace std ;
double func ( double num )
{
    return ( pow(num,3) + 4*pow(num,2) - 10 ) ;
}
double decimal_places_calc ( int dp )
{
    return ( ( pow(0.1,dp) ) ) ;
}
double calculate_root ( double a , double b , int decimal_places )
{
    double dp = decimal_places_calc(decimal_places) ;
    double c , answer , acc ;

    cout << endl ;
    cout << "a \t\tb \t\tc\t\t\tf(c) \n\n" ;
    do
    {
        cout << (float)a << "\t\t" << b << "\t";
        c = ( a + b ) / 2 ;
        answer = func(c) ;

        if ( answer < 0 )
        {
            a = c ;
            cout << "\t" << (float) c << "\t\t\t" << "(-)" << -answer << endl ;
        }
        else
        {
            b = c ;
            cout << "\t" << (float) c << "\t\t\t" << "(+)" << answer << endl ;
        }

        acc = b - a ;

    } while ( acc > dp ) ;

    return c ;
    }
int main ()
{
    double a , b ;
    int decimal_places ;
    a:cout << "Enter A , B : \n" ;
    cin >> a >> b ;

    cout << "Enter Decimal Places : \n" ;
        cin >> decimal_places ;

    if ( ( func(a) > 0 && func(b) > 0 ) || ( func(a) < 0 && func(b) < 0 ) )
    {
        cout << "Please Retry Another 2 Numbers \n" ;
        goto a ;
    }
    else if ( func(a) > 0 )
    {
        double temp ;
        temp = a ;
        a = b ;
        b = temp ;

        cout << "\nX Approximately Equal " << (float)calculate_root ( a , b , decimal_places ) ;
    }
    else if ( func(b) < 0 )
    {
        double temp ;
        temp = b ;
        b = a ;
        a = temp ;

        cout << "\nX Approximately Equals " << (float)calculate_root ( a , b , decimal_places ) ;
    }
    else
    {
        cout << "\nX Approximately Equals " << (float)calculate_root ( a , b , decimal_places ) ;
    }

    return 0 ;
}
