/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 6
 * Programme qui calcule l'aire d'un rectangle
 * https://www.youtube.com/watch?v=Z1bI7Ra-llE
 */
#include <stdio.h>
#include <stdlib.h>

int lire_dimension(char* nom)
{
	int dimension;

	printf("Entrez %s du rectangle : ", nom);
	scanf("%d", &dimension);

	while (dimension <= 0)
	{
		printf("Anomalie détectée : %s doit être strictement positive.\n", nom);
		printf("Entrez la %s du rectangle : ", nom);
		scanf("%d", &dimension);
	}

	return dimension;
}

int main(int argc, char *argv[]) 
{
	int L, l;

	L = lire_dimension("la longueur");

	l = lire_dimension("la largeur");

	if (l > L)
		printf("Anomalie détectée : la largeur %d est strictement supérieure à la longeur %d.\n", l, L);

	printf("L'aire du rectangle est : %d.\n", L * l);

    return EXIT_SUCCESS;
}