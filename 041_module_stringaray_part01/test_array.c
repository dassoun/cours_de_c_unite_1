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
	jstr j = regstr_to_jstr("Machin");
	stringarray sa = standard_empty_stringarray_create();

	stringarray_add(sa, j);

	stringarray_debug(sa);

	stringarray_destroy_using_jstr_destroy(sa);

	return EXIT_SUCCESS;
}