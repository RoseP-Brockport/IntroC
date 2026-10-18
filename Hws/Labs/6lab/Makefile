main: main.o pointer_in.o
	gcc -Wall -Wextra -o main main.o pointer_in.o

main.o: main.c pointer_in.h
	gcc -Wall -Wextra -c main.c

pointer_in.o: pointer_in.c pointer_in.h
	gcc -Wall -Wextra -c pointer_in.c

clean:
	rm -f *.o main

test: main
	./main < sample.txt