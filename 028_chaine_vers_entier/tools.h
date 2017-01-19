#include <stdio.h>
#include <stdlib.h>

int string_to_int(char* str);
/*
	ok vaut 1 si pas de caractères autre aue '0'-'9'
	ok vaut 0 sinon
*/
int safe_string_to_int(char* str, int* ok);