/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 9
 * Les pointeurs - partie 1
 * https://www.youtube.com/watch?v=DVxXCHtW67U
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	printf("Taille d'un entier : %d\n", sizeof(char*));

	char a = 'M';
	char* p = &a;
	printf("%c\n", a);
	*p = 'Z';
	printf("%c\n", a);

	char b = 'M';
	char* q = &b;
	char** r = &q;
	printf("%c\n", *q);
	printf("%c\n", **r);

	return EXIT_SUCCESS;
}