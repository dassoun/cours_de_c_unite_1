#include <stdio.h>
#include <stdlib.h>

#include "tools.h"
#include "intarray.h"

int main(int argc, char* argv[])
{
	tools_memory_init();

	intarray tab = empty_intarray_create(argc - 1);
	int i;

	for (i=1; i<argc; i++)
	{
		int ok;
		int n = safe_string_to_int(argv[i], &ok);
		if (ok)
		{
			printf("%d\n", n);
			intarray_add(tab, n);
		}
		else
			printf("%s n'est pas un nombre, on l'ignore\n", argv[i]);
	}

	if (tab->len == 0)
	{
		printf("Aucun nombre. Statistiques impossibles.");
		intarray_destroy(tab);

		return EXIT_SUCCESS;
	}

	printf("Vous avez entré les entiers suivants :\n");
	intarray_debug(tab);
	printf("\n");

	int min = intarray_get_min(tab);
	int max = intarray_get_max(tab);
	
	printf("Quelques statistiques: \n");
	printf("Minimum = %d\n", min);
	printf("Maximum = %d\n", max);
	printf("Etendue = %d\n", max - min);
	printf("Somme = %d\n", intarray_sum(tab));
	printf("Moyenne = %f\n", intarray_average(tab));
	printf("Médiane = %f\n", intarray_median(tab));

	intarray_destroy(tab);

	tools_memory_check_at_end_of_app();

	return EXIT_SUCCESS;
}