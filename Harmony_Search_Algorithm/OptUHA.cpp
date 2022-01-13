#include "OptUHA.h"

OptUHA::OptUHA() : best{0}, worst{0}
{
    srand(time(NULL));
}

vector<solution> OptUHA::GenerateRandomPop()
{
    vector<solution> population(pop_size);
    for(unsigned i = 0; i < pop_size; i++)
    {
        population[i] = GenerateNewSolution();
    }
    return population;
}

double OptUHA::generate_random_double(double from, double to)
{
    return from + static_cast<double>(rand()) / (static_cast<double>(RAND_MAX) / (to - from));
}

int OptUHA::generate_random_int(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

solution OptUHA::create_new_solution(unsigned n)
{
    return solution(n);
}

void OptUHA::print_solution(const solution& sol, double fit)
{
    cout << "SOLUTION:" << endl;
    for(unsigned i = 0; i < sol.size(); ++i)
    {
        cout << "|  " << sol[i] << endl;
    }
    cout << "Fitness: " << fit << endl;
}

solution OptUHA::GenerateNewSolution()
{
    solution ns(pop_size);

    for(unsigned i{0}; i < ns.size(); ++i)
    {
       ns[i] = generate_random_double(dna_range[0], dna_range[1]);
    }

    return ns;
}






