# Define placeholders for different 
# compilers and flags
CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g

CC3 = 2521 3c
CFLAGS3 = +leak

# Just running `make` will run this target
all: 
	${CC} ${CFLAGS} -o analyse.out algorithmic_complexity.c
	${CC} ${CFLAGS} -o btree.out btree.c
	${CC} ${CFLAGS} -o bsearch.out binary_search.c

# Running `make cse` will run this target
.PHONY: cse
cse:
	${CC3} ${CFLAGS3} -o analyse.out algorithmic_complexity.c
	${CC3} ${CFLAGS3} -o btree.out btree.c
	${CC3} ${CFLAGS3} -o bsearch.out binary_search.c

# Run `make clean` to delete all executables
.PHONY: clean
clean:
	rm *.out 
