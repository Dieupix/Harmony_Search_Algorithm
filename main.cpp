// OptUHA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "myAlgorithm.h"
#include "OptUHA.h"

int main()
{
    srand((unsigned)time(NULL));
    int num_runs = 10;
    int num_funcs = 12; 
    vector<vector<double>> obj_vals_array(num_funcs);
    for (int func = 0; func < num_funcs; func++)
    {
        for (int run = 0; run < num_runs; run++)
        {
            myAlgorithm* myAlgo = new myAlgorithm();
            double fitness = myAlgo->solve(func + 1);
            obj_vals_array[func].push_back(fitness);
            cout << "function: " << func << " obj_val: " << fitness << endl;
            if (myAlgo)
                delete myAlgo; myAlgo = NULL;
        }
    }

}

