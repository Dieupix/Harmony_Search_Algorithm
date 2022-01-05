#include "OptUHA.h"

vector<solution> OptUHA::GenerateRandomPop()
{
<<<<<<< HEAD

    vector<solution> population (pop_size);

=======
    vector<solution> population(pop_size);
>>>>>>> 95f51123dbe981c374637c8337e8c14e03ccfb10
    for( int i = 0 ; i < pop_size; i++)
    {
        population[i] = GenerateNewSolution();
    }
<<<<<<< HEAD


     return population ;
=======
    return population;
>>>>>>> 95f51123dbe981c374637c8337e8c14e03ccfb10
}

double OptUHA::generate_random_double(double from, double to)
{
  return from + (double)rand() / (double)(RAND_MAX / (to - from));


}

int OptUHA::generate_random_int(int from, int to)
{
    int nRand;
    nRand = rand() % (to - from + 1) + from;
    return nRand;
}

solution OptUHA::create_new_solution(int n)
{

    return solution{n};
}

void OptUHA::print_solution(const solution& sol, double fitness)
{
    for(auto s : sol)
    {
        cout << "- " << s << endl;
    }
    cout << "FITNESS: " << fitness << endl;
}

solution OptUHA::GenerateNewSolution()
{
    solution ns;
    ns.resize(pop_size) ;

    for(int i{0} ; i<ns.size() ; ++i)
        {

           ns[i] = generate_random_double(-100.0,100.0);


        }

    return ns;
}

void OptUHA::check_bound_pop(vector<solution>& population)
{

}






