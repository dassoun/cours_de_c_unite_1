#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"

/* Corps des fonctions manipulant des intarray */
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
	if ((n < 0) || (n >= tab.len))
	{
		printf("intarray_get_index_of_min_from :  : L'index %d est invalide\n", n);
		printf("Les valeurs valides sont entre 0 et %d\n", tab.len-1);

		return 0;
	}

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
	if ((n < 0) || (n >= tab.len))
	{
		printf("intarray_get_index_of_max_from : L'index %d est invalide\n", n);
		printf("Les valeurs valides sont entre 0 et %d\n", tab.len-1);

		return 0;
	}

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

void intarray_sort1(intarray tab)
{
	int i;
	int indiceMin;
	int tmp;

	for (i=0; i<tab.len-1; i++)
	{
		indiceMin = intarray_get_index_of_min_from(tab, i);

		/* Les 2 lignes suivantes sont équivalentes */
		//intarray_swap(&(tab.data[i]), &(tab.data[indiceMin]));
		int_swap(tab.data + i, tab.data + indiceMin);
	}
}

void int_swap(int* n, int* m)
{
	int tmp = *m;
	*m = *n;
	*n = tmp;
}

int intarray_sum(intarray tab)
{
	int i;
	int res = 0;

	for (i=0; i<tab.len; i++)
	{
		res += tab.data[i];
	}

	return res;
}

float intarray_average(intarray tab)
{
	float res = 0.0;

	if (tab.len > 0)
	{
		res = (float) intarray_sum(tab) / tab.len;
	}
	
	return res;
}

float intarray_median(intarray tab)
{
	float res; 

	intarray_sort1(tab);

	if (tab.len % 2 > 0)
	{	
		res = tab.data[((tab.len + 1) / 2) - 1];
	} else {
		int indiceInf = (tab.len / 2) - 1;
		int indiceSup = (tab.len / 2);

		res = (float) (tab.data[indiceInf] + tab.data[indiceSup]) / 2;
	}

	return res;
}