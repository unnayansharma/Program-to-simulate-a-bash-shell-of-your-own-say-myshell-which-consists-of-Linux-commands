all : Assignment.o
	gcc Assignment.o -lreadline
Assignment.o : Assignment.c
	gcc -c Assignment.c -lreadline 	
