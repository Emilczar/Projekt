
#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include <omp.h>

void licz()
{
	char wzorzec[] = "abc";
	char tekst[] =  "abcabcabc" ;
	int m, n, i, j, ilosc;
	ilosc = 0;
	n = strlen(tekst);
	m = strlen(wzorzec);
	
	i = 0;
	while (i <= n - m)
	{
		j = 0;
		while ((j<m) && (wzorzec[j] == tekst[i + j])) j++;
		if (j == m) ilosc = ilosc + 1;
		
		i++;
	}
	printf("wystapienie klucza: %d \n", ilosc);

}

int main(void)
{
	clock_t start, koniec, start1, koniec1;	start = clock();
	licz();

	koniec = clock();
	long delta = (long)(koniec - start);
	printf("Czas wykonywania obliczen : %d ms \n", koniec);

	start1 = clock();
#pragma omp parallel sections
	{
#pragma omp section
		{
			licz();
			licz();
			licz();
			licz();
			printf("policzone %d.\n", omp_get_thread_num());
		}

#pragma omp section
		{
		licz();
		licz();
		licz();
		licz();
			printf("policzone %d.\n", omp_get_thread_num());
	}
#pragma omp section
		{
			licz();
			licz();
			licz();
			licz();
			printf("policzone %d.\n", omp_get_thread_num());
	}
#pragma omp section
		{
			licz();
			licz();
			licz();
			licz();
			printf("policzone %d.\n", omp_get_thread_num());
		}
		#pragma omp section
		{
			licz();
			licz();
			licz();
			licz();
			printf("policzone %d.\n", omp_get_thread_num());
		}

	}
	koniec1 = clock();
	long delta1 = (long)(koniec1 - start1);
	printf("Czas wykonywania obliczen: %d ms ", delta1);
	
	getchar();
}