/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 8
 * Les chaines de caractères - partie 1 = pointeurs partie 0
 * https://www.youtube.com/watch?v=LnYb8IeU5gY
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char* toto = "Bonjour les gens";
	int i = 0;

	while (*(toto + i) != '\0')
	{
		printf("%c ", *(toto + i));
		i++;
	}

	return EXIT_SUCCESS;
}