#ifndef _OPTUHA_
#define _OPTUHA_

#include <vector>
#include <time.h>
#include <iostream>
#include <iomanip>

//#include <random>

using namespace std;

typedef vector<double> solution; //Une harmonie

class OptUHA
{
protected:
	size_t								pop_size = 30; // taille de la population
	size_t								dimension = 30 ; // dimension du problème
	size_t								total_func_evals = 2000000; // nombre total d'évaluation 2*10^6
	int                                 best; //l'indice de la meilleure fitness
	int                                 worst; //l'indice de la pire fitness
    vector<double>                      dna_range = {20, 20000}; // l'intervalle de chaque gêne

protected:
	vector<double>						fitness; // toutes les valeurs de la fonction objectif de la population

/*
protected:
	//random engine and distribution
	default_random_engine				dre;
	uniform_real_distribution<double>	urd;
*/

public:

    /** @brief Genere une population au hasard. => a utiliser au debut
     *          A utiliser : GenerateNewSolution()
     * @return vector<solution> : un tableau de solutions, c'est a dire, un tableau contenant toutes les harmonies.
     */
     ///@TODO : [Meriem]
	vector<solution> GenerateRandomPop();

    /** @brief Genere un reel aleatoire. On s'en servira pour generer une frequence au hasard et une probabilite p
     *
     * @param from double
     * @return double : le reel
     *
     */
     ///@TODO : [Mathis]
    double generate_random_double(double from, double to);

    /** @brief
     *
     * @param from int
     * @param to int
     * @return int
     *
     */
     ///@TODO : [Mathis]
    int generate_random_int(int from, int to);

    /** @brief Cree un nouvel individu vide, c'est a dire une solution vide. Cela correspond a notre X de depart.
     * @param n : la taille de l'harmonie
     * @return solution : notre nouvelle solution vide (a ajouter ou non a la population selon son evaluation)
     *
     */
     ///@TODO : [Manu]
	solution create_new_solution(unsigned n);

    /** @brief Imprime une solution
     *
     * @param sol solution*
     * @param fitness double
     * @return void
     *
     */
     ///@TODO : [Alexandre]
	void print_solution(const solution& sol, double fitness);

    /** @brief Genere une nouvelle solution
     *          A utiliser : generate_random_double()
     * @param current_ind_idx int
     * @return solution
     *
     */
     ///@TODO : [Manu]
	solution GenerateNewSolution();

	///@TODO : [Alexandre] constructeur
	OptUHA();

	~OptUHA() = default;
};

#endif // _OPTUHA_
