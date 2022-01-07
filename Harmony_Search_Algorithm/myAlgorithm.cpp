#include "myAlgorithm.h"
#include "OptUHA.h"

void affiche_population(const vector<solution>& population)
{
    for(unsigned i = 0; i< population.size(); ++i)
    {
        for(unsigned j = 0; j< population.size(); ++j)
        {
            cout << population[i][j] << " " ;
        }
        cout << endl;
    }
}

harmonySearch::harmonySearch(double hmcr, double par) : HMCR{hmcr}, PAR{par}
{
    srand(time(NULL));
    population.resize(HMS);
    fitness.resize(n);
}

void harmonySearch::UpdatePopulation(int func_num, int idx, const solution& new_sol)
{
    population[idx] = new_sol;
    update_fitness(idx,evaluate_solution(func_num,new_sol));
}

int harmonySearch::FindBestSolution()
{
     int bestSolution = 0 ;
     for(unsigned i = 1; i< fitness.size(); ++i)
     {
         if(fitness[bestSolution] < fitness[i])
            bestSolution = i;
     }
    return bestSolution;
}

void harmonySearch::evaluate_pop(int func_num)
{
    for(unsigned i = 0; i < fitness.size(); ++i)
        fitness[i] = evaluate_solution(func_num, population[i]);

    best = FindBestSolution();
}

double harmonySearch::evaluate_solution(int func_num, const solution& sol)
{
    double rtrn = 0;
    switch(func_num)
    {
        case 1:
            {
                rtrn = shifted_Sphere_func(sol);
                break;
            }

        case 2:
            {
                rtrn = shifted_Rastrigin_func(sol);
                break;
            }

        case 3:
            {
                rtrn = shifted_Griewank_func(sol);
                break;
            }

        case 4:
            {
                rtrn = shifted_Rosenbrock_func(sol);
                break;
            }
        default:
            {
                cerr << "ERROR: evaluate_solution: func_num is not defined" << endl;
                break;
            }

    }
    return rtrn;
}

void harmonySearch::update_fitness(int idx, double fitness_val)
{
    fitness[idx] = fitness_val;
}

double harmonySearch::mute()
{
    return generate_random_double(DNA_range[0], DNA_range[1]);
}

int harmonySearch::FindWorstSolution()
{
    int worst = 0 ;
    for(unsigned i = 1; i< fitness.size(); ++i)
    {
     if(fitness[worst] > fitness[i])
        worst = i;
    }
    return worst ;
}

void harmonySearch::run(int func_num)
{
    population = GenerateRandomPop();
    evaluate_pop(func_num); // marche valeur trop grand

    unsigned i = 0;
    while(i < total_func_evals && !CA)
    {
        cout << "i = " << i << endl;
        solution X = create_new_solution(n);
        for(unsigned j{0}; j < X.size(); ++j)
        {
            if(generate_random_double(0.0, 1.0) < HMCR)
            {
                double val = population[generate_random_int(0, HMS-1)][j];

                if(generate_random_double(0.0, 1.0) < PAR) val = mute();

                X[j] = val;
            }
            else X[j] = generate_random_double(DNA_range[0], DNA_range[1]);
        }

        double fX = evaluate_solution(func_num, X);

        CA = fX < critere;

        int ind_worst = FindWorstSolution();

        if(fX > fitness[ind_worst])
        {
            UpdatePopulation(func_num, ind_worst, X);
        }

        ++i;
    }
    cout << endl;
}

double harmonySearch::solve(int func_num)
{
    cout << "function #" << func_num << endl;
    for(nbIterations = 0; nbIterations < nbIterationsTotales; ++nbIterations)
    {
        cout << "iteration #" << nbIterations+1 << " in progress..." << endl;
        run(func_num);
        cout << endl;
    }

    print_solution(population[best], fitness[best]);

    return fitness[best];
}

