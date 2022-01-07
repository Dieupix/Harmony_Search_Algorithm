#include "OptUHA.h"

OptUHA::OptUHA() : best{0}
{}

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
  return from + (double)rand() / (double)(RAND_MAX / (to - from));
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
    for(unsigned i = 0; i < sol.size(); ++i)
    {
        cout << sol[i] << endl;
    }
    cout << "FITNESS: " << fit << endl;
}

solution OptUHA::GenerateNewSolution()
{
    solution ns;
    ns.resize(pop_size) ;

    for(unsigned i{0}; i<ns.size(); ++i)
    {
       ns[i] = generate_random_double(DNA_range[0], DNA_range[1]);
    }

    return ns;
}

void OptUHA::check_bound_pop(vector<solution>& population)
{

}






