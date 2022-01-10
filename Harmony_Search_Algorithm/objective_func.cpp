#include "objective_func.h"

solution changeIntervalle(const solution& s, double low, double high)
{
    double from = 20, to = 20000;
    double oldRange = to - from;
    solution newSol(s.size());

    for(unsigned i = 0; i < s.size(); ++i)
    {
        double newRange = high - low;
        newSol[i] = (((s[i] - from) * newRange) / oldRange) + low;
    }

    return newSol;
}

double shifted_Sphere_func(const solution& x)
{
    double high = 100, low = -100;
    auto newX = changeIntervalle(x, low, high);

    double f_bias = -450 ;
    double res = 0 ;
    for(unsigned i = 0; i < newX.size(); ++i)
    {
        res += newX[i] * newX[i];
    }
    return res;
}

double shifted_Rosenbrock_func(const solution& x)
{
    double high = 100, low = -100;
    auto newX = changeIntervalle(x, low, high);

    double f_bias = 390;
    double res = 0.0;
    for(unsigned i = 0; i < newX.size()-1; ++i)
    {
        res += 100 * (pow((newX[i] * newX[i]) - newX[i+1], 2)) + pow(newX[i]-1, 2);
    }
    return res;
}

double shifted_Griewank_func(const solution& x)
{
    double high = 600, low = -600;
    auto newX = changeIntervalle(x, low, high);

    double f_bias = -180;
    double sum = 0;
    double product = 1;

    for(unsigned i = 0; i < newX.size(); ++i){
        sum += (newX[i] * newX[i]) / 4000;
        product *= cos(newX[i]/sqrt(i+1));
    }

    return sum - product + 1;
}

double shifted_Rastrigin_func(const solution& x)
{
    double high = 5, low = -5;
    auto newX = changeIntervalle(x, low, high);

    double f_bias = -330;
    double sum = 0;

    for(unsigned i = 0; i < newX.size(); ++i)
        sum += (newX[i] * newX[i]) - 10 * cos(2 * M_PI * newX[i]) + 10;

    return sum;
}

