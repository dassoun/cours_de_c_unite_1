/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 34
 * Tableaux redimensionnables - Partie 2
 * https://www.youtube.com/watch?v=XQBr2tAOfj4
 */
#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "tools.h"

int main(int argc, char* argv[])
{
	intarray tab = empty_intarray_create(4);
	ext_intarray_debug(tab);
	printf("\n");

	intarray_add(tab, 1);
	ext_intarray_debug(tab);
	printf("\n");

	ext_intarray_set(tab, 3, 2);
	ext_intarray_debug(tab);
	printf("\n");

	ext_intarray_set(tab, 5, 8);
	ext_intarray_debug(tab);
	printf("\n");

	return EXIT_SUCCESS;
}