#include "objective_func.h"
#include<cmath>

solution changeInterval(const solution& s, double high, double low)
{
    double from = 20, to = 20000;
    solution newSol(s.size());

    for(unsigned i = 0; i < s.size(); ++i)
    {
        newSol[i] = ((high - low) / (from - to)) * (from - to) + low;
    }

    return newSol;
}

double shifted_Sphere_func(const solution& x)
{
    double high = 100, low = -100;
    auto newX = changeInterval(x, high, low);

    double f_bias = -450 ;
    double res = 0 ;
    for(unsigned i = 0; i < newX.size(); ++i)
    {
        res += pow(newX[i], 2) ;
    }
    return res + f_bias;
}

double shifted_Rosenbrock_func(const solution& x)
{
    double f_bias = -450;
    double res = 0.0;
    for(unsigned i{0}; i< x.size()-1; ++i)
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

double shifted_Rastrigin_func(const solution & x)
{
    double f_bias = -330;
    double sum = 0;

    for(unsigned i = 0; i < x.size(); ++i)
        sum += (pow(x[i],2) - 10 * cos(2 * 3.141592) + 10);
    return sum + f_bias;
}

