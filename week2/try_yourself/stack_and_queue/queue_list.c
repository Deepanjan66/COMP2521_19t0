////////////////////////////////////////////////////////////////////////
// COMP2521 19T0 -- A Queue ADT implementation, using linked lists.
//
// 2018-12-01	Jashank Jeremy <jashankj@cse.unsw.edu.au>
// YYYY-mm-dd	Your Name Here <zNNNNNNN@student.unsw.edu.au>

#include <assert.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>

#include "item.h"
#include "queue.h"
#include "testable.h"

typedef struct queue queue;
typedef struct queue_node queue_node;

struct queue {
};

// Add extra structs as required


/** Create a new, empty Queue. */
queue *queue_new (void)
{
}

/** Destroy a Queue, releasing all resources associated with it. */
void queue_drop (queue *q)
{
}

/** Add an item to the end of a Queue.
 * Sometimes referred to as "enqueue" or "unshift". */
void queue_en (queue *q, Item it)
{
}

/** Remove an item from the front of a Queue.
 * Sometimes referred to as "dequeue" or "shift". */
Item queue_de (queue *q)
{
}

/** Get the number of items in a Queue. */
size_t queue_size (queue *q)
{
}

void white_box_tests (void)
{
	// ... you need to write these!
}
