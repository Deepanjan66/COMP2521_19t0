# Define placeholders for different 
# compilers and flags
CC = gcc
CFLAGS = -Wall -Werror -std=c11 -g

CC3 = 2521 3c
CFLAGS3 = +leak

# Just running `make` will run this target
all: 
	${CC} ${CFLAGS} -o exec.out tut.c
	${CC} ${CFLAGS} -o loop.out forexample.c
	${CC} ${CFLAGS} -o sorted.out sorted.c

# Running `make cse` will run this target
.PHONY: cse
cse:
	${CC3} ${CFLAGS3} -o exec.out tut.c
	${CC3} ${CFLAGS3} -o loop.out forexample.c
	${CC3} ${CFLAGS3} -o sorted.out sorted.c

# Run `make clean` to delete all executables
.PHONY: clean
clean:
	rm *.out 
