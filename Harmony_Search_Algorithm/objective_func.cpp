#include "myAlgorithm.h"

double harmonySearch::shifted_Sphere_func(const solution& x)
{
    double res = 0 ;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i];
        res += z * z;
    }

    if(res < critere)
    {
        res = 0;
        CA = true;
    }

    return res;
}

double harmonySearch::shifted_Rastrigin_func(const solution& x)
{
    double res = 0;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i];
        res += (z * z) - 10 * cos(2 * M_PI * z) + 10;
    }

    if(res < critere)
    {
        res = 0;
        CA = true;
    }

    return res;
}

double harmonySearch::shifted_Griewank_func(const solution& x)
{
    double sum = 0;
    double product = 1;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i];
        sum += (z * z) / 4000;
        product *= cos(z / sqrt(i+1));
    }

    double res = sum - product + 1;

    if(res < critere)
    {
        res = 0;
        CA = true;
    }

    return res;
}

double harmonySearch::shifted_Rosenbrock_func(const solution& x)
{
    double res = 0;
    double z = 0, z1 = 0;

    for(unsigned i = 0; i < x.size()-1; ++i)
    {
        z = x[i] + 1;
        z1 = x[i+1] + 1;

        auto sq = ((z * z) - z1) * ((z * z) - z1);
        auto sq1 = (z-1) * (z-1);

        res += 100 * sq + sq1;
    }

    if(res < critere)
    {
        res = 0;
        CA = true;
    }

    return res;
}
