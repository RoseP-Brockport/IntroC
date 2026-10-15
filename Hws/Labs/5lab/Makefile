main: main.o colors.o
	gcc -Wall -Wextra -o main main.o colors.o
main.o: main.c colors.h
	gcc -Wall -Wextra -c main.c
colors.o: colors.c colors.h
	gcc -Wall -Wextra -c colors.c

clean:
	rm -f *.o main

test: main
	./main < inputs1.txt