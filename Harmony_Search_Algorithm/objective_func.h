#ifndef OBJECTIVE_FUNC_H_INCLUDED
#define OBJECTIVE_FUNC_H_INCLUDED

#include "myAlgorithm.h"

double shifted_Sphere_func      (const solution& x);
double shifted_Rastrigin_func   (const solution& x);
double shifted_Griewank_func    (const solution& x);
double shifted_Rosenbrock_func  (const solution& x);

#endif // OBJECTIVE_FUNC_H_INCLUDED
