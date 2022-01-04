#include "fun_stack.h"
#include <stdlib.h>

fun_info_t funstack[100];
fun_info_t *funlist = malloc(100 * sizeof(*funlist));
static int funstack_i = 0;
static int funlist_i = 0;
static int funlist_max_size = 100;
static int funlist_size_part = 100; // o ile zwiekszac pamiec przy realloc

void put_on_fun_stack(int par_level, char *funame){
	
	fun_info_t new;
	new.usenr = malloc(100 * sizeof(*new.usenr));
	new.par_level = par_level;
	
	funstack[funstack_i] = new;
	funstack_i++;
	
	for(int i = 0; i < funlist_i; i++) {
		if(funlist[i].funame == funame) {
			break;
		}
	}

	if(i == funlist_i) {
		funlist[funlist_i] = new;
		funlist_i++;
		
		// jezeli przy dodaniu nastepnego elementu nie bylo by miejsca
		// zwieksz potrzebna przestrzen juz teraz
		if (funlist_i == funlist_max_size) {
			funlist = realloc(funlist, (funlist_max_size + funlist_size_part)*sizeof(*funlist));	
		}
	}
}

int top_of_funstack(void){

	return funstack[funstack_i].par_level;
}

char *get_from_fun_stack(void){
	
	char *name = funstack[funstack_i].funame;
	funstack_i -= 1;
	return name;
}


void store_add_def(char *funame, int ln , char *inpname){
	
	for (int i = 0; i < funlist_i; i++){
		if (funlist[i].funame == funame){
			funlist[i].defnrs = ln;
			break;
		}
	}
}

void store_add_proto(char *funame, int ln, char *inpname){

	for (int i = 0; i < funlist_i; i++){
		if (funlist[i].funame == funame){
			funlist[i].protonr = ln;
			break;
		}
	}
}

void store_add_call(char *funame, int ln, char *inpname){

	for (int i = 0; i < funlist_i; i++){
		if (funlist[i].funame == funame){
			funlist[i].usenr[funlist[i].usenr_i] = ln;
			funlist[i].usenr_i++;
		}
	}
}

