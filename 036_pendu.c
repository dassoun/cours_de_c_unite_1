/*
 * Cours de Jacques-Olivier Lapeyre
 * Cours 36
 * Jeu du pendu - Partie 2 (correction)
 * https://www.youtube.com/watch?v=2WJ6qD7TGEU
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _pendu S_pendu;
typedef struct _pendu* pendu;

struct _pendu{
	char* word;
	char tried[26];
	int remaining_letters;
	int remaining_tries;
};

void S_pendu_init(pendu P, char* word, int nb_tries)
{
	int len = strlen(word);
	char first = word[0];
	char last = word[len - 1];
	int i;
	P->word = word;
	P->remaining_tries = nb_tries;
	P->remaining_letters = strlen(word);

	for (i=0; i<26; i++)
		P->tried[i] = 0;

	if (len <= 1)
	{
		P->remaining_letters =0;
		return;
	}

	P->remaining_letters -= 2;

	if ((first >= 'A') && (first <= 'Z'))
		P->tried[first - 'A'] = 1;

	if ((last >= 'A') && (last <= 'Z'))
		P->tried[last - 'A'] = 1;
	
	for (i=1; i<=(len-2); i++)
	{
		char c = word[i];
		if ((c == first) || (c == last) || (c < 'A') || (c > 'Z'))
			P->remaining_letters--;

	}

	/*printf("word = %s. remaining_letters = %d\n", P->word, P->remaining_letters);*/
}

char pendu_choix_lettre(pendu P)
{
	char c;
	char ok = 0;
	do
	{
		scanf("%c", &c);
		if ((c >= 'a') && (c <= 'z'))
			c += ('A' - 'a');

		if ((c >= 'A') && (c <= 'Z') && P->tried[c - 'A'] == 0)
			ok = 1;
		else if (c != '\n')
			printf("Le caractère %c a déjà été testé ou placé. Ré-essayez.\n", c);
	} 
	while (ok == 0);

	return c;	
}

void pendu_display(pendu P)
{
	int i;
	for (i=0; P->word[i]!='\0'; i++)
	{
		char c = P->word[i];
		if ((P->tried[c - 'A'] == 1) || (c < 'A') || (c > 'Z'))
			printf("%c", c);
		else
			printf("-");
	}
}

void pendu_play(pendu P)
{
	char letter;
	while ((P->remaining_tries > 0) && (P->remaining_letters > 0))
	{
		int trouve = 0;
		int i;
		pendu_display(P);
		printf("\nIl vous reste %d erreur(s) max.", P->remaining_tries);
		printf("\n\nChoisissez une lettre : ");
		letter = pendu_choix_lettre(P);
		P->tried[letter - 'A'] = 1;

		for(i=0; P->word[i]!='\0'; i++)
		{
			if (P->word[i] == letter)
			{
				trouve = 1;
				P->remaining_letters--;
			}
		}
		if (trouve == 0)
			P->remaining_tries--;
	}

	if (P->remaining_letters > 0)
	{
		pendu_display(P);
		printf("\nVous avez gagné.\n");
		printf("Il vous restait %d droit(s) à l'erreur.\n", P->remaining_tries);
	} 
	else 
	{
		printf("Vous avez perdu.\n");
		printf("Le mot à trouver était %s.\n", P->word);
	}
}

void make_uppercase(char* str)
{
	int i = 0;
	for (i=0; str[i]!='\0'; i++)
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			str[i] += ('A' - 'a');
	}
}

int main(int argc, char** argv)
{
	S_pendu P;
	char* word;
	int nb_tries;
	int i;

	if (argc >= 2)
	{
		word = argv[1];
		make_uppercase(word);
	}
	else
		word = "EXCEPTIONNELLEMENT";

	if (argc >= 3)
		nb_tries = atoi(argv[2]);
	else
		nb_tries = 7;

	for (i=0; i<30; i++)
		printf("\n");

	printf("Jeu du Pendu. Vous avez droit à %d erreur(s).\n", nb_tries);

	S_pendu_init(&P, word, nb_tries);

	pendu_play(&P);

	return EXIT_SUCCESS;
}