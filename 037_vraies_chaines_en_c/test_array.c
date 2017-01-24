/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 37
 * De vraes chaines de caractères en c
 * https://www.youtube.com/watch?v=FxgxgmDRhNw
 */
#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "jstr.h"
#include "tools.h"

int main(int argc, char* argv[])
{
	jstr tab = standard_empty_jstr_create();
	int i;

	for(i=0; i<=100; i++)
		jstr_add(tab, i);

	jstr_debug(tab);
	printf("\n");

	char* str = "Hello world !\n";
	jstr tab2 = regstr_to_jstr(str);
	jstr_debug(tab2);

	char* toto = jstr_to_regstr(tab2);
	printf("toto = %s\n", toto);

	jstr_destroy(tab);
	jstr_destroy(tab2);
	free(toto);

	return EXIT_SUCCESS;
}