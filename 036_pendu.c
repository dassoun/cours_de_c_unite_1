/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 36
 * Jeu du pendu - Partie 1
 * https://www.youtube.com/watch?v=QzUU2CXD6qg
 */
#include <stdio.h>
#include <stdlib.h>

void display_word(char* word, int* tab_tried, int* tab_found)
{
	int i = 0;
	char* word_to_display = "";

	while (word[i] != '\0')
	{

		i++;
	}
}

char upper_char(char c)
{
	if ((c >= 97) && (c <= 123))
		return (c - 32);
	else
		return (c);
}

void upper_word(char* word)
{
	int i = 0;
	
	while (word[i] != '\0')
	{
		word[i] = upper_char(word[i]);
		i++;
	}
}

int try_char(char c, int* tab_tried, int* tab_found, char* word)
{

}

void array_debug(int* tab, int len)
{
	int i;
	printf("[");
	for (i=0; i<len; i++)
	{
		char* s;
		if (i == (len - 1))
			s = "";
		else
			s = ", ";
		printf("%d=>%d%s", i, tab[i], s);
	}
	printf("]");
}

int main(int argc, char* argv[])
{
	char* word = "default";
	int nblives = 7;

	int tab_tried[26];
	int tab_found[26];

	int i;

	for (i=0; i<26; i++)
	{
		tab_tried[i] = 0;
		tab_found[i] = 0;
	}

	if (argc == 1)
		upper_word(word);
	else if (argc == 2)
		word = argv[1];
	else if (argc == 3)
	{
		word = argv[1];
		upper_word(word);
		nblives = *argv[2] - '0'; // Conversion du caractère en entier
	}

	tab_tried[word[0] - 'A'] = 1;
	tab_found[word[0] - 'A'] = 1;

	printf("%s\n", word);
	printf("%d\n", nblives);

	int found = 0;

	/*while ((found == 0) && (nblives > 0))
	{

	}*/

	printf("%d\n", 'a');
	printf("%d\n", 'A');

	printf("%c\n", upper_char('A'));
	printf("%c\n", upper_char('a'));
	printf("%c\n", upper_char('.'));

	array_debug(tab_tried, 26);
	printf("\n");

	return EXIT_SUCCESS;
}