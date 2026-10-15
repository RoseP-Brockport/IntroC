practice1: practice1.o unit_tests.o
	gcc -Wall -Wextra -o practice1 practice1.o unit_tests.o

practice1.o: practice1.c practice1.h unit_tests.h
	gcc -Wall -Wextra -c practice1.c

unit_tests.o: unit_tests.c unit_tests.h practice1.h
	gcc -Wall -Wextra -c unit_tests.c

clean:
	rm -f *.o practice1

test: practice1
	./practice1