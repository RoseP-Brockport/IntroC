all: rpgcraft

rpgcraft: inventory.o recipes.o crafting.o parser.o autocraft.o main.o
	gcc -Wall -Wextra -std=c11 -g -o rpgcraft inventory.o recipes.o crafting.o parser.o autocraft.o main.o

inventory.o: inventory.c inventory.h
	gcc -Wall -Wextra -std=c11 -g -c inventory.c

recipes.o: recipes.c recipes.h
	gcc -Wall -Wextra -std=c11 -g -c recipes.c

crafting.o: crafting.c crafting.h inventory.h recipes.h
	gcc -Wall -Wextra -std=c11 -g -c crafting.c

parser.o: parser.c parser.h
	gcc -Wall -Wextra -std=c11 -g -c parser.c

autocraft.o: autocraft.c autocraft.h inventory.h crafting.h recipes.h
	gcc -Wall -Wextra -std=c11 -g -c autocraft.c

main.o: main.c inventory.h crafting.h recipes.h parser.h autocraft.h
	gcc -Wall -Wextra -std=c11 -g -c main.c

# One set of checks for each project phase

tests/test_phase1: tests/test_phase1.c inventory.o
	gcc -Wall -Wextra -std=c11 -g -I. -o tests/test_phase1 tests/test_phase1.c inventory.o

test_phase1: tests/test_phase1
	./tests/test_phase1

tests/test_phase2: tests/test_phase2.c inventory.o
	gcc -Wall -Wextra -std=c11 -g -I. -o tests/test_phase2 tests/test_phase2.c inventory.o

test_phase2: tests/test_phase2
	./tests/test_phase2

tests/test_phase3: tests/test_phase3.c inventory.o crafting.o recipes.o
	gcc -Wall -Wextra -std=c11 -g -I. -o tests/test_phase3 tests/test_phase3.c inventory.o crafting.o recipes.o

test_phase3: tests/test_phase3
	./tests/test_phase3

tests/test_inventory_full: tests/test_inventory_full.c inventory.o
	gcc -Wall -Wextra -std=c11 -g -I. -o tests/test_inventory_full tests/test_inventory_full.c inventory.o

test_inventory_full: tests/test_inventory_full
	./tests/test_inventory_full

tests/test_recipes_full: tests/test_recipes_full.c recipes.o
	gcc -Wall -Wextra -std=c11 -g -I. -o tests/test_recipes_full tests/test_recipes_full.c recipes.o

test_recipes_full: tests/test_recipes_full
	./tests/test_recipes_full

tests/test_crafting_full: tests/test_crafting_full.c inventory.o crafting.o recipes.o
	gcc -Wall -Wextra -std=c11 -g -I. -o tests/test_crafting_full tests/test_crafting_full.c inventory.o crafting.o recipes.o

test_crafting_full: tests/test_crafting_full
	./tests/test_crafting_full

tests/test_parser_full: tests/test_parser_full.c parser.o
	gcc -Wall -Wextra -std=c11 -g -I. -o tests/test_parser_full tests/test_parser_full.c parser.o

test_parser_full: tests/test_parser_full
	./tests/test_parser_full

tests/test_autocraft_full: tests/test_autocraft_full.c inventory.o recipes.o crafting.o autocraft.o
	gcc -Wall -Wextra -std=c11 -g -I. -o tests/test_autocraft_full tests/test_autocraft_full.c inventory.o recipes.o crafting.o autocraft.o

test_autocraft_full: tests/test_autocraft_full
	./tests/test_autocraft_full

# Full-program tests: feed text through stdin and save stdout.
# The small C checker only reads the saved output and expected messages.

tests/check_output: tests/check_output.c
	gcc -Wall -Wextra -std=c11 -g -o tests/check_output tests/check_output.c

test_program: rpgcraft tests/check_output
	mkdir -p tests/results
	./rpgcraft < tests/program_cases/01_basic.in > tests/results/01_basic.out
	./tests/check_output tests/results/01_basic.out tests/program_cases/01_basic.checks
	./rpgcraft < tests/program_cases/02_resize.in > tests/results/02_resize.out
	./tests/check_output tests/results/02_resize.out tests/program_cases/02_resize.checks
	./rpgcraft < tests/program_cases/03_collisions.in > tests/results/03_collisions.out
	./tests/check_output tests/results/03_collisions.out tests/program_cases/03_collisions.checks
	./rpgcraft < tests/program_cases/04_crafting.in > tests/results/04_crafting.out
	./tests/check_output tests/results/04_crafting.out tests/program_cases/04_crafting.checks
	./rpgcraft < tests/program_cases/05_failures.in > tests/results/05_failures.out
	./tests/check_output tests/results/05_failures.out tests/program_cases/05_failures.checks
	./rpgcraft < tests/program_cases/06_invalid_input.in > tests/results/06_invalid_input.out
	./tests/check_output tests/results/06_invalid_input.out tests/program_cases/06_invalid_input.checks
	./rpgcraft < tests/program_cases/07_eof.in > tests/results/07_eof.out
	./tests/check_output tests/results/07_eof.out tests/program_cases/07_eof.checks
	./rpgcraft < tests/program_cases/08_inventory.in > tests/results/08_inventory.out
	./tests/check_output tests/results/08_inventory.out tests/program_cases/08_inventory.checks
	./rpgcraft < tests/program_cases/09_many_items.in > tests/results/09_many_items.out
	./tests/check_output tests/results/09_many_items.out tests/program_cases/09_many_items.checks
	./rpgcraft < tests/program_cases/12_same_hash.in > tests/results/12_same_hash.out
	./tests/check_output tests/results/12_same_hash.out tests/program_cases/12_same_hash.checks

test_program_bonus: rpgcraft tests/check_output
	mkdir -p tests/results
	./rpgcraft < tests/program_cases/10_bonus_success.in > tests/results/10_bonus_success.out
	./tests/check_output tests/results/10_bonus_success.out tests/program_cases/10_bonus_success.checks
	./rpgcraft < tests/program_cases/11_bonus_rollback.in > tests/results/11_bonus_rollback.out
	./tests/check_output tests/results/11_bonus_rollback.out tests/program_cases/11_bonus_rollback.checks

# One executable for both required and optional extra-credit functionality.
bonus: rpgcraft

test_phases: test_phase1 test_phase2 test_phase3
test_components: test_inventory_full test_recipes_full test_crafting_full test_parser_full
test_all: test_phases test_components test_program
test_bonus: test_autocraft_full test_program_bonus
test: test_all

# Valgrind memory checks (run after Phase 2 memory cleanup is implemented)
# Requires Valgrind to be installed. No new student test code is needed.
# --error-exitcode=1 makes make fail for invalid memory accesses or tracked leaks.
# "still reachable" allocations are reported but are not treated as errors.

mem_phase2: tests/test_phase2
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./tests/test_phase2

mem_phase3: tests/test_phase3
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./tests/test_phase3

mem_inventory: tests/test_inventory_full
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./tests/test_inventory_full

mem_crafting: tests/test_crafting_full
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./tests/test_crafting_full

mem_parser: tests/test_parser_full
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./tests/test_parser_full

# Redirection feeds commands through getchar(), just as in normal testing.
# Program stdout is hidden to keep the Valgrind diagnostics easy to read.
mem_program: rpgcraft
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./rpgcraft < tests/program_cases/04_crafting.in > /dev/null
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./rpgcraft < tests/program_cases/06_invalid_input.in > /dev/null
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./rpgcraft < tests/program_cases/07_eof.in > /dev/null
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./rpgcraft < tests/program_cases/09_many_items.in > /dev/null

# Optional Master Alchemist checks: successful and unsuccessful transactions.
mem_autocraft: tests/test_autocraft_full
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./tests/test_autocraft_full

mem_program_bonus: rpgcraft
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./rpgcraft < tests/program_cases/10_bonus_success.in > /dev/null
	valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=definite,indirect,possible --track-origins=yes --error-exitcode=1 ./rpgcraft < tests/program_cases/11_bonus_rollback.in > /dev/null

mem_all: mem_phase2 mem_phase3 mem_inventory mem_crafting mem_parser mem_program
mem_bonus: mem_autocraft mem_program_bonus

clean:
	rm -f *.o rpgcraft tests/test_phase1 tests/test_phase2 tests/test_phase3 tests/test_inventory_full tests/test_recipes_full tests/test_crafting_full tests/test_parser_full tests/test_autocraft_full tests/check_output
	rm -f tests/results/*.out

.PHONY: all bonus test test_all test_phases test_components test_bonus test_phase1 test_phase2 test_phase3 test_inventory_full test_recipes_full test_crafting_full test_parser_full test_autocraft_full test_program test_program_bonus mem_phase2 mem_phase3 mem_inventory mem_crafting mem_parser mem_program mem_autocraft mem_program_bonus mem_all mem_bonus clean
