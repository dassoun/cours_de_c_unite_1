#include <stdio.h>
#include <stdlib.h>

#include "jstr.h"
#include "tools.h"
#include "stringarray.h"

/* Corps des fonctions manipulant des stringarray */
stringarray stringarray_create(int len)
{
	stringarray tab = malloc(sizeof(S_stringarray));
	
	tab->len = len;
	tab->alloc = len;

	stringarray_create_aux(tab);

	return tab;
}

stringarray empty_stringarray_create(int alloc)
{
	stringarray tab = malloc(sizeof(S_stringarray));

	tab->len = 0;
	tab->alloc = alloc;
	
	stringarray_create_aux(tab);

	return tab;
}

stringarray standard_empty_stringarray_create(void)
{
	return empty_stringarray_create(stringarray_DEFAULT_ALLOC);
}

void stringarray_create_aux(stringarray tab)
{
	if (tab->alloc <= 0)
	{
		tab->alloc = 4;

		printf("stringarray_create_aux : taille allouée <= 0.\n");
		printf("Nous allouons %d à la place.\n", tab->alloc);
	}
	
	tab->data = malloc(tab->alloc * sizeof(jstr));

	int i;

	for(i=0; i<tab->alloc; i++)
		tab->data[i] = null;
}

void stringarray_destroy(stringarray tab)
{
	free(tab->data);
	free(tab);
}

void stringarray_destroy_using_jstr_destroy(stringarray tab);
{
	int i;

	for (i=0; i<tab->len; i++)
		jstr_destroy(tab->data[i]);

	stringarray_destroy(tab);
}

char stringarray_get(stringarray tab, int index)
{
	if ((index < 0) || (index >= tab->len))
	{
		printf("stringarray_get : L'index %d est invalide\n", index);
		printf("Les valeurs valides sont entre 0 et %d\n", tab->len-1);
		return -1;
	}

	return tab->data[index];
}

void stringarray_set(stringarray tab, int index, jstr value)
{
	if ((index < 0) || (index >= tab->len))
	{
		printf("stringarray_set : L'index %d est invalide\n", index);
		printf("Les valeurs valides sont entre 0 et %d\n", tab->len-1);

		return;
	}

	tab->data[index] = value;
}

int stringarray_length(stringarray tab)
{
	return tab->len;
}

int stringarray_search(stringarray tab, char n)
{
	int trouve = 0;
	int i = 0;

	while (!trouve && i < tab->len)
	{
		if (tab->data[i] == n)
			trouve = 1;
		i++;
	}

	return trouve;
}

int stringarray_nb_occurences(stringarray tab, char n)
{	
	int i;
	int nb = 0;

	for (i=0; i<tab->len; i++)
	{
		if (tab->data[i] == n)
			nb++;
	}

	return nb;
}

void stringarray_debug(stringarray tab)
{
	int i;
	for (i=0; i<=tab->len-1; i++)
		jstr_debug(tab->data[i]);
}

void ext_stringarray_debug(stringarray tab)
{
	printf("Tab : alloc = %d; len = %d.\n", tab->alloc, tab->len);
	stringarray_debug(tab);
}

stringarray stringarray_concat(stringarray t1, stringarray t2)
{
	int n = t1->len + t2->len;

	stringarray tab = stringarray_create(n);

	int i;
	for(i=0; i<t1->len; i++)
	{
		tab->data[i] = t1->data[i];
	}
	for(i=0; i<t2->len; i++)
	{
		tab->data[t1->len+i] = t2->data[i];
	}

	return tab;
}

void D_stringarray_concat(stringarray t1, stringarray t2)
{
	int i;
	for (i=0; i<t2->len; i++)
		stringarray_add(t1, t2->data[i]);
}

char stringarray_get_min(stringarray tab)
{
	int index_min = stringarray_get_index_of_min(tab);

	return tab->data[index_min];
}

int stringarray_get_index_of_min(stringarray tab)
{
	int indexMin = stringarray_get_index_of_min_from(tab, 0);

	return indexMin;
}

int stringarray_get_index_of_min_from(stringarray tab, int n)
{
	if ((n < 0) || (n >= tab->len))
	{
		printf("stringarray_get_index_of_min_from : L'index %d est invalide\n", n);
		printf("Les valeurs valides sont entre 0 et %d\n", tab->len-1);

		return 0;
	}

	int i;
	char min = tab->data[n];
	int indexMin = n;

	for(i=n+1; i<tab->len; i++)
	{
		if (tab->data[i] < min)
		{
			min = tab->data[i];
			indexMin = i;
		}
	}

	return indexMin;
}

char stringarray_get_max(stringarray tab)
{
	int index_max = stringarray_get_index_of_max(tab);

	return tab->data[index_max];
}

int stringarray_get_index_of_max(stringarray tab)
{
	int indexMax = stringarray_get_index_of_max_from(tab, 0);

	return indexMax;
}

int stringarray_get_index_of_max_from(stringarray tab, int n)
{
	if ((n < 0) || (n >= tab->len))
	{
		printf("stringarray_get_index_of_max_from : L'index %d est invalide\n", n);
		printf("Les valeurs valides sont entre 0 et %d\n", tab->len-1);

		return 0;
	}

	int i;
	char max = tab->data[n];
	int indexMax = n;

	for(i=n+1; i<tab->len; i++)
	{
		if (tab->data[i] > max)
		{
			max = tab->data[i];
			indexMax = i;
		}
	}

	return indexMax;
}

void stringarray_sort1(stringarray tab)
{
	int i;
	int indiceMin;
	int tmp;

	for (i=0; i<tab->len-1; i++)
	{
		indiceMin = stringarray_get_index_of_min_from(tab, i);

		char_swap(tab->data + i, tab->data + indiceMin);
	}
}

stringarray stringarray_clone(stringarray tab)
{
	int i;

	stringarray copy = stringarray_create(tab->len);

	for (i=0; i<tab->len; i++)
	{
		stringarray_set(copy, i, stringarray_get(tab, i));
	}

	return copy;
}

void unsorted_stringarray_delete(stringarray tab, int index)
{
	if ((index < 0) || (index >= tab->len))
	{
		printf("unsorted_stringarray_delete : L'index %d est invalide\n", index);
		printf("Les valeurs valides sont entre 0 et %d\n", tab->len-1);

		return;
	}

	tab->data[index] = tab->data[tab->len - 1];

	tab->len--;
}

void stringarray_delete(stringarray tab, int index)
{
	if ((index < 0) || (index >= tab->len))
	{
		printf("stringarray_delete : L'index %d est invalide\n", index);
		printf("Les valeurs valides sont entre 0 et %d\n", tab->len-1);

		return;
	}

	int i;

	for (i=index+1; i<tab->len; i++)
		tab->data[i-1] = tab->data[i];

	tab->len--;
}

/*
	première version : ne prend pas encore en compte
	les situations où il faut réallouer data
*/
void stringarray_add(stringarray tab, jstr value)
{
	ext_stringarray_set(tab, tab->len, value);
}

void ext_stringarray_set(stringarray tab, int index, jstr value)
{
	if (index < 0)
	{
		printf("ext_stringarray_set : L'index %d est invalide\n", index);
		printf("Les valeurs valides sont supérieures à 0\n");

		return;
	}

	if (index <= (tab->len - 1))
	{
		tab->data[index] = value;
	}
	else
	{
		if (index >= tab->alloc)
			stringarray_resize(tab, (index * 2) + 1);

		int i;

		for(i=tab->len; i<index; i++)
			tab->data[i] = 0;
		tab->data[index] = value;

		tab->len = index + 1;
	}
}

void stringarray_resize(stringarray tab, int newalloc)
{
	char* newdata = malloc(sizeof(char) * newalloc);

	int i;
	for (i=0; i<tab->len; i++)
		newdata[i] = tab->data[i];

	free(tab->data);

	tab->data = newdata;
	tab->alloc = newalloc;
}

stringarray regstr_to_stringarray(regstr str)
{
	int i;
	
	stringarray tab = standard_empty_stringarray_create();
	for (i=0; str[i]!='\0'; i++)
		stringarray_add(tab, str[i]);

	return tab;
}

char* stringarray_to_regstr(stringarray tab)
{
	char* str = malloc(sizeof(char) * (tab->len + 1));
	int i;

	for (i=0; i<tab->len; i++)
		str[i] = tab->data[i];
	str[tab->len] = '\0';

	return str;
}

int stringarray_equal_substr(stringarray j1, int s1, int e1, stringarray j2, int s2)
{
	int len = e1 - s1 + 1;
	int e2 = s2 + len - 1;

	if (s1 > e1)
	{
		int_swap(&s1, &e1);
		printf("stringarray_equal_substr : s1 était supérieur à e1. Les deux ont été échangés.\n");
	}

	if ((s1 < 0) || (s2 < 0) || (s1 >= j1->len) || (e1 >= j1->len) || (s2 >= j2->len))
	{
		printf("stringarray_equal_substr : out of bounds. s1 = %d; e1 = %d;\n", s1, e2);
		printf("s2 = %d; j1->len = %d; j2->len = %d\n", s2, j1->len, j2->len);

		return 0;
	}

	if (e2 >= j2->len)
		return 0;

	int i;

	for (i=0; i<len; i++)
	{
		if (j1->data[i + s1] != j2->data[i + s2])
			return 0;
	}

	return 1;
}

int stringarray_equal(stringarray j1, stringarray j2)
{
	if (j1->len != j2->len)
		return 0;

	return stringarray_equal_substr(j1, 0, (j1->len - 1), j2, 0);
}

intarray stringarray_find_substr_indices(stringarray j, stringarray sub)
{
	intarray tab = standard_empty_intarray_create();
	int i;

	for (i=0; i<=(j->len - sub->len); i++)
	{
		if (stringarray_equal_substr(j, i, ((i + sub->len) - 1), sub, 0))
			intarray_add(tab, i);
	}

	return tab;
}

intarray stringarray_find_proper_substr_indices(stringarray j, stringarray sub)
{
	intarray tab = standard_empty_intarray_create();
	int i = 0;

	while (i <= (j->len - sub->len))
	{
		if (stringarray_equal_substr(j, i, ((i + sub->len) - 1), sub, 0))
		{
			intarray_add(tab, i);
			i += sub->len;
		}
		else
			i++;
	}

	return tab;
}

int stringarray_compare(stringarray j1, stringarray j2)
{
	int i = 0;

	while ((j1->data[i] == j2->data[i]) && (i<(j1->len)) && (i<(j2->len)))
		i++;

	if ((i == (j1->len)) && (i == (j2->len)))
		return 0;

	if ((i == (j1->len)) || (j1->data[i] < j2->data[i]))
		return -1;

	if ((i == (j2->len)) || (j1->data[i] > j2->data[i]))
		return 1;
}