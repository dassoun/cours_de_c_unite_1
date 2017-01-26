/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 41
 * Module stringarray - partie 1
 * https://www.youtube.com/watch?v=9sFXFyoHOGU
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

	stringarray_destroy_using_jstr_destroy(sa);

	tools_memory_check_at_end_of_app();

	return EXIT_SUCCESS;
}