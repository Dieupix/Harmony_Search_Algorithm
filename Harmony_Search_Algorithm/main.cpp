// OptUHA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myAlgorithm.h"
#include <cstdlib>

using namespace std;

/*
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
*/

int main()
{
    unsigned func_num = 0, num_funcs = 4;

    double hmcr = 0.2;
    double par = 0.005;

    harmonySearch myAlgo{hmcr,par};

    for(func_num = 0; func_num < num_funcs; ++func_num)
    {
        myAlgo.solve(func_num+1);
    }

    /*OptUHA opt;
    for(unsigned i = 0; i < 99; ++i) // TEST THE RANDOM GENERATOR ENGINE
    {
        cout << opt.generate_random_double(0, 10) << endl;
    }*/

}

