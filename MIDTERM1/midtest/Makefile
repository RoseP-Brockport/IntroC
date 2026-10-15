midterm: midterm.o unit_tests.o
	gcc -Wall -Wextra -o midterm midterm.o unit_tests.o

midterm.o: midterm.c midterm.h unit_tests.h
	gcc -Wall -Wextra -c midterm.c

unit_tests.o: unit_tests.c unit_tests.h midterm.h
	gcc -Wall -Wextra -c unit_tests.c

clean:
	rm -f *.o midterm

test: midterm
	./midterm