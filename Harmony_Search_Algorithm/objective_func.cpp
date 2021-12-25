#include "objective_func.h"

double schifed_Sphere_func(const solution x)
{
    double f_bias = -450 ;
    double res = 0 ;
    for( int i = 0 ; i < x.size() ; i++ )
    {
        res += x[i] ;
    }
    return res + f_bias ;
}

double shifted_Griewank_func(double x)
{
    double sgf = 0.0;

    return sgf;
}
