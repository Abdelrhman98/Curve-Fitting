#include "Curve-Fitting.h"
#include <bits/stdc++.h>
#include "GUI.h"
#include "template.cpp"
using namespace std ;
template <typename T>
string toString2(T temp){
    stringstream ss;
    ss << temp;
    return ss.str();
}
const double E = 2.71828182845904523536 ;
void calc_a_b(float &a , float &b , float  a1 , float  a2 , float  b1 , float  b2  , float  c1 , float  c2 ){
    a = 0.00001 ;
    b = 0.00001 ;
    float det;
	det = a1*b2 - a2*b1;
    a = (c1*b2 - b1*c2) / det;
    b = (a1*c2 - c1*a2) / det;
}

void straight_line(){
    int noOfPoints ;
    float *x , *y , *xy , *x2 ;
    float a , b , a1 , a2 , b1 , b2 , c1 , c2 ;
    VS vec;
    vec.pb(" \1\1 Enter Number Of Points \1\1 ");
    printBOX(vec);
    vec.clear();
    end;
    responsive(2);
    cin >> noOfPoints ;
    cls;

    x = new float [noOfPoints+1] ;
    y = new float [noOfPoints+1] ;
    xy = new float [noOfPoints+1] ;
    x2 = new float [noOfPoints+1] ;

    x[noOfPoints] = 0 ;
    y[noOfPoints] = 0 ;
    xy[noOfPoints] = 0 ;
    x2[noOfPoints] = 0 ;

    end;
    vec.pb(" \3\3Enter Points \3\3 ");
    printBOX(vec);
    vec.clear();
    end;
    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        vec.pb("Enter x"  +  toString2(i) + " : ");
        printBOX(vec);
        vec.clear();
        end;

        responsive(1);
        cin >> x[i] ;
        x[noOfPoints] += x[i] ;

        vec.pb("Enter F("  +  toString2(x[i]) + ") : ");
        printBOX(vec);
        vec.clear();
        end;
            responsive(1);
            cin >> y[i] ;
            y[noOfPoints] += y[i] ;
        cout << endl ;
        xy[i] = x[i] * y[i] ;
        xy[noOfPoints] += xy[i] ;
        x2[i] = x[i] * x[i] ;
        x2[noOfPoints] += x2[i] ;
        cls;
    }
    cls;
    vec.pb("x    Y    xY    x^2");
    printBOX(vec);
    vec.clear();
    end;
    for ( int i = 0 ; i < noOfPoints ; i++ )
    {
        vec.pb(toString2(x[i]) + "    " + toString2(y[i]) + "    " + toString2(xy[i]) + "    " + toString2(x2[i]));
    }
    printBOX(vec);
    vec.clear();
    end;
    vec.pb(toString2( x[noOfPoints] ) + "    " + toString2(y[noOfPoints]) + "    " + toString2(xy[noOfPoints]) + "    " + toString2(x2[noOfPoints]));
    printBOX(vec);
    vec.clear();
    end;

    calc_a_b( a , b , x[noOfPoints] , x2[noOfPoints] , noOfPoints , x[noOfPoints] , y[noOfPoints] , xy[noOfPoints] ) ;

    vec.pb("a = " + toString2(a) );
    vec.pb("b = " + toString2(b) );
    vec.pb("y = " + toString2(a) + "x" + " + " + toString2(b) );
    printBOX(vec);
    end;
}
void exponential()
{
    int noOfPoints ;
    float *x , *y , *Y , *x2 , *xY;
    float a , b , a1 , a2 , b1 , b2 , c1 , c2 ;

    VS vec;
    vec.pb(" \1\1 Enter Number Of Points \1\1 ");
    printBOX(vec);
    vec.clear();
    end;
    responsive(2);
    cin >> noOfPoints ;

    cls;

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

    vec.pb(" \3\3Enter Points \3\3 ");
    printBOX(vec);
    vec.clear();
    end;

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

    cls;

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

    VS vec;
    vec.pb(" \1\1 Enter Number Of Points \1\1 ");
    printBOX(vec);
    vec.clear();
    end;
    responsive(2);
    cin >> noOfPoints ;

    cls;

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

    vec.pb(" \3\3Enter Points \3\3 ");
    printBOX(vec);
    vec.clear();
    end;

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

    VS vec;
    vec.pb(" \1\1 Enter Number Of Points \1\1 ");
    printBOX(vec);
    vec.clear();
    end;
    responsive(2);
    cin >> noOfPoints ;

    cls

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

    vec.pb(" \3\3Enter Points \3\3 ");
    printBOX(vec);
    vec.clear();
    end;

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

    cls;

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
    VS vec;
    vec.pb(" ..:: Curve Fitting ::.. ");
    printBOX(vec);
    vec.clear();
    end;
    vec.pb(" \3\3 Choose Type Of Curve \3\3 ");
    printBOX(vec);
    vec.clear();
    end;
    vec.pb(" 1.Straight Line ( y = ax + b ) ");
    vec.pb(" 2.Parabola ( y = ax^2 + bx + c ) ");
    vec.pb(" 3.Exponential ( y = ae^bx ) ");
    vec.pb(" 4.curve ( y = ax^b ) ");
    printBOX(vec);
    end;
}

int solveCURVE_FITTING()
{
    int choice ;
    start:
    cls;
    choices() ;
    VS vec;
    vec.pb(" \3\3 Your Choice \3\3 ");
    printBOX(vec);
    end;
    responsive(1);
    cin >> choice ;
    cls;
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
