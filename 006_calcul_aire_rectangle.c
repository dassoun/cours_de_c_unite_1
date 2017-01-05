/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 6
 * Programme qui calcule l'aire d'un rectangle
 * https://www.youtube.com/watch?v=Z1bI7Ra-llE
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int L, l;

	printf("Entrez la longueur du rectangle : ");
	scanf("%d", &L);

	while (L <= 0)
	{
		printf("Anomalie détectée : la longueur doit être strictement positive.\n");
		printf("Entrez la longueur du rectangle : ");
		scanf("%d", &L);
	}

	printf("Entrez la largeur du rectangle : ");
	scanf("%d", &l);

	while (l <= 0)
	{
		printf("Anomalie détectée : la largeur doit être strictement positive.\n");
		printf("Entrez la largeur du rectangle : ");
		scanf("%d", &l);
	}

	if (l > L)
		printf("Anomalie détectée : la largeur %d est strictement supérieure à la longeur %d.\n", l, L);

	printf("L'aire du rectangle est : %d.\n", L * l);

    return EXIT_SUCCESS;
}