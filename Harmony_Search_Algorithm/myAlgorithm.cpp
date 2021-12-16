#include "myAlgorithm.h"
#include "OptUHA.h"

harmonySearch::harmonySearch(double hmcr, double par) : HMCR{hmcr}, PAR{par}
{}

void harmonySearch::run(int func_num)
{
    population = GenerateRandomPop();
    //evaluate_pop(func_num);
    while(nbIterations < nbIterationsTotales && !CA)
    {
        solution X = create_new_solution(n);
        for(int j{0} ; j < X.size() ; ++j)
            {
                if(generate_random_double(0.0,1.0) < HMCR)
                {
                    double val = population[generate_random_int(0,HMS)][j];
                    if(generate_random_double(0.0,1.0) < PAR)
                    {
                        //mute(val);
                    }
                    X[j] = val;
                }
                else X[j] = generate_random_double(20.0,20000.0);
            }
        //double fX = evaluate_solution(func_num,X);
        //CA = fX < critere;
        /*int ind_worst = FindWorstSolution();
        if(fX > fitness[ind_worst])
        {
            UpdatePopulation(func_num,ind_worst,X);
        }*/
        ++nbIterations;
    }
}



double harmonySearch::solve(int func_num)
{
    solution sol(dimension);
    for(unsigned i = 0; i < nbIterationsTotales; ++i)
    {
        run(func_num);
        print_solution(population[best], fitness[best]);
    }
    return fitness[best];
}

void harmonySearch::update_fitness(int idx, double fitness_val)
{
    fitness[idx] = fitness_val;
}

