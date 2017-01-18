/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 24
 * Programmer proprement - partie 2
 * https://www.youtube.com/watch?v=2bak_UkZlX8
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

/* retourne le résultat de la concaténation de t1 et t2 */
intarray intarray_concat(intarray t1, intarray t2);
/* retourne la plus petite valeur contenue dans tab */
int intarray_get_min(intarray tab);
/* retourne l'index de la plus petite valeur contenue dans tab */
int intarray_get_index_of_min(intarray tab);
/*
	retourne l'index de la plus petite valeur contenue dans tab
	entre la case numéro n et la fin du tableau
*/
int intarray_get_index_of_min_from(intarray tab, int n);
/* retourne la plus grande valeur contenue dans tab */
int intarray_get_max(intarray tab);
/* retourne l'index de la plus grande valeur contenue dans tab */
int intarray_get_index_of_max(intarray tab);
/*
	retourne l'index de la plus grande valeur contenue dans tab
	entre la case numéro n et la fin du tableau
*/
int intarray_get_index_of_max_from(intarray tab, int n);


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

intarray intarray_concat(intarray t1, intarray t2)
{
	int n = t1.len + t2.len;

	intarray tab = intarray_create(n);

	int i;
	for(i=0; i<t1.len; i++)
	{
		tab.data[i] = t1.data[i];
	}
	for(i=0; i<t2.len; i++)
	{
		tab.data[t1.len+i] = t2.data[i];
	}

	return tab;
}

int intarray_get_min(intarray tab)
{
	int index_min = intarray_get_index_of_min(tab);

	return tab.data[index_min];
}

int intarray_get_index_of_min(intarray tab)
{
	int indexMin = intarray_get_index_of_min_from(tab, 0);

	return indexMin;
}

int intarray_get_index_of_min_from(intarray tab, int n)
{
	int i;
	int min = tab.data[n];
	int indexMin = n;

	for(i=n+1; i<tab.len; i++)
	{
		if (tab.data[i] < min)
		{
			min = tab.data[i];
			indexMin = i;
		}
	}

	return indexMin;
}

int intarray_get_max(intarray tab)
{
	int index_max = intarray_get_index_of_max(tab);

	return tab.data[index_max];
}

int intarray_get_index_of_max(intarray tab)
{
	int indexMax = intarray_get_index_of_max_from(tab, 0);

	return indexMax;
}

int intarray_get_index_of_max_from(intarray tab, int n)
{
	int i;
	int max = tab.data[n];
	int indexMax = n;

	for(i=n+1; i<tab.len; i++)
	{
		if (tab.data[i] > max)
		{
			max = tab.data[i];
			indexMax = i;
		}
	}

	return indexMax;
}

int main(int argc, char *argv[])
{
	intarray tab1 = intarray_create(2);
	intarray tab2 = intarray_create(3);

	intarray_set(tab1, 0, 5);
	intarray_set(tab1, 1, 6);

	intarray_set(tab2, 0, 1);
	intarray_set(tab2, 1, 2);
	intarray_set(tab2, 2, 3);

	intarray tab3 = intarray_concat(tab1, tab2);	

	intarray_debug(tab1);
	printf("\n");
	intarray_debug(tab2);
	printf("\n");
	intarray_debug(tab3);
	printf("\n");

	printf("min de tab3 = %d", intarray_get_min(tab3));
	printf("\n");

	printf("indice du min de tab3 = %d", intarray_get_index_of_min(tab3));
	printf("\n");

	printf("max de tab3 = %d", intarray_get_max(tab3));
	printf("\n");

	printf("indice du max de tab3 = %d", intarray_get_index_of_max(tab3));
	printf("\n");

	printf("indice du min de tab3 à partir de l'indice 3 = %d", intarray_get_index_of_min_from(tab3, 3));
	printf("\n");

	printf("indice du max de tab3 à partir de l'indice 3 = %d", intarray_get_index_of_max_from(tab3, 3));
	printf("\n");

	intarray_destroy(tab1);
	intarray_destroy(tab2);
	intarray_destroy(tab3);

	return EXIT_SUCCESS;
}