#include <cstdio>
#include <time.h>
#include <omp.h>

int main()
{
	clock_t start, stop;
	int n = 10000;
	int  tab[10000];
	int licznik = 0;
	bool p;
	int i ;
	    
	start = clock();
#pragma omp parallel for
		for (i = 1; i < n ; i++)
		{
		p = true;

		for (int j = 2; j < i; j++)
		{	
		if (i % j == 0)
				p = false;
		}
			if (p == true)

				
			#pragma omp critical
			//printf("%d w: %d\n", i, omp_get_thread_num());
			tab[licznik++] = i;

		}
	
	stop = clock();
	printf("Czas przetwarzania wynosi %f sekund\n",((double)(stop - start)/1000.0));
}