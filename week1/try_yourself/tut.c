#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <err.h>

#define TRUE 1
#define FALSE 0

typedef int bool;
typedef char Item;

typedef struct node* Link;

struct node {
   Item item;
   Link next;
};

// Task1
Link node_new (Item item);
void list_insert_next (Link ls, Link node);
void free_link (Link l);

// Task 2
void list_print (Link l);
Link list_from_cstr (const char *str);
Link list_reverse (Link l);

// Implement the following functions
int length (Link l);
Link list_duplicate (Link l);

// Task 3
bool is_sorted (int *a, int n);

int main(int argc, char* arhv[]) 
{
   Link ls = list_from_cstr ("hello world!");
   Link ls2 = list_duplicate (ls);

   list_print (ls);
   list_print (ls2);
   list_print (list_reverse (ls));
   list_print (ls);
   list_print (ls2); 
   
   free_link (ls);
   free_link (ls2); 

   return EXIT_SUCCESS;
}

// Creates a new node, initialised with the item provided.
// Returns pointer to node (link).
Link node_new (Item item)
{
   // TODO
   return NULL;
}

// Insert a new node into a given non-empty list.
// The node is inserted directly after the head of the list ls.
// Examples:
// a -> NULL, c -> NULL
//
// a -> b -> NULL, c -> NULL
void list_insert_next (Link ls, Link node)
{
   // TODO
}

void list_print (Link l) 
{
   // TODO
}

Link list_from_cstr (const char *str) 
{
   // TODO
   return NULL;
}

Link list_reverse (Link l) 
{
   // TODO
   return NULL;
}

void free_link (Link l) {
   // TODO
}

int length(Link l) 
{
   // TODO
   return 0;   
}

Link list_duplicate (Link l) 
{
   // TODO
   return NULL;  
}


bool is_sorted (int *a, int n)
{
   // TODO
   return FALSE;
}
