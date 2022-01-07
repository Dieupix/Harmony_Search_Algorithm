#ifndef _MYALGO_OPT_
#define _MYALGO_OPT_

#include "OptUHA.h"
#include "objective_func.h"

#include <cmath>
#include <fstream>

class harmonySearch : public OptUHA
{
protected:
    int HMS = pop_size; //nombre d'harmonies de la population
    int n = dimension; //nombre de frequences dans une harmonie
    double HMCR; //taux de consideration de l'harmonie
    double critere = pow(10,-16);
    bool CA = false; //critère d'arret f(x) < 10^-16
    double PAR; //taux de réglage de la hauteur, la probabilite de modifier la frequence selectionnee
    unsigned nbIterations = 0; //nombre d'iterations deja effectuees
    unsigned nbIterationsTotales = 30;
	vector<solution> population;

public:
	void UpdatePopulation(int idx, const solution& new_sol, double fX); ///@TODO : [Manu] met a jour la population (ajoute X a la place de la pire solution (idx)) => fonction Remplace()
	int FindBestSolution(); ///@TODO : [Meriem] cherche la meilleure valeur du tableau fitness
	void evaluate_pop(int func_num); ///@TODO : [Mathis] evalue la population par rapport a la fonction
	double evaluate_solution(int func_num, const solution& sol); ///@TODO : [Mathis] evalue une harmonie par rapport a la fonction
	void update_fitness(int idx, double fitness_val); ///@TODO : [Alexandre] met a jour le tableau fitness
    //double mute(double val); ///@TODO : [Manu] mute val
    double mute(); ///@TODO : [Manu] mute

    //Ce qu'on a ajoute
    int FindWorstSolution(); ///@TODO : [Meriem] cherche la pire solution dans fitness (a utiliser : UpdatePopulation())
    void run(int func_num); ///@TODO : [les 4] l'algo en soit

    void save(int) const; ///@TODO : Alex : sauvegarde la meilleure fitness dans un fichier suivant la fonction utilisée
    void saveIn(const string&) const; ///@TODO : Alex : sauvegarde la meilleure fitness dans un fichier

public:
	void solve(int func_num); ///@TODO : [Alexandre] renvoie la meilleure valeur trouvee par l'algo par rapport a la fonction
	harmonySearch(double hmcr, double par);///@TODO : [Alexandre] constructeur
	~harmonySearch() = default;

};

#endif // _MYALGO_OPT_
