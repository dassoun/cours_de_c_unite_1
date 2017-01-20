/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 33
 * Tableaux redimensionnables - Partie 1
 * https://www.youtube.com/watch?v=R7TXSrs_gYY
 */
#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "tools.h"

int main(int argc, char* argv[])
{
	intarray tab = intarray_create(10);

	intarray_set(tab, 4, 10);
	intarray_set(tab, 9, 25);

	intarray_debug(tab);
	printf("\n");

	intarray_delete(tab, 4);

	intarray_debug(tab);
	printf("\n");

	intarray_add(tab, 99);
	intarray_debug(tab);
	printf("\n");

	intarray_add(tab, 99999);
	intarray_debug(tab);
	printf("\n");

	unsorted_intarray_delete(tab, -5);

	intarray_debug(tab);
	printf("\n");

	unsorted_intarray_delete(tab, 56);

	intarray_debug(tab);
	printf("\n");

	intarray tab2 = empty_intarray_create(10);
	intarray_debug(tab2);
	printf("\n");

	intarray tab3 = empty_intarray_create(1);

	intarray_destroy(tab);
	intarray_destroy(tab2);
	intarray_destroy(tab3);


	return EXIT_SUCCESS;
}