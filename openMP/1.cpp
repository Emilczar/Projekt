#include <cstdio>
#include <time.h>
#include <omp.h>

int main()
{
	clock_t start, stop;
	int n =10000;
	bool p;
	int i ;
	
	start = clock();
#pragma omp parallel for
		for (i = 1; i < n ; i++)
		{
		p = true;

		for (int j = 2; j < i; j++)
		if (i % j == 0)
				p = false;
			if (p == true)
				printf("%d\n", i);


		}
	
	stop = clock();
	printf("Czas przetwarzania wynosi %f sekund\n",((double)(stop - start)/1000.0));
}