#include "objective_func.h"

#define M_PI 3.14159265358979323846

solution changeIntervalle(const solution& s, double high, double low)
{
    double from = 20, to = 20000;
    solution newSol(s.size());

    for(unsigned i = 0; i < s.size(); ++i)
    {
        double oldRange = to - from;
        if(oldRange == 0)
        {
            newSol[i] = low;
        }
        else
        {
            double newRange = high - low;
            newSol[i] = (((s[i] - from) * newRange) / oldRange) + low;
        }
    }

    return newSol;
}

double shifted_Sphere_func(const solution& x)
{
    double high = 100, low = -100;
    auto newX = changeIntervalle(x, high, low);

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
    double high = 100, low = -100;
    auto newX = changeIntervalle(x, high, low);

    double f_bias = -450;
    double res = 0.0;
    for(unsigned i{0}; i< newX.size()-1; ++i)
        {
            res += 100*(pow( pow(newX[i],2) - newX[i+1],2) ) + pow(newX[i]-1,2) ;
        }
    return res + f_bias;
}

double shifted_Griewank_func(const solution& x)
{
    double high = 600, low = -600;
    auto newX = changeIntervalle(x, high, low);

    double f_bias = -180;
    double sum = 0;
    double product = 1;

    for(unsigned i = 0; i < newX.size(); ++i){
        sum += pow(newX[i], 2) / 4000;
        product *= cos(newX[i]/sqrt(i));
    }

    return sum - product + 1 + f_bias;
}

double shifted_Rastrigin_func(const solution& x)
{
    double high = 5, low = -5;
    auto newX = changeIntervalle(x, high, low);

    double f_bias = -330;
    double sum = 0;

    for(unsigned i = 0; i < newX.size(); ++i)
        sum += (pow(newX[i],2) - 10 * cos(2 * M_PI) + 10);
    return sum + f_bias;
}

