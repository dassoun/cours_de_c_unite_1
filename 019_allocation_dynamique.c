/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 19
 * Allocation dynamique
 * https://www.youtube.com/watch?v=FqKA_ucr_E8
 */
#include <stdio.h>
#include <stdlib.h>

#define RC printf("\n")

void intarray_debug(int* T, int len)
{
	int i;
	printf("[");
	for (i=0; i<len-1; i++)
		printf("%d ", T[i]);
	printf("%d", T[len-1]);
	printf("]");
	RC;
}

int main(int argc, char *argv[])
{
	int n;

	printf("Combien de cases voulez-vous remplir ? ");
	scanf("%d", &n);

	int i;
	int* toto = malloc(n * sizeof(int));
	
	for (i=0; i<n; i++)
	{
		toto[i] = 2 * i + 5;
	}
	intarray_debug(toto, n);
	free(toto);

	return EXIT_SUCCESS;
}