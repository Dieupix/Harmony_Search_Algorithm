// OptUHA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myAlgorithm.h"

using namespace std;

int main()
{
    unsigned nb_funcs = 4;

    double hmcr = 0.9;
    double par = 0.09;

    harmonySearch myAlgo{hmcr, par};

    for(unsigned func_num = 0; func_num < nb_funcs; ++func_num)
    {
        myAlgo.solve(func_num+1);
    }
}

