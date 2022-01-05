a.out: alex.o parser.o fun_stack.o
	$(CC) $^


alex.o: alex.c
fun_stack.o: fun_stack.c
parser.o: parser.c
