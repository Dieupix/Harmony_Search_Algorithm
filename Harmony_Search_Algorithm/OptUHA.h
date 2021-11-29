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
	size_t								pop_size = 30; // taille de la population
	size_t								dimension = 30 ; // dimension du problème
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
	vector<solution> GenerateRandomPop();
	double generate_random_double();
	int generate_random_int(int from, int to);
	solution create_new_solution();
	void print_solution(double* indv, double fitness);
	solution GenerateNewSolution(int current_ind_idx);
	void check_bound_pop(vector<solution>& population);

	OptUHA();
	~OptUHA();
};

#endif
