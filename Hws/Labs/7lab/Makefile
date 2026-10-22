processor: processor.o request.o main.o
	gcc -Wall -Wextra -o processor processor.o request.o main.o

processor.o: processor.c processor.h
	gcc -Wall -Wextra -c processor.c

request.o: request.c request.h processor.h
	gcc -Wall -Wextra -c request.c

main.o: main.c request.h processor.h
	gcc -Wall -Wextra -c main.c

clean:
	rm -rf *.o processor

test: processor
	./processor