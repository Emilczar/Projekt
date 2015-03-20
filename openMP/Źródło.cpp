
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define CACHE_LINE 64
#define CACHE_ALIGN __declspec(align(CACHE_LINE))
CACHE_ALIGN int i;
CACHE_ALIGN int array[128];
int licznik;
int b = 0;
int vv = 0;
int save;
int save2;
int a;
void szukaj(char tab1[], char tab2[]){

	int i = sizeof(tab1);
	int j = sizeof(tab2);
wroc:
	int save3 = save2;
	a = save3;
wroc2:
	for (a; a < i; a++)
	{
		save2 = a;
		tab1[a];
		if (tab1[a] == tab2[b])
		{
			save = a;
		dalej:
			printf("licznik : %c", tab1[a]);
			if (b == sizeof(tab2))
			{
				licznik = licznik + 1;
				//koniec

				goto wroc;
			}
			else
			{
				++a;
				++b;
				for (a; a < i; a++)
				{
					if (tab1[a] == tab2[b]){
						goto dalej;
					}
					else
					{
						goto wroc2;
					}
				}
			}
		}
		printf("licznik : %d", licznik);
	}

}
int main() {

	char znaki[128] = "kaiakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwakwa	";
	char tab[] = "kwa";
	printf("tablica: : %c", znaki[a]);
	szukaj(znaki, tab);
	
	int a = sizeof(znaki);
	int b = sizeof(tab);
	for (int i = 0; i <= a-2; i++)
	{
	wroc:
	int j = 0;
	znaki[i];
	if (znaki[i]==tab[j])
	{
	printf("%d tak %c\n",i,znaki[i]);
	++i;
	++j;
	for (i; i < a-2; i++)
	{
	if (znaki[i]==tab[j])
	{
	printf("%d test:    %c\n", i, znaki[i]);
	}
	else
	{
	--j;
	goto wroc;
	}
	}
	}
	else
	{
	printf("%d NIE:    %c \n", i, znaki[i]);
	}
	}
	//printf("wynik:%d ",b);
	//printf("%c",tab[0]);

	
	getchar();
	return 0;

}