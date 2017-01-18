/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 23
 * Programmer proprement
 * https://www.youtube.com/watch?v=v0_uUQy4Yzo
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _intarray intarray;

struct _intarray {
	int* data;
	int len;
};

intarray intarray_create(int len);

void intarray_destroy(intarray tab);
int intarray_get(intarray tab, int index);
void intarray_set(intarray tab, int index, int value);
int intarray_length(intarray tab);

void intarray_print_positive_values(intarray tab);
int intarray_search(intarray tab, int n);
int intarray_nb_occurences(intarray tab, int n);
void intarray_debug(intarray tab);


intarray intarray_create(int len)
{
	intarray tab;
	int i;
	tab.len = len;
	tab.data = malloc(len * sizeof(int));

	for(i=0; i<len; i++) {
		tab.data[i] = 0;
	}

	return tab;
}

void intarray_destroy(intarray tab)
{
	free(tab.data);
}

int intarray_get(intarray tab, int index)
{
	if ((index < 0) || (index >= tab.len))
	{
		printf("intarray_get : L'index %d est invalide\n", index);
		printf("Les valeurs valides sont entre 0 et %d\n", tab.len-1);
		return -1;
	}

	return tab.data[index];
}

void intarray_set(intarray tab, int index, int value)
{
	if ((index < 0) || (index >= tab.len))
	{
		printf("intarray_get : L'index %d est invalide\n", index);
		printf("Les valeurs valides sont entre 0 et %d\n", tab.len-1);

		return;
	}

	tab.data[index] = value;
}

int intarray_length(intarray tab)
{
	return tab.len;
}

void intarray_print_positive_values(intarray tab)
{
	int i;
	printf("[");
	for (i=0; i<tab.len-1; i++)
	{
		if (tab.data[i] >= 0)
			printf("%d ", tab.data[i]);
	}
	if (tab.data[tab.len-1] >= 0)
			printf("%d", tab.data[tab.len-1]);
	printf("]");
}


int intarray_search(intarray tab, int n)
{
	int trouve = 0;
	int i = 0;

	while (!trouve && i < tab.len)
	{
		if (tab.data[i] == n)
			trouve = 1;
		i++;
	}

	return trouve;
}

int intarray_nb_occurences(intarray tab, int n)
{	
	int i;
	int nb = 0;

	for (i=0; i<tab.len; i++)
	{
		if (tab.data[i] == n)
			nb++;
	}

	return nb;
}

void intarray_debug(intarray tab)
{
	int i;
	printf("[");
	for (i=0; i<tab.len-1; i++)
		printf("%d ", tab.data[i]);
	printf("%d", tab.data[tab.len-1]);
	printf("]");
}

int main(int argc, char *argv[])
{
	intarray tab = intarray_create(10);

	int n;

	intarray_set(tab, 0, 13);
	intarray_set(tab, 5, 45);

	intarray_debug(tab);
	printf("\n");

	intarray_set(tab, 5, 45);

	n = intarray_get(tab, 56);

	printf("%d", n);
	printf("\n");

	printf("La taille du tableau tab est %d cases.\n", intarray_length(tab));

	intarray_destroy(tab);

	return EXIT_SUCCESS;
}