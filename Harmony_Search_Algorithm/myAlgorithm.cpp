#include "myAlgorithm.h"
#include "OptUHA.h"

harmonySearch::harmonySearch(double hmcr, double par) : HMCR{hmcr}, PAR{par}
{
    population.resize(HMS);
}


void harmonySearch::UpdatePopulation(int func_num, int idx, solution new_sol)
{
    population[idx] = new_sol;
    update_fitness(idx,evaluate_solution(func_num,new_sol));
}

int harmonySearch::FindBestSolution()
{
     int bestSolution = 0 ;
     for( int i = 1 ; i< fitness.size(); i++ )
     {
         if( fitness[bestSolution] < fitness[i])
            bestSolution = i;
     }
    return bestSolution ;
}

vector<double> harmonySearch::evaluate_pop(int func_num)
{
    fitness.resize(pop_size) ;

    for(int i = 0; i < fitness.size(); i++)
            fitness[i] = evaluate_solution(func_num, population[i]);

 return fitness ;
}

double harmonySearch::evaluate_solution(int func_num, const solution& sol)
{
    switch(func_num)
    {
        case 1:
            {
                return shifted_Sphere_func(sol);
                break;
            }

        case 2:
            {
                return shifted_Rastrigin_func(sol);
                break;
            }

        case 3:
            {
               return shifted_Griewank_func(sol);
               break;
            }

        case 4:
            {
              return shifted_Rosenbrock_func(sol);
              break;
            }
    }
}

void harmonySearch::update_fitness(int idx, double fitness_val)
{
    fitness[idx] = fitness_val;
}
double harmonySearch::mute()
{
    return generate_random_double(20.0,20000.0);
}
 int harmonySearch::FindWorstSolution()
 {
     int worst = 0 ;
     for( int i = 1 ; i< fitness.size(); i++ )
     {
         if( fitness[worst] > fitness[i])
            worst = i;
     }
    return worst ;
 }
<<<<<<< HEAD


=======
void affiche(vector<double> s)
{
    for(int i = 0 ; i < s.size() ; i++)
        cout <<s[i]<<" " ;
}
>>>>>>> 95f51123dbe981c374637c8337e8c14e03ccfb10
void harmonySearch::run(int func_num)
{


    population = GenerateRandomPop();
<<<<<<< HEAD
     fitness = evaluate_pop(func_num); // marche valeur trop grand


=======
    //affiche(population[0]);
    evaluate_pop(func_num);
    //affiche(fitness);
>>>>>>> 95f51123dbe981c374637c8337e8c14e03ccfb10
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
                        val = mute();
                    }
                    X[j] = val;
                }
                else X[j] = generate_random_double(-100.0,100.0);
            }
        double fX = evaluate_solution(func_num,X);

        CA = fX < critere;
        int ind_worst = FindWorstSolution();
        if(fX > fitness[ind_worst])
        {
            UpdatePopulation(func_num,ind_worst,X);
        }
        ++nbIterations;

    }


}



double harmonySearch::solve(int func_num)
{
<<<<<<< HEAD

    solution sol(dimension);
    for(unsigned i = 0; i < nbIterationsTotales; ++i)
    {

=======
    for(unsigned i = 0; i < nbIterationsTotales; ++i)
    {
        cout<<"avant";
>>>>>>> 95f51123dbe981c374637c8337e8c14e03ccfb10
        run(func_num);
        cout<<"done";
        print_solution(population[best], fitness[best]);
    }
    return fitness[best];
}


void affiche_population(vector<solution> population)
{
    for( int i = 0 ; i< population.size(); i++)
     {
         for( int j = 0 ; j< population.size(); j++)
       {
        cout <<population[i][j] <<endl ;
        }

     }
}
