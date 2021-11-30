#pragma once
#ifndef _OPTUHA_
#define _OPTUHA_
#include <vector>
#include <random>
#include "iostream"
using namespace std;

typedef double indType;
typedef indType* solution;

class OptUHA
{
protected:
	size_t								pop_size = 10; // taille de la population
	size_t								dimension = 2; // dimension du problème
	size_t								total_func_evals = 2500; // nombre total d'évaluation
	size_t								max_func_eval = total_func_evals * pop_size; // nombre total d'appel de la fonction objectif
	bool								optimization_mode = 0; // 0 = min; 1 = max;
	vector<double>						bound_min; // bornes min
	vector<double>						bound_max ; // bornes max

protected:
	vector<double>						fitness;

protected:
	//random engine and distribution
	default_random_engine				dre;
	uniform_real_distribution<double>	urd;

protected :

    /** @brief Genere une population au hasard
     *
     * @return vector<solution> : un tableau de solutions, c'est a dire, un tableau contenant toutes les harmonies.
     */
	vector<solution> GenerateRandomPop();

    /** @brief Genere un reel aleatoire. On s'en servira pour generer une frequence au hasard et une probabilite p
     *
     * @return double : le reel
     *
     */
	double generate_random_double();

    /** @brief
     *
     * @param from int
     * @param to int
     * @return int
     *
     */
	int generate_random_int(int from, int to);

    /** @brief Cree un nouvel individu, c'est a dire une solution. Cela correspond a notre X
     *
     * @return solution : notre nouvelle solution (a ajouter ou non a la population selon son evaluation)
     *
     */
	solution create_new_solution();

    /** @brief Imprime
     *
     * @param indv double*
     * @param fitness double
     * @return void
     *
     */
	void print_solution(double* indv, double fitness);

    /** @brief
     *
     * @param current_ind_idx int
     * @return solution
     *
     */
	solution GenerateNewSolution(int current_ind_idx);

    /** @brief
     *
     * @param population vector<solution>&
     * @return void
     *
     */
	void check_bound_pop(vector<solution>& population);

	OptUHA();
	~OptUHA();
};

#endif
