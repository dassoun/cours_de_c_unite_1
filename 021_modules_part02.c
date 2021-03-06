/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 21
 * Les modules - Partie 2
 * https://www.youtube.com/watch?v=xmxnhxWak1I
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct _intarray intarray;

struct _intarray {
	int* data;
	int len;
};

intarray intarray_create(int len);
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

	intarray_debug(tab);
	printf("\n");

	tab.data[0] = -4;
	tab.data[5] = 20;
	tab.data[7] = 20;

	intarray_debug(tab);
	printf("\n");

	intarray_print_positive_values(tab);
	printf("\n");
	printf("%d", intarray_search(tab, 20));
	printf("\n");
	printf("%d", intarray_nb_occurences(tab, 20));
	printf("\n");

	free(tab.data);

	return EXIT_SUCCESS;
}