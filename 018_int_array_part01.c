/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 18
 * int array - partie 1
 * https://www.youtube.com/watch?v=fGn0U9aROR4
 */
#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#define RC printf("\n")

void intarray_debug(int* T, int len)
{
	int i;
	for (i=0; i<len; i++)
	{
		printf("%d ", T[i]);
	}
	RC;
}

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
	int T[8];
	int i;

	for (i=0; i<8; i++)
	{
		T[i] = factorielle(i);
	}

	intarray_debug(T, 8);

	return EXIT_SUCCESS;
}