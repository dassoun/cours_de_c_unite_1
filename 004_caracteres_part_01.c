/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 4
 * Les caractères - Partie 1
 * https://www.youtube.com/watch?v=Vmaq7k3r9F0
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	char toto = 'A';
	printf("%c\n", toto);

	toto = toto + 1;
	printf("%c\n", toto);

	toto = 65;
	printf("%c\n", toto);

	toto = toto + 32;
	printf("%c", toto);

    return (EXIT_SUCCESS);
}