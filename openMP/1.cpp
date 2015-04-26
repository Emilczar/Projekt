#include <cstdio>
#include <time.h>
#include <omp.h>
#include <windows.h>

int blok = 50;

void rownolegle(int ilosc) 
{
		int  tab[10000];
		int licznik = 0;
		bool p;
		int i;
	
#pragma omp parallel for  shared(tab) private(i )
		for (i = 1; i < ilosc; i++)
		{
			p = true;

			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
					p = false;
				//goto nextIteration;

			}
		//nextIteration:
			if (p == true)


//#pragma omp critical
				//printf("%d w: %d\n", i, omp_get_thread_num());
			tab[licznik++] = i;

		}

		

		
	
}	
void rownolegle_w2(int ilosc)
{
	int  tab[10000];
	int licznik = 0;
	bool p;
	int i;
	omp_set_num_threads(2);
#pragma omp parallel for shared(tab)
	for (i = 1; i < ilosc; i++)
	{
		p = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				p = false;
			//goto nextIteration;

		}
	//nextIteration:
		if (p == true)


#pragma omp critical
			//printf("%d w: %d\n", i, omp_get_thread_num());
			tab[licznik++] = i;

	}





}
void rownolegle_schedule(int ilosc)
{
	int  tab[10000];
	int licznik = 0;
	bool p;
	int i;

#pragma omp parallel for  shared(tab) schedule(static , blok)
	for (i = 1; i < ilosc; i++)
	{
		p = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				p = false;
			//goto nextIteration;

		}
	//nextIteration:
		if (p == true)


#pragma omp critical
			//printf("%d w: %d\n", i, omp_get_thread_num());
			tab[licznik++] = i;

	}





}
void rownolegle_schedule_d(int ilosc)
{

	int  tab[10000];
	int licznik = 0;
	bool p;
	int i;

#pragma omp parallel for  shared(tab) schedule(dynamic , blok)
	for (i = 1; i < ilosc; i++)
	{
		p = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				p = false;
			//goto nextIteration;

		}
	//nextIteration:
		if (p == true)


#pragma omp critical
			//printf("%d w: %d\n", i, omp_get_thread_num());
			tab[licznik++] = i;

	}





}
void rownolegle_schedule_prock2(int ilosc)
{
	HANDLE thread_uchwyt = GetCurrentThread();
	int  tab[10000];
	int licznik = 0;
	bool p;
	int i;

	int th_id = omp_get_thread_num();
	DWORD_PTR mask = (1 << (th_id % 2));
	DWORD_PTR result = SetThreadAffinityMask(thread_uchwyt, mask);
	if (result == 0) printf("blad SetThreadAffnityMask \n");
	
#pragma omp parallel for  shared(tab) schedule(static , blok)
	for (i = 1; i < ilosc; i++)
	{
		p = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				p = false;
			//goto nextIteration;

		}
	//nextIteration:
		if (p == true)


#pragma omp critical
			//printf("%d w: %d\n", i, omp_get_thread_num());
			tab[licznik++] = i;

	}





}
void rownolegle_schedule_prock2_d(int ilosc)
{
	HANDLE thread_uchwyt = GetCurrentThread();
	int  tab[10000];
	int licznik = 0;
	bool p;
	int i;

	int th_id = omp_get_thread_num();
	DWORD_PTR mask = (1 << (th_id % 2));
	DWORD_PTR result = SetThreadAffinityMask(thread_uchwyt, mask);
	if (result == 0) printf("blad SetThreadAffnityMask \n");

#pragma omp parallel for  shared(tab) schedule(dynamic , blok)
	for (i = 1; i < ilosc; i++)
	{
		p = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				p = false;
			//goto nextIteration;

		}
		//nextIteration:
		if (p == true)


#pragma omp critical
			//printf("%d w: %d\n", i, omp_get_thread_num());
			tab[licznik++] = i;

	}





}
void rownolegle_pr2(int ilosc)
{
	HANDLE thread_uchwyt = GetCurrentThread();
	int  tab[10000];
	int licznik = 0;
	bool p;
	int i;

	int th_id = omp_get_thread_num();
	DWORD_PTR mask = (1 << (th_id % 2));
	DWORD_PTR result = SetThreadAffinityMask(thread_uchwyt, mask);
	if (result == 0) printf("blad SetThreadAffnityMask \n");

#pragma omp parallel for
	for (i = 1; i < ilosc; i++)
	{
		p = true;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
				p = false;
			//goto nextIteration;

		}
	//nextIteration:
		if (p == true)


#pragma omp critical
			//printf("%d w: %d\n", i, omp_get_thread_num());
			tab[licznik++] = i;

	}





}
int main()
{
	
	int ilosc = 10000;

	clock_t start, stop;
	


	

	start = clock();
	rownolegle(ilosc);
	stop = clock();
	printf("Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_w2(ilosc);
	stop = clock();
	printf(" 2 w Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_schedule(ilosc);
	stop = clock();
	printf("s, 10 Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_schedule_d(ilosc);
	stop = clock();
	printf("d 10 Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_schedule_prock2(ilosc);
	stop = clock();
	printf("s 10 2 prock Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));
	start = clock();
	rownolegle_schedule_prock2_d(ilosc);
	stop = clock();
	printf("d 10 2 prock Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));

	start = clock();
	rownolegle_pr2(ilosc);
	stop = clock();
	printf("2 prock Czas przetwarzania wynosi %f sekund\n", ((double)(stop - start) / 1000.0));
	
}