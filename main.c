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

	analizatorSkladni(argv[1]);

	fun_info_t **funlista = get_funlist();

	for (int i = 0; i < get_funlist_i(); i++)
	{
		printf("Funkcja %s:\n", funlista[i]->funame);
		printf("\tPrototyp:");
		if(funlista[i]->protonr == -1)
		{
			printf("\t\tPrototypu nie ma w podanym pliku\n");
		}
		else
		{
			printf("\t\tLinia %s\n", funlista[i]->protonr);
		}
		printf("\tDefinicja:");
		if(funlista[i]->defnrs == -1)
		{
			printf("\t\tDefinicji nie ma w podanym pliku\n");
		}
		else
		{
			printf("\t\tLinie od %s do %s\n", funlista[i]->defnrs, funlista[i]->defnrs);
		}
		printf("\tUzycie");
		if(funlista[i]->usenr_i==0)
		{
			printf("\t\tFunkcja nie jest uzyta w podanym pliku\n");
		}
		else
		{
			printf("\t\tFunkcja jest uzyta w liniach:");
			for (int j = 0; j < usenr_i; j++)
			{
				printf(" %d", funlista[i]->usenr[j]);
			}
		}
	}

	return 0;
