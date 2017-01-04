/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 5
 * Les caractères - Partie 2
 * https://www.youtube.com/watch?v=cdxwgC_HFfo
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	unsigned char toto = 'A';

	while (toto < 'Z')
	{
		printf("%c ", toto);
		toto = toto + 1;
	}
	printf("\n");

	toto = '0';
	while (toto < 255)
	{
		printf("%c ", toto);
		toto = toto + 1;
	}

	printf("%c", 7); /* Afficher la cloche */
	

    return (EXIT_SUCCESS);
}