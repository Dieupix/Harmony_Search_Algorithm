#include "objective_func.h"

double shifted_Sphere_func(const solution& x)
{
    double f_bias = -450 ;
    double res = 0 ;
    for(unsigned i = 0; i < x.size(); ++i)
    {
        res += x[i] * x[i];
    }
    return res + f_bias;
}

double shifted_Rastrigin_func(const solution& x)
{
    double f_bias = -330;
    double sum = 0;

    for(unsigned i = 0; i < x.size(); ++i)
        sum += (x[i] * x[i]) - 10 * cos(2 * M_PI * x[i]) + 10;

    return sum + f_bias;
}

double shifted_Griewank_func(const solution& x)
{
    double f_bias = -180;
    double sum = 0;
    double product = 1;

    for(unsigned i = 0; i < x.size(); ++i){
        sum += (x[i] * x[i]) / 4000;
        product *= cos(x[i]/sqrt(i+1));
    }

    return sum - product + 1 + f_bias;
}

double shifted_Rosenbrock_func(const solution& x)
{
    double f_bias = 390;
    double res = 0.0;
    for(unsigned i = 0; i < x.size()-1; ++i)
    {
        res += 100 * ((x[i] * x[i]) - x[i+1]) * ((x[i] * x[i]) - x[i+1]) + (x[i]-1) * (x[i]-1);
    }
    return res + f_bias;
}

