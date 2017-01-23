/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 36
 * Jeu du pendu - Partie 1
 * https://www.youtube.com/watch?v=QzUU2CXD6qg
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_FOUND 				1
#define CHAR_ALREADY_TRIED		2
#define CHAR_NOT_FOUND			3
#define CHAR_FIRST_TRY			4

int display_word(char* word, int* tab_tried);
char upper_char(char c);
void upper_word(char* word);
int try_char(char c, int* tab_tried, char* word);
void array_debug(int* tab, int len);
int already_tried(char c, int* tab_tried);


int display_word(char* word, int* tab_tried)
{
	int i = 0;
	int nbletterstofind = 0;

	while (word[i] != '\0')
	{	
		if (word[i] >= 65 && word[i] <= 90)
		{
			if (tab_tried[word[i] - 65] == 1)
				printf("%c", word[i]);
			else
			{
				printf("-");
				nbletterstofind++;
			}
		}
		else 
			printf("%c", word[i]);

		i++;
	}

	return nbletterstofind;
}

char upper_char(char c)
{
	if ((c >= 97) && (c <= 122))
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

int try_char(char c, int* tab_tried, char* word)
{
	if (already_tried(c, tab_tried))
		return CHAR_ALREADY_TRIED;

	tab_tried[c - 65] = 1;

	int i;
	while (word[i] != '\0')
	{
		if (word[i] == c)
			return CHAR_FOUND;
		i++;
	}

	return CHAR_NOT_FOUND;
}

int already_tried(char c, int* tab_tried)
{
	return tab_tried[c - 65];
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
	char* word;
	int nblives = 7;

	int tab_tried[26];

	char typedletter;

	int letterstofind;

	int i;

	// On vide l'ecran pour masquer le mot saisi
	for (i=0; i<30; i++)
		printf("\n");

	for (i=0; i<26; i++)
		tab_tried[i] = 0;

	if (argc >= 2)
	{
		word = argv[1];
		upper_word(word);
	}
	else
		word = "MACHINBIDULE";

	if (argc >= 3)
		nblives = atoi(argv[2]);
	else
		nblives = 7;		

	printf("Jeu du Pendu. Vous avez droit à %d essais.\n", nblives);

	try_char(word[0], tab_tried, word);
	try_char(word[strlen(word) - 1], tab_tried, word);

	letterstofind = display_word(word, tab_tried);
	printf("\n");

	while ((nblives > 0) && (letterstofind > 0))
	{	
		int res;

		printf("Saisissez une lettre : ");
		scanf("%c", &typedletter);

		// On vide le buffer, sinon ça déconne
		char c;
		while ((c = getchar()) != '\n' && c != EOF) { }

		res = try_char(upper_char(typedletter), tab_tried, word);
		if (res == CHAR_ALREADY_TRIED)
			printf("La lettre %c a déjà été placée, ou testée.\nIl vous reste toujours %d essai(s).\n", upper_char(typedletter), nblives);
		if (res == CHAR_NOT_FOUND)
		{
			nblives--;
			printf("La lettre %c n'est pas dans le mot.\nIl vous reste %d essai(s).\n", upper_char(typedletter), nblives);
		}

		letterstofind = display_word(word, tab_tried);
		printf("\n");
	}

	if (nblives <= 0)
		printf("\nNombre de tentatives maximum atteint.\nVous avez perdu...\n");

	if (letterstofind <= 0)
		printf("\nLe mot à trouver était : %s.\nVous avez gagné !\n", word);

	return EXIT_SUCCESS;
}