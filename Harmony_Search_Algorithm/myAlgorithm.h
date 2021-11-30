#pragma once
#ifndef _MYALGO_OPT_
#define _MYALGO_OPT_
#include "OptUHA.h"
#include "objective_func.h"

class harmonySearch : OptUHA
{
protected:
    int HMS = pop_size; //nombre d'harmonies de la population
    int n = dimension; //nombre de frequences dans une harmonie
    double HMCR; //taux de consideration de l'harmonie
    bool CA = false; //critère d'arret f(x) < 10^-16
    double PAR; //taux de réglage de la hauteur, la probabilite de modifier la frequence selectionnee
    int nbIterations = 0; //nombre d'iterations deja effectuees
	vector<solution>					population;


protected:
	void UpdatePopulation(int func_num, int idx, solution new_sol); //met a jour la population (ajoute X a la place de la pire solution (idx)) => fonction Remplace()
	solution FindBestSolution(int func_num, double &fitness); //cherche la meilleure valeur du tableau fitness
	void evaluate_pop(int func_num); //evalue la population par rapport a la fonction
	double evaluate_solution(int func_num, solution sol); //evalue une harmonie par rapport a la fonction
	void update_fitness(int idx, double fitness_val); //met a jour le tableau fitness
    double mute(double f); //mute f


    //Ce qu'on a ajoute
    int FindWorstSolution(); //cherche la pire solution dans fitness (a utiliser : UpdatePopulation())

public:
	double solve(int func_num); //renvoie la meilleure valeur trouvee par l'algo par rapport a la fonction
	harmonySearch(double hmcr, double par);
	~harmonySearch() = default;

};

#endif
