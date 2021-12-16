#include "OptUHA.h"


vector<solution> OptUHA::GenerateRandomPop()
{
    vector<solution> population {size_t};

    for( int i = 0 ; i <size_t; i++)
    {

        population[i].GenerateNewSolution() ;
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
