#include "OptUHA.h"

int OptUHA::generate_random_int(int from, int to)
{
    int nRand;
    nRand = rand() % (to - from + 1) + from;
    return nRand;
}

double OptUHA::generate_random_double(double from, double to)
{
    double nRand ;
    nRand = from + (double)rand() / (double)(RAND_MAX / (to - from));
    return nRand;
}





