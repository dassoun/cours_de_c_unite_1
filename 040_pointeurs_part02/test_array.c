/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 40
 * Les pointeurs - Partie 2 - Les pointeurs de pointeurs
 * https://www.youtube.com/watch?v=6Jl68Us03iU
 */
#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "jstr.h"
#include "tools.h"

int main(int argc, char* argv[])
{
	jstr A = regstr_to_jstr("Le soleil");
	//jstr B = jstr_clone(A);
	jstr B = A;
	jstr tmp = regstr_to_jstr(" brille.");

	D_jstr_concat(B, tmp);

	printf("A = ");
	jstr_debug(A);
	printf("\n");
	printf("B = ");
	jstr_debug(B);
	printf("\n");

	jstr_destroy(A);
	//jstr_destroy(B);
	jstr_destroy(tmp);

	return EXIT_SUCCESS;
}