/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 30
 * 2e Programme
 * https://www.youtube.com/watch?v=kByAEWhgHF4
 */
#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"
#include "tools.h"

int main(int argc, char* argv[])
{
	char* str = "-156";
	printf("%d\n", string_to_int(str));

	return EXIT_SUCCESS;
}