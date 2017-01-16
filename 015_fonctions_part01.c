/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 15
 * Les fonctions - partie 1
 * https://www.youtube.com/watch?v=sAI1KbWfcLE
 */
#include <stdio.h>
#include <stdlib.h>

long factorielle(int n)
{
	int i;
	long a = 1;

	for(i=1; i<=n; i++)
	{
		a *= i;
	}

	return a;
}

int main(int argc, char *argv[])
{
	int n;
	long res;

	printf("Saisissez un nombre : ");
	scanf("%d", &n);

	while (n < 0)
	{
		printf("La factorielle d'un nombre négatif n'existe pas.\nSaisissez un nombre positif : ");
		scanf("%d", &n);
	}

	res = factorielle(n);
	printf("La factorielle de %d est : %ld", n, res);

	return EXIT_SUCCESS;
}


