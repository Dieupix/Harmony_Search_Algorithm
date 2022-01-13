#include "myAlgorithm.h"

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
    fitness.resize(HMS);
}

void harmonySearch::UpdatePopulation(int idx, const solution& new_sol, double fX)
{
    population[idx] = new_sol;
    update_fitness(idx, fX);

    best = FindBestSolution();
    worst = FindWorstSolution();
}

int harmonySearch::FindBestSolution()
{
    int bestSolution = 0;
    for(unsigned i = 1; i < fitness.size(); ++i)
    {
        if(fitness[bestSolution] > fitness[i])
            bestSolution = i;
    }
    return bestSolution;
}

int harmonySearch::FindWorstSolution()
{
    int worstSolution = 0;
    for(unsigned i = 1; i < fitness.size(); ++i)
    {
        if(fitness[worstSolution] < fitness[i])
            worstSolution = i;
    }
    return worstSolution;
}

void harmonySearch::evaluate_pop(int func_num)
{
    for(unsigned i = 0; i < fitness.size(); ++i)
    {
        fitness[i] = evaluate_solution(func_num, population[i]);
    }

    best = FindBestSolution();
    worst = FindWorstSolution();
}

double harmonySearch::evaluate_solution(int func_num, const solution& sol)
{
    double rtrn = 0;
    double f_bias = 0;
    switch(func_num)
    {
        case 1:
            f_bias = -450;
            rtrn = shifted_Sphere_func(sol) + f_bias;
            break;
        case 2:
            f_bias = -330;
            rtrn = shifted_Rastrigin_func(sol) + f_bias;
            break;
        case 3:
            f_bias = -180;
            rtrn = shifted_Griewank_func(sol) + f_bias;
            break;
        case 4:
            f_bias = 390;
            rtrn = shifted_Rosenbrock_func(sol) + f_bias;
            break;
        default:
            cerr << "ERROR: evaluate_solution: func_num is not defined" << endl;
            break;
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

void harmonySearch::run(int func_num)
{
    population = GenerateRandomPop();
    evaluate_pop(func_num);

    CA = false;
    unsigned i = 0;
    while(i < total_func_evals && !CA)
    {
        solution X = create_new_solution(n);
        for(unsigned j = 0; j < X.size(); ++j)
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

        if(CA) cout << "CA atteint!" << endl;

        if(fX < fitness[worst])
        {
            UpdatePopulation(worst, X, fX);
        }

        ++i;
    }

    save(func_num);
}

void harmonySearch::solve(int func_num)
{
    cout << "function #" << func_num << endl;

    changeDNARange(func_num);

    for(nbIterations = 0; nbIterations < nbIterationsTotales; ++nbIterations)
    {
        cout << "iteration #" << nbIterations+1 << " in progress..." << endl;
        run(func_num);
        cout << "iteration done." << endl;
    }
}

void harmonySearch::changeDNARange(int func_num)
{
    switch(func_num)
    {
        case 1: // shifted_Sphere_func
            dna_range[0] = -100;
            dna_range[1] = 100;
            break;
        case 2: // shifted_Rastrigin_func
            dna_range[0] = -5;
            dna_range[1] = 5;
            break;
        case 3: // shifted_Griewank_func
            dna_range[0] = -600;
            dna_range[1] = 600;
            break;
        case 4: // shifted_Rosenbrock_func
            dna_range[0] = -100;
            dna_range[1] = 100;
            break;
        default:
            dna_range[0] = 1;
            dna_range[1] = 1;
            cerr << "ERROR: changeDNARange: func_num is not defined" << endl;
            break;
    }
}

void harmonySearch::save(int func_num) const
{
    string fileName = "../outputs/";
    string extension = ".txt";
    switch(func_num)
    {
        case 1:
            fileName += "shifted_Sphere_func";
            break;
        case 2:
            fileName += "shifted_Rastrigin_func";
            break;
        case 3:
            fileName += "shifted_Griewank_func";
            break;
        case 4:
            fileName += "shifted_Rosenbrock_func";
            break;
        default:
            cerr << "ERROR: save: func_num is not defined" << endl;
            fileName += "errorSAVE";
            break;
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

        ofs << setw(2) << nbIterations+1 << " : " << toSave << endl;
    }
}

double harmonySearch::shifted_Sphere_func(const solution& x)
{
    double res = 0 ;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i] - 0;
        res += z * z;
    }

    if(res < critere)
    {
        res = 0;
        CA = true;
    }

    return res;
}

double harmonySearch::shifted_Rastrigin_func(const solution& x)
{
    double res = 0;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i] - 0;
        res += (z * z) - 10 * cos(2 * M_PI * z) + 10;
    }

    if(res < critere)
    {
        res = 0;
        CA = true;
    }

    return res;
}

double harmonySearch::shifted_Griewank_func(const solution& x)
{
    double sum = 0;
    double product = 1;
    double z = 0;

    for(unsigned i = 0; i < x.size(); ++i)
    {
        z = x[i] - 0;
        sum += (z * z) / 4000;
        product *= cos(z / sqrt(i+1));
    }

    double res = sum - product + 1;

    if(res < critere)
    {
        res = 0;
        CA = true;
    }

    return res;
}

double harmonySearch::shifted_Rosenbrock_func(const solution& x)
{
    double res = 0;
    double z = 0, z1 = 0;

    for(unsigned i = 0; i < x.size()-1; ++i)
    {
        z = x[i] - 0 + 1;
        z1 = x[i+1] - 0 + 1;

        auto sq = ((z * z) - z1) * ((z * z) - z1);
        auto sq1 = (z-1) * (z-1);

        res += 100 * sq + sq1;
    }

    if(res < critere)
    {
        res = 0;
        CA = true;
    }

    return res;
}
