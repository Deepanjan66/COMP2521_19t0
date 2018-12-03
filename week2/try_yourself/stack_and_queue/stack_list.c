////////////////////////////////////////////////////////////////////////
// COMP2521 19T0 -- A Stack ADT implementation, using arrays.
//
// 2018-11-29	Jashank Jeremy <jashankj@cse.unsw.edu.au>
// YYYY-mm-dd   Your Name Here <zNNNNNNN@student.unsw.edu.au>

#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

#include "item.h"
#include "stack.h"
#include "testable.h"

#define DEFAULT_SIZE 10

typedef struct stack stack;

struct stack {
};

// Add extra structs

/** Create a new, empty Stack. */
stack *stack_new (void)
{
}

/** Destroy a Stack. */
void stack_drop (stack *s)
{
}

/** Add an item to the top of a Stack. */
void stack_push (stack *s, Item it)
{
}

/** Remove an item from the top of a Stack. */
Item stack_pop (stack *s)
{
}

/** Get the number of items in a Stack. */
size_t stack_size (stack *s)
{
}

void white_box_tests (void)
{
	// ... you need to write these!
}
