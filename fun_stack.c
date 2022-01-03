#include "fun_stack.h"

fun_info_t funstack[100];
fun_info_t *funlist = malloc(100 * sizeof(*funlist));
static int funstack_i = 0;
static int funlist_i = 0;
static int funlist_max_size = 100;

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

	if(i == funlist_i){
		funlist[funlist_i] = new;
		funlist_i++;
		
		if (funlist_i == funlist_max_size){
				
		}
	}
}

int top_of_funstack(void){

	return funstack[funstack_i].par_level;
}

char *get_from_fun_stack(void){
	
	// Dodanie do funlist
	funlist[funlist_i] = 

}

