/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 43
 * Gestion de la mémoire en c
 * https://www.youtube.com/watch?v=M5yR3Q89wOk
 */
#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "jstr.h"
#include "tools.h"
#include "stringarray.h"

int main(int argc, char* argv[])
{
	tools_memory_init();

	stringarray sa = standard_empty_stringarray_create();

	//stringarray_add(sa, regstr_to_jstr("Le soleil brille."));
	ext_stringarray_set(sa, 0, regstr_to_jstr("Le lapin bleu"));

	stringarray_debug(sa);	
	printf("\n");


	stringarray_destroy_using_jstr_destroy(sa);

/*	jstr j = regstr_to_jstr("Toto est content");
	jstr_debug(j);

	regular_jstr_destroy(&j);
	printf("\n");
	printf("toto\n");

	regular_jstr_destroy(&j);
	printf("titi\n");
	jstr_destroy(j);*/


/*	stringarray sa = standard_empty_stringarray_create();
	jstr j = regstr_to_jstr("Pomme");
	stringarray_add(sa, j);
	j = regstr_to_jstr("Banane");
	stringarray_add(sa, j);
	j = regstr_to_jstr("Framboise");
	stringarray_add(sa, j);
	j = regstr_to_jstr("Orange");
	stringarray_add(sa, j);
	j = regstr_to_jstr("Figue");
	stringarray_add(sa, j);

	ext_stringarray_debug(sa);
	printf("\n");

	stringarray_sort1(sa);
	
	ext_stringarray_debug(sa);	

	stringarray_destroy_using_jstr_destroy(sa);*/

	tools_memory_check_at_end_of_app();

	return EXIT_SUCCESS;
}