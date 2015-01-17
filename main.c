#include "allinc.h"
using namespace std;

int main()
{
	srand(time(NULL));
	struct Population population1;
	for (int n=0; n<POPULATION_SIZE; n++)
	{
		Individual indi;
		cout << n << " - ";

		for ( int i = 0; i < SUM_UPPER_BOUND; i++ )
		{
			indi.genes[i] = rand()%SUM_UPPER_BOUND + 1;
			cout << indi.genes[i] << " ";
		}
		
		population1.Population[n]=indi;
		cout << " F= " << fitness(indi) << endl;
		cout << endl;
	}


  sort(population1);
	cout << "\nMax fitness=" << fitness(getMax(population1)) << endl;
	printPopD(population1);

	evolve(population1);

	return 1;
}
