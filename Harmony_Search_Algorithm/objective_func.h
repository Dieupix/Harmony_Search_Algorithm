#ifndef OBJECTIVE_FUNC_H_INCLUDED
#define OBJECTIVE_FUNC_H_INCLUDED
#include "myAlgorithm.h"
#include "OptUHA.h"
///@TODO : [Meriem] fonction Shifted Sphere (voir la formule)
///@TODO : [Manu] fonction Shifted Rosenbrock (voir la formule)
///@TODO : [Mathis] fonction Shifted Rastrigin (voir la formule)
///@TODO : [Alexandre] fonction Shifted Griewank (voir la formule)


double schifed_Sphere_func(const solution x) ;
double shifted_Griewank_func(double x);

#endif // OBJECTIVE_FUNC_H_INCLUDED
