#include "objective_func.h"
#include<cmath>

double schifed_Sphere_func(const solution x)
{
    double f_bias = -450 ;
    double res = 0 ;
    for( unsigned i = 0 ; i < x.size() ; i++ )
    {
        res += x[i] ;
    }
    return res + f_bias ;
}

double shifted_Rosenbrock_func(const solution& x)
{
    double f_bias = -450;
    double res = 0.0;
    for(unsigned i{0} ; i< x.size()-1 ; ++i)
        {
            res += 100*(pow( pow(x[i],2) - x[i+1],2) ) + pow(x[i]-1,2) ;
        }
    return res + f_bias;
}

double shifted_Griewank_func(const solution& x)
{
    double f_bias = -180;
    double sum = 0;
    double product = 1;

    for(unsigned i = 0; i < x.size(); ++i){
        sum += pow(x[i], 2) / 4000;
        product *= cos(x[i]/sqrt(i));
    }

    return sum - product + 1 + f_bias;
}

