//===================================//
// Written by: Deepanjan Chakrabarty
// Date: 23th November, 2018
// Last update: 27th November, 2018
// Tutorial 1 demo
//===================================//

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

int main(int argc, char* argv[]) 
{
   Link ls = list_from_cstr ("hello world!");
   Link ls2 = list_duplicate (ls);

   list_print (ls);
   list_print (ls2);
   list_print (list_reverse(ls));
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
    Link n = malloc (sizeof (*n));
    if (n == NULL)
        err (1, "couldn't allocate");
    n->item = item;
    n->next = NULL;
    return n;
}

// Insert a new node into a given non-empty list.
// The node is inserted directly after the head of the list ls.
// Examples:
// a -> NULL, c -> NULL
//
// a -> b -> NULL, c -> NULL
void list_insert_next (Link ls, Link node)
{
    assert (ls != NULL);
    assert (node != NULL);
    node->next = ls->next;
    ls->next = node;
}

void list_print (Link l) 
{
   printf("[");
   Link curr = l;

   while (curr != NULL) {
      printf("%c->", curr->item);
      curr = curr->next;
   }
   printf("NULL]\n");
}

// "hello" 
// h -> e -> l -> l -> o -> NULL
Link list_from_cstr (const char *str) 
{

   assert (str != NULL);

   if (str[0] == '\0') return NULL;

   Link head = node_new(str[0]);
   Link curr = head;

   int i;
   for (i = 1; str[i] != '\0'; i++) {
      curr->next = node_new(str[i]);
      curr = curr->next;
   }

   return head;
}

// h -> e -> l -> l -> o -> NULL
// o -> l -> l -> e -> h -> NULL
//
// return h
Link list_reverse (Link l) 
{
   if (l == NULL) return NULL;
   
   Link newHead = list_duplicate(l);
   Link prev = NULL;
   Link curr = newHead;

   while (curr != NULL) {
      Link tmp = curr->next;
      curr->next = prev;
      prev = curr;
      curr = tmp;
   }

   return prev;
}

void free_link (Link l) {
   Link curr = l;
   Link prev = NULL;

   while (curr != NULL) {
      prev = curr;
      curr = curr->next;
      free(prev);
   }
}

// Should return the length of the linkedlist
int length(Link l) 
{
   int count = 0;
   Link curr = l;

   while (curr != NULL) {
      count++;
      curr = curr->next;
   }

   return count;   
}

// Should return a duplicate linkedlist 
//(deep copy)
Link list_duplicate (Link l) 
{
   assert(l != NULL); 

   Link newL = node_new(l->item); 

   Link newCurr = newL;
   Link oldCurr = l->next;

   while (oldCurr != NULL) {
      newCurr->next = node_new(oldCurr->item);
      newCurr = newCurr->next;
      oldCurr = oldCurr->next;
   }

   return newL;
}

