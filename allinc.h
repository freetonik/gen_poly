#ifndef ALLINC
#define ALLINC

#include <stdio.h>
#include <time.h>
#include <cstdlib>
#include <iostream>

#define SUM_UPPER_BOUND 10
#define POPULATION_SIZE 22
#define GENERATIONS 10
#define MUTATE_POINTS 1
#define TOURNAMENT_SIZE 8
#define EPSILON 0.005
#define SORTING_LIMIT 100

struct Individual
{
	int genes[SUM_UPPER_BOUND];
	int size;
};

struct Population
{
	//array of individuals
	Individual Population[POPULATION_SIZE];
};


float alpha(Population population1);
void sort(Population &population1);
void printPop(Population population1);
void printPopD(Population population1);
void printInd(Individual ind);
float fitness (Individual);
Individual getMax(Population population1);
Individual getMax(Population population1, float size);
Individual getMax(Individual a[], float size);
void mutatePop(struct Population &population1);
void evolve (Population &population1);

#endif //ALLINC
