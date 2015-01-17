#include "allinc.h"

using namespace std;

void mutate (Individual &indi, int mutPoints)
{
	for (int n=0; n<mutPoints; n++)
	{
		if ((rand() % 2)==1)
		{
			int cur = rand()%(SUM_UPPER_BOUND + 1);
			if (cur<5 && indi.genes[cur]<10) indi.genes[cur]++;
			else if (cur>=5 && indi.genes[cur]<10 && indi.genes[cur]!=1) indi.genes[cur]--;
		}
	}
}

void mutatePop(struct Population &population1)
{
	for (int i=0; i<=POPULATION_SIZE; i++)
	{
		mutate(population1.Population[i], MUTATE_POINTS);
	}
}

float fitness (Individual c)
{
	float nom=1, den = 1;
	for (int n=0; n<SUM_UPPER_BOUND/2; n++)
	{
		nom=nom*c.genes[n];
		den=den*c.genes[n+SUM_UPPER_BOUND/2];

	}
	return nom/den;

}

Individual crossover(Individual a, Individual b)
{
	Individual c;
	for (int i=0; i<5; i++) c.genes[i]=a.genes[i];
	for (int i=5; i<SUM_UPPER_BOUND; i++) c.genes[i]=b.genes[i];

	return c;
}

int gens=0;
void evolve (Population &population1)
{
	Individual parents[POPULATION_SIZE/2];
	Individual offspring[POPULATION_SIZE/2];
	cout << "Starting evolution..." << endl;

	do
	{
		mutatePop(population1);
		//sort (population1);
		printInd(population1.Population[0]);
		cout << "   GEN: " << gens << ", f()=" << fitness(getMax(population1)) << endl;

		for (int i=0; i<POPULATION_SIZE/2; i++)
		{
			parents[i]=population1.Population[i];
		}

		for (int k=0; k<POPULATION_SIZE/2-1; k++)
		{
			offspring[k]=crossover(parents[k], parents[k+1]);
		}

		//sort (population1);
		int insc=0;
		for (int l=0; l<POPULATION_SIZE/2-1; l++)
		{
			if (fitness(offspring[l]) > fitness(population1.Population[0]))
			{
				population1.Population[POPULATION_SIZE-insc]=offspring[l];
				insc++;
			}
		}

	gens++;
	} while (fitness(getMax(population1)) < 100000);
	cout << "          ============RESULT============" <<endl;
	printInd(getMax(population1));
	cout << "   GEN: " << gens << ", f()=" << fitness(getMax(population1)) << endl;
}
