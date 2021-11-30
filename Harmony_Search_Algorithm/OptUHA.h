#pragma once
#ifndef _OPTUHA_
#define _OPTUHA_
#include <vector>
#include <random>
#include "iostream"
using namespace std;

typedef vector<double> solution; //Une harmonie


class OptUHA
{
protected:
    //Est-ce qu'on laisse laisse les donnees telles quelles ou on les met dans le constructeur
	size_t								pop_size = 30; // taille de la population
	size_t								dimension = 30 ; // dimension du problème
	size_t								total_func_evals = 2000000; // nombre total d'évaluation
	size_t								max_func_eval = total_func_evals * pop_size; // nombre total d'appel de la fonction objectif
	bool								optimization_mode = 0; // 0 = min; 1 = max;
	vector<double>						bound_min; // bornes min
	vector<double>						bound_max ; // bornes max
	int                                 best; //l'indice de la meilleure fitness

protected:
	vector<double>						fitness; // toutes les valeurs de la fonction objectif de la population

protected:
	//random engine and distribution
	default_random_engine				dre;
	uniform_real_distribution<double>	urd;

protected :

    /** @brief Genere une population au hasard. => a utiliser au debut
     *          A utiliser : GenerateNewSolution()
     * @return vector<solution> : un tableau de solutions, c'est a dire, un tableau contenant toutes les harmonies.
     */
	vector<solution> GenerateRandomPop();

    /** @brief Genere un reel aleatoire. On s'en servira pour generer une frequence au hasard et une probabilite p
     *
     * @param from double
     * @return double : le reel
     *
     */
	double generate_random_double(double from, double to);

    /** @brief
     *
     * @param from int
     * @param to int
     * @return int
     *
     */
	int generate_random_int(int from, int to);

    /** @brief Cree un nouvel individu vide, c'est a dire une solution vide. Cela correspond a notre X de depart.
     * @param n : la taille de l'harmonie
     * @return solution : notre nouvelle solution vide (a ajouter ou non a la population selon son evaluation)
     *
     */
	solution create_new_solution(int n);

    /** @brief Imprime une solution
     *
     * @param sol solution*
     * @param fitness double
     * @return void
     *
     */
	void print_solution(solution* sol, double fitness);

    /** @brief Genere une nouvelle solution
     *          A utiliser : generate_random_double()
     * @param current_ind_idx int
     * @return solution
     *
     */
	solution GenerateNewSolution(int current_ind_idx);

    /** @brief Gere l'ajout ou non d'une nouvelle harmonie (ETAPE 3)
     *
     * @param population vector<solution>&
     * @return void
     *
     */
	void check_bound_pop(vector<solution>& population);

	OptUHA() = default;
	~OptUHA() = default;
};

#endif
