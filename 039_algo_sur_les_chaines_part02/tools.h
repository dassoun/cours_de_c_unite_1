#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdio.h>
#include <stdlib.h>

/* regstr = regular str = string with an ending '\0' */
typedef char* regstr;

int string_to_int(char* str);
/*
	ok vaut 1 si pas de caractères autre aue '0'-'9'
	ok vaut 0 sinon
*/
int safe_string_to_int(char* str, int* ok);
void int_swap(int* n, int* m);
void char_swap(char* n, char* m);

#endif