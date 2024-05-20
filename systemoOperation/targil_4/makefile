CC = gcc
CFLAGS = -Wall -Wextra -fprofile-arcs -ftest-coverage

# Your main target
main: main.c
	$(CC) $(CFLAGS) -o $@ $<

# Target for setting execute permissions for test.sh
set_permissions:
	chmod +x test.sh

# Target for running the tests
test: set_permissions
	./test.sh

# Target for generating coverage report for your program
coverage:
	gcov main.c

# Target for generating coverage report for your tests
test_coverage: test
	gcov main.c

clean:
	rm -f main *.gcov *.gcda *.gcno 

.PHONY: test clean coverage test_coverage set_permissions
