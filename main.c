#include "parser.h"
#include "alex.h"
#include "fun_stack.h"
#include <stdio.h>

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		fprintf(stderr, "%s: błąd: Proszę podać plik do odczytu\n", argv[0]);
	}
	
	init_fun_stack();	

	analizatorSkladni(argv[1]);
	printf("TEST: funlist_i: %d\n", get_funlist_i());

	fun_info_t **funlista = get_funlist();

	for (int i = 0; i < get_funlist_i(); i++)
	{
		printf("%d. Funkcja %s:\n", i, funlista[i]->funame);
		printf("\tPrototyp:\n");
		if(funlista[i]->protonr == -1)
		{
			printf("\t\tPrototypu nie ma w podanym pliku\n");
		}
		else
		{
			printf("\t\tLinia %d\n", funlista[i]->protonr);
		}
		printf("\tDefinicja:\n");
		if(funlista[i]->defnrs == -1)
		{
			printf("\t\tDefinicji nie ma w podanym pliku\n");
		}
		else
		{
			printf("\t\tLinie od %d do %d\n", funlista[i]->defnrs, funlista[i]->defnrs);
		}
		printf("\tUzycie\n");
		if(funlista[i]->usenr_i==0)
		{
			printf("\t\tFunkcja nie jest uzyta w podanym pliku\n");
		}
		else
		{
			printf("\t\tFunkcja jest uzyta w liniach:");
			for (int j = 0; j < funlista[i]->usenr_i; j++)
			{
				printf(" %d", funlista[i]->usenr[j]);
			}
			printf("\n");
		}
		printf("\n");
	}

	free_funlist();

	return 0;
}
