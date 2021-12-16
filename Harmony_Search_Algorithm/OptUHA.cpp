#include "OptUHA.h"



vector<solution> OptUHA::GenerateRandomPop()
{
    vector<solution> population (pop_size);

    for( int i = 0 ; i < pop_size; i++)
    {

        population[i] = GenerateNewSolution() ;
    }

}


solution OptUHA::create_new_solution(int n)
{
    return solution{n};
}

solution OptUHA::GenerateNewSolution()
{
    solution ns;
    for(int i{0} ; i<ns.size() ; ++i)
        {
            ns[i] = generate_random_double(20.0,20000.0);
        }
    return ns;
}

int OptUHA::generate_random_int(int from, int to)
{
    int nRand;
    nRand = rand() % (to - from + 1) + from;
    return nRand;
}

double OptUHA::generate_random_double(double from, double to)
{
    double nRand ;
    nRand = from + (double)rand() / (double)(RAND_MAX / (to - from));
    return nRand;
}


void OptUHA::print_solution(const solution& sol, double fitness)
{
    for(auto s : sol)
    {
        cout << "- " << s << endl;
    }
    cout << "FITNESS: " << fitness << endl;
}



