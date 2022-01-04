// OptUHA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <time.h>
#include "myAlgorithm.h"
#include "OptUHA.h"

int main()
{
    srand(time(NULL));
    double hmcr = 0.5;//0
    double par = 0.01;//0
    //
    int num_runs = 10;
    int num_funcs = 1;//12
    vector<vector<double>> obj_vals_array(num_funcs);

    for (int func = 0; func < num_funcs; func++)
    {
        for (int run = 0; run < num_runs; run++)
        {
            harmonySearch* myAlgo = new harmonySearch(hmcr,par);
            double fitness = myAlgo->solve(func + 1);
            obj_vals_array[func].push_back(fitness);
            cout << "function: " << func << " obj_val: " << fitness << endl;
            if (myAlgo)
                delete myAlgo; myAlgo = NULL;
        }
    }
}


/*
double generate_random_double(double from, double to)
{
    double nRand ;
    nRand = from + (double)rand() / (double)(RAND_MAX / (to - from));
    return nRand;
}

int main()
{
    for(int i{0} ; i<30 ; ++i)
        {
          double x = generate_random_double(20.0, 20000.0);
          cout<<x<<endl;
        }
}
*/
