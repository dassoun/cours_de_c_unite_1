/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 38
 * Algorithmique sur des chaines
 * https://www.youtube.com/watch?v=o75Hs0bg5jM
 */
#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "jstr.h"
#include "tools.h"

/*
0) Concaténation des argvs.
1) int jstr_equal_substr(jstr1, int s1, int e2, jstr j2, int s2);
2) int jstr_equal(jstr j1, jstr j2);
3) intarray jstr_find_substr_indices(jstr j, jstr sub);
4) intarray jstr_find_propoer_substr_indices(jstr j, jstr sub);
5) int jstr_compare(jstr j1, jstr j2) => -1, 0 ou 1
*/

int main(int argc, char* argv[])
{
	/*
		Exercice 0 :
		------------
		Ecrire un programme qui concatène en une seule chaine de caractères
		toutes les chaines de argv. (sauf argv[0]).
	*/
	jstr j = standard_empty_jstr_create();
	int i;
	for (i=1; i<argc; i++)
	{
		jstr tmp = regstr_to_jstr(argv[i]);
		D_jstr_concat(j, tmp);
		jstr_destroy(tmp);
	}

	jstr_debug(j);
	printf("\n");

	jstr_destroy(j);

	/*
		Exercice 1 :
		------------
	*/
	jstr j1 = regstr_to_jstr("machin bidule");
	jstr j2 = regstr_to_jstr("ule");

	int res = jstr_equal_substr(j1, 10, 12, j2, 0);
	printf("%d\n", res);

	jstr_destroy(j1);
	jstr_destroy(j2);

	/*
		Exercice 2 :
		------------
	*/
	j1 = regstr_to_jstr("machin");
	j2 = regstr_to_jstr("machin");

	res = jstr_equal(j1, j2);
	printf("%d\n", res);

	jstr_destroy(j1);
	jstr_destroy(j2);

	/*
		Exercice 3 :
		------------
	*/
	j1 = regstr_to_jstr("totototon");
	j2 = regstr_to_jstr("toto");

	intarray tab = jstr_find_substr_indices(j1, j2);
	intarray_debug(tab);
	printf("\n");

	jstr_destroy(j1);
	jstr_destroy(j2);
	intarray_destroy(tab);

	/*
		Exercice 4 :
		------------
	*/
	j1 = regstr_to_jstr("totototon");
	j2 = regstr_to_jstr("toto");

	tab = jstr_find_proper_substr_indices(j1, j2);
	intarray_debug(tab);
	printf("\n");

	jstr_destroy(j1);
	jstr_destroy(j2);
	intarray_destroy(tab);

	/*
		Exercice 5 :
		------------
	*/
	j1 = regstr_to_jstr("toto");
	j2 = regstr_to_jstr("toto");

	res = jstr_compare(j1, j2);

	printf("jstr_compare %s / %s = %d\n", j1->data, j2->data, res);

	jstr_destroy(j1);
	jstr_destroy(j2);

	return EXIT_SUCCESS;
}