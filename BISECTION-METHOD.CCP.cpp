#include "BISECTION-METHOD.h"
#include "template.cpp"
#include "GUI.h"
#include <bits/stdc++.h>
#include <string>
using namespace std ;

template <typename T>
string toString2(T temp){
    stringstream ss;
    ss << temp;
    return ss.str();
}

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

    end;
    VS vecGrid;
    vecGrid.pb(" a            b           c                    f(c)             ");
    printBOX(vecGrid);
    vecGrid.clear();
    end;
    do
    {
        string strCollector = toString2((float)a) + "        " + toString2(b) + "    ";
        c = ( a + b ) / 2 ;
        answer = func(c) ;

        if ( answer < 0 )
        {
            a = c ;
            strCollector += "    " + toString2((float) c) + "            " + "(-)" + toString2(-answer);

        }
        else
        {
            b = c ;
            strCollector += "    " + toString2((float) c) + "            " + "(+)" + toString2(answer);
        }

        acc = b - a ;
    vecGrid.pb(strCollector);
    printBOX(vecGrid);
    vecGrid.clear();
    end;
    } while ( acc > dp ) ;

    return c ;
    }




int solveBISECITION()
{
    double a , b ;
    int decimal_places ;
    a:
        cls;
        VS vec;
        vec.pb(" \2\2 Enter A , B  \2\2 ");
        printBOX(vec);
        end;

    responsive(2);
    cin >> a >> b ;

    vec.clear();
    vec.pb(" \6\6 Enter Decimal Places \6\6 ");
    printBOX(vec);
    end;

    responsive(1);
    cin >> decimal_places ;

    if ( ( func(a) > 0 && func(b) > 0 ) || ( func(a) < 0 && func(b) < 0 ) )
    {
        vec.clear();
        vec.pb(" \3\3 Please Retry Another 2 Numbers \3\3 ");
        printBOX(vec);
        end;
        goto a ;
    }

    else if ( func(a) > 0 )
    {
        double temp ;
        temp = a ;
        a = b ;
        b = temp ;
        VS vec;
        vec.pb("X Approximately Equal " +  toString2((float)calculate_root ( a , b , decimal_places )));
        printBOX(vec);
        end;
    }
    else if ( func(b) < 0 )
    {
        double temp ;
        temp = b ;
        b = a ;
        a = temp ;

        VS vec;
        vec.pb("X Approximately Equals " +  toString2((float)calculate_root ( a , b , decimal_places )));
        printBOX(vec);
        end;
    }
    else
    {
        VS vec;
        vec.pb("X Approximately Equals " +  toString2((float)calculate_root ( a , b , decimal_places )));
        printBOX(vec);
        end;
    }

    return 0 ;
}
