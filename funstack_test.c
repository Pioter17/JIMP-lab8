#include "fun_stack.h"
#include <stdio.h>

int main(int argc, char **argv) {
	
	char *funame[256];

	init_fun_stack();

	put_on_fun_stack(0, "fa");
	put_on_fun_stack(1, "fb");	
	printf("funstack_i: %d\nfunlist_i: %d\n", get_funstack_i(), get_funlist_i());
	printf("fun on top: %s\n", get_from_fun_stack());
	printf("fun on top: %s\n", get_from_fun_stack());
	put_on_fun_stack(0, "fc");
	put_on_fun_stack(1, "fd");
	put_on_fun_stack(2, "fe");
	printf("funstack_i: %d\nfunlist_i: %d\n", get_funstack_i(), get_funlist_i());
	printf("par level on top: %d\n", top_of_funstack());	
	printf("fun on top: %s\n", get_from_fun_stack());
}
