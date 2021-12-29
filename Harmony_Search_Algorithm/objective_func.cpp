#include "objective_func.h"
#include<cmath>

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

double shifted_Rosenbrock_func(const solution& x)
{
    double f_bias = -450;
    double res = 0.0;
    for(int i{0} ; i< x.size()-1 ; ++i)
        {
            res += 100*(pow( pow(x[i],2) - x[i+1],2) ) + pow(x[i]-1,2) ;
        }
    return res + f_bias;
}
