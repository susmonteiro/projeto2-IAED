all: p2.c
		gcc -Wall -Wextra -ansi -pedantic -o p2 p2.c p2.h

gdb:
		gcc -Wall -Wextra -ansi -pedantic -o p2 p2.c -g

run: p2.c
		./p2 < ../../IAED1819/projectos/p2/testes_enunciado/t0.in > test.myout

run_in_terminal:
		./p2 < ../../IAED1819/projectos/p2/testes_enunciado/t0.in

compare:
		diff ../../IAED1819/projectos/p2/testes_enunciado/t0.out test.myout

test:	
		gcc -Wall -Wextra -ansi -pedantic -o p2 p2.c
		cp p2.c p2.h ../../IAED1819/projectos/p2/
		cd ../../IAED1819/projectos/p2/


clean: 
		rm p2