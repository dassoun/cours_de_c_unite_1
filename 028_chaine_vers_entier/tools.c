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

int main(int argc, char *argv[]) 
{
    char* str = "00000";

    printf("%d\n", string_to_int(str));
    
    return (EXIT_SUCCESS);
}