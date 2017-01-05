/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 10
 * Simplifications d'écritures / boucles for
 * https://www.youtube.com/watch?v=wZrKx9csrzs
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int toto = 5;

	toto += 2;
	printf("%d\n", toto);

	toto++;
	printf("%d\n", toto);

	toto -= 5;
	printf("%d\n", toto);

	toto--;
	printf("%d\n", toto);

	toto *= 2;
	printf("%d\n", toto);

	char titi[7] = "Bonjour";
	/*			  1234567	*/
	printf("%c\n", *(titi + 3));
	printf("%c\n", titi[3]);

	titi[3] = '*';
	printf("%c\n", *(titi + 3));
	printf("%s\n", titi);

	/* === Tant que === */
	int i = 0;
	while (i < 10) 
	{
		printf("%d ", i * 10);
		i++;
	}
	printf("\n");

	/* === Pour v1 === */
	i = 0;
	for (; i < 10;)
	{
		printf("%d ", i * 10);
		i++;
	}
	printf("\n");

	/* === Pour v2 === */
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i * 10);
	}
	printf("\n");

	return EXIT_SUCCESS;
}