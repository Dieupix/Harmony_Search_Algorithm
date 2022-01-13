#include "objective_func.h"

double shifted_Sphere_func(const solution& x)
{
    double f_bias = -450 ;
    double res = 0 ;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i] - 0;
        res += z * z;
    }

    return res + f_bias;
}

double shifted_Rastrigin_func(const solution& x)
{
    double f_bias = -330;
    double sum = 0;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i] - 0;
        sum += (z * z) - 10 * cos(2 * M_PI * z) + 10;
    }

    return sum + f_bias;
}

double shifted_Griewank_func(const solution& x)
{
    double f_bias = -180;
    double sum = 0;
    double product = 1;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i] - 0;
        sum += (z * z) / 4000;
        product *= cos(z / sqrt(i+1));
    }

    return sum - product + 1 + f_bias;
}

double shifted_Rosenbrock_func(const solution& x)
{
    double f_bias = 390;
    double res = 0;
    double z = 0, z1 = 0;

    for(unsigned i = 0; i < x.size()-1; ++i)
    {
        z = x[i] - 0 + 1;
        z1 = x[i+1] - 0 + 1;

        res += 100 * ((z * z) - z1) * ((z * z) - z1) + (z-1) * (z-1);
    }

    return res + f_bias;
}

