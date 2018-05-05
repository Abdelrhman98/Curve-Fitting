#include<iostream>
#include<stdlib.h>
#include<cmath>
#include <iomanip>
using namespace std ;
const double E = 2.71828182845904523536 ;
void calc_a_b(float &a , float &b , float  a1 , float  a2 , float  b1 , float  b2  , float  c1 , float  c2 )
{
    a = 0.00001 ;
    b = 0.00001 ;
    float det;
	det = a1*b2 - a2*b1;

    a = (c1*b2 - b1*c2) / det;
    b = (a1*c2 - c1*a2) / det;
}
void straight_line()
{
    int noOfPoints ;
    float *x , *y , *xy , *x2 ;
    float a , b , a1 , a2 , b1 , b2 , c1 , c2 ;

    cout << "Enter Number Of Points : " ;
        cin >> noOfPoints ;

    system("CLS") ;

    x = new float [noOfPoints+1] ;
    y = new float [noOfPoints+1] ;
    xy = new float [noOfPoints+1] ;
    x2 = new float [noOfPoints+1] ;

    x[noOfPoints] = 0 ;
    y[noOfPoints] = 0 ;
    xy[noOfPoints] = 0 ;
    x2[noOfPoints] = 0 ;

    cout << endl ;

    cout << "Enter Points \n \n" ;

    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        cout << "Enter x" << i << " : ";
            cin >> x[i] ;
            x[noOfPoints] += x[i] ;
        cout << "Enter F(" << x[i] << ") : ";
            cin >> y[i] ;
            y[noOfPoints] += y[i] ;
        cout << endl ;
        xy[i] = x[i] * y[i] ;
        xy[noOfPoints] += xy[i] ;
        x2[i] = x[i] * x[i] ;
        x2[noOfPoints] += x2[i] ;
    }

    system("CLS") ;

    cout << "x\tY\txY\tx^2\n\n" ;
    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        cout << x[i] << "\t" << y[i] << "\t" << xy[i] << "\t" << x2[i] << "\n" ;
    }

    cout << "----------------------------\n";
    cout << x[noOfPoints] << "\t" << y[noOfPoints] << "\t" << xy[noOfPoints] << "\t" << x2[noOfPoints] << "\n" ;

    cout << endl << endl << endl ;

    calc_a_b( a , b , x[noOfPoints] , x2[noOfPoints] , noOfPoints , x[noOfPoints] , y[noOfPoints] , xy[noOfPoints] ) ;

    cout << "a = " << a << endl ;
    cout << "b = " << b << endl << endl;

    cout << "y = " << a << "x" << " + " << b << endl ;
}
void exponential()
{
    int noOfPoints ;
    float *x , *y , *Y , *x2 , *xY;
    float a , b , a1 , a2 , b1 , b2 , c1 , c2 ;

    cout << "Enter Number Of Points : " ;
        cin >> noOfPoints ;

    system("CLS") ;

    x = new float [noOfPoints+1] ;
    y = new float [noOfPoints+1] ;
    Y = new float [noOfPoints+1] ;
    x2 = new float [noOfPoints+1] ;
    xY = new float [noOfPoints+1] ;

    x[noOfPoints] = 0 ;
    y[noOfPoints] = 0 ;
    Y[noOfPoints] = 0 ;
    x2[noOfPoints] = 0 ;
    xY[noOfPoints] = 0 ;

    cout << endl ;

    cout << "Enter Points \n \n" ;

    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        cout << "Enter x" << i << " : ";
            cin >> x[i] ;
            x[noOfPoints] += x[i] ;
        cout << "Enter F(" << x[i] << ") : ";
            cin >> y[i] ;
            y[noOfPoints] += y[i] ;
        cout << endl ;
        Y[i] = log(y[i]) ;
        Y[noOfPoints] += Y[i] ;
        xY[i] = x[i] * Y[i] ;
        xY[noOfPoints] += xY[i] ;
        x2[i] = x[i] * x[i] ;
        x2[noOfPoints] += x2[i] ;
    }

    system("CLS") ;

    cout << "x\ty\tY\t\tx^2\txY\n\n" ;
    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        cout << x[i] << "\t" << y[i] << "\t" << Y[i] << "\t\t" << x2[i] << "\t" << xY[i] << "\n" ;
    }

    cout << "---------------------------------------------\n";
    cout << x[noOfPoints] << "\t" << y[noOfPoints] << "\t" << Y[noOfPoints] << "\t\t" << x2[noOfPoints] << "\t" << xY[noOfPoints] << "\n" ;

    calc_a_b( a , b , x[noOfPoints] , x2[noOfPoints] , noOfPoints , x[noOfPoints] , Y[noOfPoints] , xY[noOfPoints] ) ;

    cout << "a = " << exp(a) << endl ;
    cout << "b = " << b/log(E) << endl << endl;

    cout << "y = " << exp(a) << "x" << " + " << b/log(E) << endl ;

}
void y_eq_a_x_b()
{
    int noOfPoints ;
    float *x , *y , *X , *Y , *X2 , *xY , *XY;
    float a , b , a1 , a2 , b1 , b2 , c1 , c2 ;

    cout << "Enter Number Of Points : " ;
        cin >> noOfPoints ;

    system("CLS") ;

    x = new float [noOfPoints+1] ;
    y = new float [noOfPoints+1] ;
    X = new float [noOfPoints+1] ;
    Y = new float [noOfPoints+1] ;
    X2 = new float [noOfPoints+1] ;
    XY = new float [noOfPoints+1] ;

    x[noOfPoints] = 0 ;
    y[noOfPoints] = 0 ;
    X[noOfPoints] = 0 ;
    Y[noOfPoints] = 0 ;
    X2[noOfPoints] = 0 ;
    XY[noOfPoints] = 0 ;

    cout << endl ;

    cout << "Enter Points \n \n" ;

    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        cout << "Enter x" << i << " : ";
            cin >> x[i] ;
            x[noOfPoints] += x[i] ;
        cout << "Enter F(" << x[i] << ") : ";
            cin >> y[i] ;
            y[noOfPoints] += y[i] ;
        cout << endl ;
        X[i] = log(x[i]) ;
        X[noOfPoints] += X[i] ;
        Y[i] = log(y[i]) ;
        Y[noOfPoints] += Y[i] ;
        XY[i] = X[i] * Y[i] ;
        XY[noOfPoints] += XY[i] ;
        X2[i] = X[i] * X[i] ;
        X2[noOfPoints] += X2[i] ;
    }

    system("CLS") ;

    cout << "x\ty\tX\t\tY\t\tX^2\t    XY\n\n" ;
    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        cout << x[i] << "\t" << y[i] << "\t" << setprecision(4) << X[i] << "\t\t" << Y[i] << "\t\t" << X2[i] << setprecision(4) << "\t    " << XY[i] << "\n" ;
    }

    cout << "--------------------------------------------------------------\n";
    cout << x[noOfPoints] << "\t" << y[noOfPoints] << "\t" << X[noOfPoints] << "\t\t"  << Y[noOfPoints] << "\t\t" << setprecision(4) << X2[noOfPoints] << "\t    "  << setprecision(4) << XY[noOfPoints] << "\n" ;

    calc_a_b( a , b , X[noOfPoints] , X2[noOfPoints] , noOfPoints , X[noOfPoints] , Y[noOfPoints] , XY[noOfPoints] ) ;

    cout << "a = " << log(a) << endl ;
    cout << "b = " << b << endl << endl;

    cout << "y = " << log(a) << "x" << " + " << b << endl ;

}
void parabola()
{
    int noOfPoints ;
    float *x , *y , *xy , *x2 , *x3 , *x2y , *x4 ;

    cout << "Enter Number Of Points : " ;
        cin >> noOfPoints ;

    system("CLS") ;

    x = new float [noOfPoints+1] ;
    y = new float [noOfPoints+1] ;
    xy = new float [noOfPoints+1] ;
    x2 = new float [noOfPoints+1] ;
    x3 = new float [noOfPoints+1] ;
    x4 = new float [noOfPoints+1] ;
    x2y = new float [noOfPoints+1] ;

    x[noOfPoints] = 0 ;
    y[noOfPoints] = 0 ;
    xy[noOfPoints] = 0 ;
    x2[noOfPoints] = 0 ;
    x3[noOfPoints] = 0 ;
    x4[noOfPoints] = 0 ;
    x2y[noOfPoints] = 0 ;

    cout << endl ;

    cout << "Enter Points \n \n" ;

    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        cout << "Enter x" << i << " : ";
            cin >> x[i] ;
            x[noOfPoints] += x[i] ;
        cout << "Enter F(" << x[i] << ") : ";
            cin >> y[i] ;
            y[noOfPoints] += y[i] ;

        xy[i] = x[i] * y[i] ;
        xy[noOfPoints] += xy[i] ;
        x2[i] = x[i] * x[i] ;
        x2[noOfPoints] += x2[i] ;
        x3[i] = x[i] * x[i] * x[i] ;
        x3[noOfPoints] += x3[i] ;
        x4[i] = x[i] * x[i] * x[i] * x[i] ;
        x4[noOfPoints] += x4[i] ;
        x2y[i] = x2[i] * y[i] ;
        x2y[noOfPoints] += x2y[i] ;

        cout << endl ;
    }

    system("CLS") ;

    cout << "x\ty\txY\tx^2\tx^3\tx^4\t(x^2)Y\n\n" ;
    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        cout << x[i] << "\t" << y[i] << "\t" << xy[i] << "\t" << x2[i] << "\t" << x3[i] << "\t" << x4[i] << "\t" << x2y[i] << "\n" ;
    }

    cout << "--------------------------------------------------------\n";
    cout << x[noOfPoints] << "\t" << y[noOfPoints] << "\t" << xy[noOfPoints] << "\t" << x2[noOfPoints] << "\t" << x3[noOfPoints] << "\t" << x4[noOfPoints] << "\t" << x2y[noOfPoints] << "\n" ;

}
void choices()
{

    cout << "..:: Curve Fitting ::..\n\n\n";
    cout << "Choose Type Of Curve : \n\n";


    cout << "1.Straight Line ( y = ax + b ) \n\n";
    cout << "2.Parabola ( y = ax^2 + bx + c ) \n\n";
    cout << "3.Exponential ( y = ae^bx ) \n\n";
    cout << "4.curve ( y = ax^b ) \n\n";
}

int main ()
{
    int choice ;
    start:
    system("CLS") ;
    choices() ;
    cout << "Your Choice : " ;
    cin >> choice ;

    cout << endl << endl ;
    system("CLS") ;
    switch(choice)
    {
        case 1 :
            straight_line() ;
            break ;
        case 2 :
            parabola() ;
            break ;
        case 3 :
            exponential() ;
            break ;
        case 4 :
             y_eq_a_x_b();
             break ;
        default :
            goto start ;
    }

    return 0 ;
}
