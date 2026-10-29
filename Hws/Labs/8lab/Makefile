log: log.o main.o
	gcc -Wall -Wextra -o log log.o main.o

log.o: log.c log.h
	gcc -Wall -Wextra -c log.c

main.o: main.c log.h
	gcc -Wall -Wextra -c main.c

clean:
	rm -f log *.o

test: log
	valgrind --leak-check=full ./log < one.txt
	valgrind --leak-check=full ./log < two.txt
	valgrind --leak-check=full ./log < three.txt
	valgrind --leak-check=full ./log < four.txt
	valgrind --leak-check=full ./log < five.txt
	valgrind --leak-check=full ./log < six.txt

test_one: log
	valgrind --leak-check=full ./log < one.txt

test_two: log
	valgrind --leak-check=full ./log < two.txt

test_three: log
	valgrind --leak-check=full ./log < three.txt

test_four: log
	valgrind --leak-check=full ./log < four.txt

test_five: log
	valgrind --leak-check=full ./log < five.txt

test_six: log
	valgrind --leak-check=full ./log < six.txt