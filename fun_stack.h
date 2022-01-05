#ifndef _FUN_STACK_H_IS_INCLUDED_
#define _FUN_STACK_H_IS_INCLUDED_

#define FUNAME_SIZE 256  // rozmiar tablicy funame przechowujaca nazwe funkcji
#define USENR_SIZE 100   // podstawowy rozmiar tablicy int usenr która przechowuje linie w jakich została użyta funkcja 

typedef struct {
	char funame[256];
	int defnrs, defnrk;
	int protonr;
	int *usenr;
	int usenr_i;
	int usenr_max;
} fun_info_t;

typedef struct {
	int par_level;
	char funame[256];
} fun_info_stack_t;

int top_of_funstack( void );  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
void put_on_fun_stack( int par_level, char *funame ); // odkłada na stos parę (funame,par_level)
char *get_from_fun_stack( void ); // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame
void store_add_def(char *, int, char *);
void store_add_proto(char *, int, char *);
void store_add_call(char *, int, char *);

void init_fun_stack(void);

int get_funstack_i(void);
int get_funlist_i(void);
fun_info_t **get_funlist(void);

#endif

