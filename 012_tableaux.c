/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 12
 * Tableaux
 * https://www.youtube.com/watch?v=dJNZNmYrWZ0
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	int tab[10];

	for (i=0; i<=9; i++)
	{
		printf("Entrez l'entier numéro %d : ", i + 1);
		scanf("%d", &tab[i]);
	}

	printf("Vous avez entré, dans cet ordre, les nombres : ");
	for (i=0; i<=9; i++)
	{
		if (i < 9)
			printf("%d, ", tab[i]);
		else
			printf("%d.", tab[i]);
		
	}

	printf("Vous avez entré, dans l'ordre inverse, les nombres : ");
	for (i=9; i>=0; i--)
	{
		if (i > 0)
			printf("%d, ", tab[i]);
		else
			printf("%d.", tab[i]);
		
	}

	return EXIT_SUCCESS;
}