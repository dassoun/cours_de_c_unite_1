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
	jstr j1 = regstr_to_jstr("machin");
	jstr j2 = regstr_to_jstr("aaa");
	jstr j3 = regstr_to_jstr("truc");

	stringarray sa = standard_empty_stringarray_create();

	stringarray_add(sa, j1);
	stringarray_add(sa, j2);
	stringarray_add(sa, j3);

	ext_stringarray_debug(sa);
	printf("\n");

	stringarray_sort1(sa);

	ext_stringarray_debug(sa);
	printf("\n");

	ext_jstr_debug(j1);
	printf("\n");
	ext_jstr_debug(j2);
	printf("\n");

	jstr_swap(j1, j2);	

	ext_jstr_debug(j1);
	printf("\n");
	ext_jstr_debug(j2);
	printf("\n");	


	jstr_swap(sa->data[0], sa->data[1]);


	ext_stringarray_debug(sa);
	printf("\n");


	stringarray_destroy_using_jstr_destroy(sa);

	return EXIT_SUCCESS;
}