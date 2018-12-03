////////////////////////////////////////////////////////////////////////
// COMP2521 19T0 -- A Queue ADT implementation, using arrays.

#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

#include "item.h"
#include "queue.h"
#include "testable.h"

#define DEFAULT_SIZE 10

typedef struct queue queue;

struct queue {
};

/** Create a new, empty Stack.  $ O(1) $. */
queue *queue_new (void)
{
}

/** Destroy a Queue.  $ O(1) $. */
void queue_drop (queue *q)
{
}


/** Add an item to the end of a Queue.  $ O(1) $.
 * Sometimes referred to as "enqueue" or "unshift". */
void queue_en (queue *q, Item it)
{
}

/** Remove an item from the front of a Queue.  $ O(n) $.
 * Sometimes referred to as "dequeue" or "shift". */
Item queue_de (queue *q)
{
}

/** Get the number of items in a Queue.  $ O(1) $. */
size_t queue_size (queue *q)
{
}

void white_box_tests (void)
{
	// ... you need to write these!
}
