#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;

struct node {
   int item;
   Node next;
};


Node new_node(int item);

int main(int argc, char* argv[]) 
{

   printf("===== fun with gdb =====\n");
   Node head = new_node(1);
   head->next = new_node(2);
   head->next->next = new_node(3);

   free(head->next->next);
   free(head->next);
   free(head);

   return EXIT_SUCCESS;
}

Node new_node(int item) 
{
   Node curr = malloc(sizeof(*curr));

   curr->item = item;
   curr->next = NULL;

   return curr;
}
