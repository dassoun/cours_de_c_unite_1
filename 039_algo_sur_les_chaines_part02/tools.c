#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

int string_to_int(char* str)
{
	int ok;
	int n;

	n = safe_string_to_int(str, &ok);

	if (ok == 0) 
		printf("string_to_int : la chaine %s n'est pas numérique\n", str);

	return n;
}

/*
	ok vaut 1 si pas de caractères autre aue '0'-'9'
	ok vaut 0 sinon
*/
int safe_string_to_int(char* str, int* ok)
{
	*ok = 1;

	if (str[0] == '-')
		return -safe_string_to_int(str + 1, ok);

	if (str[0] == '\0')
	{
		*ok = 0;
		return 0;
	}

	int res = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			*ok = 0;

		res *= 10;
		// Les 2 lignes suivantes sont équivalentes
		res += str[i] - '0';
		//res += str[i] - 48;
		i++;
	}

	return res;
}

void int_swap(int* n, int* m)
{
	int tmp = *m;
	*m = *n;
	*n = tmp;
}

void char_swap(char* n, char* m)
{
	char tmp = *m;
	*m = *n;
	*n = tmp;
}