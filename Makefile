connectn.out: main.o win.o board.o gameplay.o input_validation.o
	gcc -g -Wall -Werror -o connectn.out main.o win.o board.o gameplay.o input_validation.o

main.o:main.c gameplay.h board.h win.h
	gcc -g -Wall -Werror -c main.c

win.o: win.c win.h
	gcc -g -Wall -Werror -c win.c

board.o: board.c board.h input_validation.h
	gcc -g -Wall -Werror -c board.c

gameplay.o: gameplay.c gameplay.h board.h win.h
	gcc -g -Wall -Werror -c gameplay.c

input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c

clean:
	rm -rf *.o *.out