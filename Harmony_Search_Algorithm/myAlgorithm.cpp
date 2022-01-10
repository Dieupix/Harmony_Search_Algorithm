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
    population.resize(HMS);
    fitness.resize(n);
}

void harmonySearch::UpdatePopulation(int idx, const solution& new_sol, double fX)
{
    population[idx] = new_sol;
    update_fitness(idx, fX);
}

int harmonySearch::FindBestSolution()
{
     int bestSolution = 0 ;
     for(unsigned i = 1; i < fitness.size(); ++i)
     {
        if(fitness[bestSolution] > fitness[i])
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
    return generate_random_double(dna_range[0], dna_range[1]);
}

int harmonySearch::FindWorstSolution()
{
    int worst = 0 ;
    for(unsigned i = 1; i< fitness.size(); ++i)
    {
        if(fitness[worst] < fitness[i])
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
        solution X = create_new_solution(n);
        for(unsigned j{0}; j < X.size(); ++j)
        {
            if(generate_random_double(0.0, 1.0) < HMCR)
            {
                double val = population[generate_random_int(0, HMS-1)][j];

                if(generate_random_double(0.0, 1.0) < PAR)
                    val = mute();

                X[j] = val;
            }
            else X[j] = generate_random_double(dna_range[0], dna_range[1]);
        }

        double fX = evaluate_solution(func_num, X);

        CA = fX < critere;

        int ind_worst = FindWorstSolution();

        if(fX < fitness[ind_worst])
        {
            UpdatePopulation(ind_worst, X, fX);
        }

        ++i;
    }
    save(func_num);
}

void harmonySearch::solve(int func_num)
{
    cout << "function #" << func_num << endl;
    for(nbIterations = 0; nbIterations < nbIterationsTotales; ++nbIterations)
    {
        cout << "iteration #" << nbIterations+1 << " in progress..." << endl;
        run(func_num);
        cout << "iteration done." << endl;
    }
}

void harmonySearch::save(int func_num) const
{
    string fileName = "../outputs/";
    string extension = "2.txt";
    switch(func_num)
    {
        case 1:
            {
                fileName += "shifted_Sphere_func";
                break;
            }

        case 2:
            {
                fileName += "shifted_Rastrigin_func";
                break;
            }

        case 3:
            {
                fileName += "shifted_Griewank_func";
                break;
            }

        case 4:
            {
                fileName += "shifted_Rosenbrock_func";
                break;
            }
        default:
            {
                cerr << "ERROR: save: func_num is not defined" << endl;
                fileName += "errorSAVE";
                break;
            }
    }

    fileName += extension;

    saveIn(fileName);
}

void harmonySearch::saveIn(const string& fileName) const
{
    ofstream ofs(fileName, nbIterations == 0 ? ios::out : ios::app);

    if(!ofs)
    {
        cerr << "ERROR: saveIn: cannot open file " << fileName << endl;
    }
    else
    {
        string toSave = to_string(fitness[best]);

        ofs << nbIterations+1 << " : " << toSave << endl;
    }
}

