typedef struct _intarray intarray;

struct _intarray {
	int* data;
	int len;
};

/* Prototypes des fonctions manipulant des intarray */
intarray intarray_create(int len);
void intarray_destroy(intarray tab);
int intarray_get(intarray tab, int index);
void intarray_set(intarray tab, int index, int value);
int intarray_length(intarray tab);
void intarray_print_positive_values(intarray tab);
int intarray_search(intarray tab, int n);
int intarray_nb_occurences(intarray tab, int n);
void intarray_debug(intarray tab);
/* retourne le résultat de la concaténation de t1 et t2 */
intarray intarray_concat(intarray t1, intarray t2);
/* retourne la plus petite valeur contenue dans tab */
int intarray_get_min(intarray tab);
/* retourne l'index de la plus petite valeur contenue dans tab */
int intarray_get_index_of_min(intarray tab);
/*
	retourne l'index de la plus petite valeur contenue dans tab
	entre la case numéro n et la fin du tableau
*/
int intarray_get_index_of_min_from(intarray tab, int n);
/* retourne la plus grande valeur contenue dans tab */
int intarray_get_max(intarray tab);
/* retourne l'index de la plus grande valeur contenue dans tab */
int intarray_get_index_of_max(intarray tab);
/*
	retourne l'index de la plus grande valeur contenue dans tab
	entre la case numéro n et la fin du tableau
*/
int intarray_get_index_of_max_from(intarray tab, int n);
/* Tri par sélection du minimum */
void intarray_sort1(intarray tab);
void int_swap(int* n, int* m);

int intarray_sum(intarray tab);
float intarray_average(intarray tab);
float intarray_median(intarray tab);
intarray intarray_clone(intarray tab);