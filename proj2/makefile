all: proj2.c
		gcc -Wall -Wextra -ansi -pedantic -o proj2 proj2.c hashtables.c listas.c

exp: hashtables_ex.c
		gcc -Wall -Wextra -ansi -pedantic -g -o hashtables_ex hashtables_ex.c

listas: listas.c listas.h
		gcc -Wall -Wextra -ansi -pedantic -o listas listas.c listas.h

hash: hash.c hash.h
		gcc -Wall -Wextra -ansi -pedantic -o hash hash.c hash.h
gdb:
		gcc -Wall -Wextra -ansi -pedantic -o proj2 proj2.c hashtables.c listas.c -g

run: p2.c
		../

run_in_terminal:
		./p2 < ../../IAED1819/projectos/p2/testes_enunciado/t0.in

compare:
		diff ../../IAED1819/projectos/p2/testes_enunciado/t0.out test.myout

test:	
		gcc -Wall -Wextra -ansi -pedantic -o p2 p2.c
		cp p2.c p2.h ../../IAED1819/projectos/p2/
		cd ../../IAED1819/projectos/p2/

zip: p2.c p2.h hash.c hash.h listas.c listas.h
		zip proj2.zip p2.c p2.h hash.c hash.h listas.c listas.h
		
clean: 
		rm p2