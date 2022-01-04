a.out: funstack_test.o fun_stack.o
	$(CC) $^

funstack_test.o: funstack_test.c
fun_stack.o: fun_stack.o
