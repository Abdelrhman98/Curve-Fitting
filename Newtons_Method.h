#ifndef NEWTONS_METHOD_H_INCLUDED
#define NEWTONS_METHOD_H_INCLUDED
double func2 ( double num );
double derivative_1 ( double num );
double derivative_2 ( double num );
double decimal_places_calc2 ( int dp );
double calc_xnew ( double x , double fx , double f_dash_x );
double calculate ( double x , int decimal_places );
bool check_number ( double x );
int solveNEWTONS_METHOD ();


#endif // NEWTONS_METHOD_H_INCLUDED
