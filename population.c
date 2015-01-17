#include "allinc.h"

using namespace std;


float alpha (Population population1)
{
	return 0;
}

void sort (Population &population1)
{
int swapped=false;
int sc=0;
	do
	{
	swapped=false;


		for (int i=0; i<POPULATION_SIZE; i++)
		{
			if (fitness(population1.Population[i]) < fitness(population1.Population[i+1]))
			{
				Individual temp = population1.Population[i];
				population1.Population[i]=population1.Population[i+1];
				population1.Population[i+1]=temp;
				swapped=true;
				break;
			}
		}
	
	sc++;
	} while (sc<SORTING_LIMIT);
	cout << endl;

}

void printPop(Population population1)
{
	for (int i=0; i<POPULATION_SIZE; i++)
		cout << "Individual " << i << "/" << POPULATION_SIZE << ", F=" << fitness(population1.Population[i]) << endl;
	cout << endl;
}

void printPopD(Population population1)
{
	for (int i=0; i<POPULATION_SIZE; i++)
	{
		printInd(population1.Population[i]);
		cout << endl << i << "/" << POPULATION_SIZE << ", F=" << fitness(population1.Population[i]) << endl;
	}
	cout << endl;
}

void printInd(Individual ind)
{
	for ( int i = 0; i < SUM_UPPER_BOUND; i++ )
	{
		cout << ind.genes[i] << ",";
	}
}


Individual getMax(Population population1)
{
	Individual max = population1.Population[0];
	for (int i=1; i<POPULATION_SIZE; i++)
	{
		//cout << "maxing..." << endl;
		if (fitness(population1.Population[i]) > fitness(max))  max = population1.Population[i];
	}

	return max;
}

Individual getMax(Population population1, float size)
{
	Individual max = population1.Population[0];
	for (int i=1; i<size; i++)
	{
		if (fitness(population1.Population[i]) > fitness(max))  max = population1.Population[i];
	}

	return max;
}

Individual getMax(Individual a[], float size)
{
	Individual max = a[0];
	for (int i=1; i<size; i++)
	{
		if (fitness(a[i]) > fitness(max))  max = a[i];
	}

	return max;
}
