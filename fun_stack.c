#include "fun_stack.h"
#include <stdlib.h>
#include <string.h>


fun_info_stack_t funstack[100];
fun_info_t **funlist;
static int funstack_i = 0;
static int funlist_i = 0;
static int funlist_max_size = 2;
const int funlist_size_part = 2; // o ile zwiekszac pamiec przy realloc


int get_funlist_i(void) {
	return funlist_i;
}
int get_funstack_i(void) {
	return funstack_i;
}


void init_fun_stack( void ) {
	funlist = malloc(2 * sizeof(**funlist));
}


void put_on_fun_stack(int par_level, char *funame){
	
	fun_info_stack_t new;
	new.par_level = par_level;
	strcpy(new.funame, funame);
		
	funstack[funstack_i] = new;
	funstack_i++;
	
	int i = 0;	
	for(i = 0; i < funlist_i; i++) {
		if(funlist[i]->funame == funame) {
			break;
		}
	}
      

	if(i == funlist_i) {

		fun_info_t new2;
		strcpy(new2.funame, funame);
		new2.usenr = malloc(100 * sizeof (*new2.usenr));
		new2.usenr_i = 0;
		new2.protonr = -1;
		new2.defnrs = -1;
		new2.defnrk = -1;

		funlist[funlist_i] = &new2;
		funlist_i++;
		
		// jezeli przy dodaniu nastepnego elementu nie bylo by miejsca
		// zwieksz potrzebna przestrzen juz teraz
		if (funlist_i == funlist_max_size) {
			funlist_max_size += funlist_size_part;
			funlist = realloc(funlist, funlist_max_size*sizeof(*funlist));	
		}
	}
}

int top_of_funstack(void){

	return funstack[funstack_i-1].par_level;
}

char *get_from_fun_stack(void){
	
	funstack_i -= 1;
	char *name = funstack[funstack_i].funame;
	return name;
}


void store_add_def(char *funame, int ln , char *inpname){
	
	for (int i = 0; i < funlist_i; i++){
		if (funlist[i]->funame == funame){
			funlist[i]->defnrs = ln;
			break;
		}
	}
}

void store_add_proto(char *funame, int ln, char *inpname){

	for (int i = 0; i < funlist_i; i++){
		if (funlist[i]->funame == funame){
			funlist[i]->protonr = ln;
			break;
		}
	}
}

void store_add_call(char *funame, int ln, char *inpname){

	for (int i = 0; i < funlist_i; i++){
		if (funlist[i]->funame == funame){
			funlist[i]->usenr[funlist[i]->usenr_i] = ln;
			funlist[i]->usenr_i++;
			break;
		}
	}
}

