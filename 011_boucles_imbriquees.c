/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 11
 * Boucles imbriquées
 * https://www.youtube.com/watch?v=M_wnksdocZc
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	int j;

	for (i=1; i<=10; i++)
	{
		printf("Table de multipliacation de %d :\n", i);
		for (j=1; j<=10; j++)
		{
			printf("%d * %d = %d\n", i, j, i* j);
		}
		printf("\n");
	}
	
	printf("\n");

	return EXIT_SUCCESS;
}