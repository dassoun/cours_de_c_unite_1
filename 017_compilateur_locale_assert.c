/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 17
 * Compilateur, variable locale, et assert
 * https://www.youtube.com/watch?v=v8qsit2JeS0
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int factorielle(int n)
{
	int i;
	int a = 1;

	assert(n <= 12);

	for(i=1; i<=n; i++)
	{
		a *= i;
	}

	return a;
}

int main(int argc, char *argv[])
{
	int n;

	printf("Saisissez un nombre : ");
	scanf("%d", &n);

	while (n < 0)
	{
		printf("La factorielle d'un nombre négatif n'existe pas.\nSaisissez un nombre positif : ");
		scanf("%d", &n);
	}

	int i;

	for(i=0; i<=n; i++)
	{
		a = factorielle(i);
		printf("%d! = %d\n", i, a);
	}

	return EXIT_SUCCESS;
}


