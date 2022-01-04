#include "fun_stack.h"
#include <stdio.h>

int main(int argc, char **argv) {
	
	char *funame[256];

	put_on_funstack(0, "fa");
	put_on_funstack(1, "fb");	
	printf("fun on top: %s\n", get_from_funstack());
	printf("fun on top: %s\n", get_from_funstack());
	put_on_funstack(0, "fc");
	printf("par level on top: %d\n", top_of_funstack());	
	printf("fun on top: %s\n", get_from_funstack());
}
