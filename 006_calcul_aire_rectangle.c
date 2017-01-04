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

	printf("Entrez la largeur du rectangle : ");
	scanf("%d", &l);

	printf("L'aire du rectangle est : %d", L * l);

    return (EXIT_SUCCESS);
}