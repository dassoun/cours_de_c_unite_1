/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 21
 * Les modules - Partie 2
 * https://www.youtube.com/watch?v=xmxnhxWak1I
 */
#include <stdio.h>
#include <stdlib.h>


void intarray_print_positive_values(int* tab, int len);
int intarray_search(int* tab, int len, int n);
int intarray_nb_occurences(int* tab, int len, int n);


void intarray_print_positive_values(int* tab, int len)
{
	int i;
	printf("[");
	for (i=0; i<len; i++)
	{
		if (tab[i] >= 0)
			printf(" %d", tab[i]);
	}
	printf(" ]");
	printf("\n");
}


int intarray_search(int* tab, int len, int n)
{
	int trouve = 0;
	int i = 0;

	while (!trouve && i < len)
	{
		if (tab[i] == n)
			trouve = 1;
		i++;
	}

	return trouve;
}

int intarray_nb_occurences(int* tab, int len, int n)
{	
	int i;
	int nb = 0;

	for (i=0; i<len; i++)
	{
		if (tab[i] == n)
			nb++;
	}

	return nb;
}

void intarray_debug(int* T, int len)
{
	int i;
	printf("[");
	for (i=0; i<len-1; i++)
		printf("%d ", T[i]);
	printf("%d", T[len-1]);
	printf("]");
	printf("\n");
}

int main(int argc, char *argv[])
{
	int n;

	printf("Combien de cases voulez-vous remplir ? ");
	scanf("%d", &n);

	int i;
	int* toto = malloc(n * sizeof(int));
	
	for (i=0; i<n; i++)
	{
		printf("Veuillez saisir la valeur numéro %d : ", i);
		scanf("%d", &toto[i]);
	}

	intarray_debug(toto, n);

	intarray_print_positive_values(toto, n);


	int search;
	int trouve;
	printf("Entrez une valeur à chercher ? ");
	scanf("%d", &search);

	trouve = intarray_search(toto, n, search);
	if (trouve == 1)
		printf("La valeur %d a été trouvée %d fois.\n", search, intarray_nb_occurences(toto, n, search));
	else 
		printf("La valeur %d n'a pas été trouvée.\n", search);

	free(toto);

	return EXIT_SUCCESS;
}