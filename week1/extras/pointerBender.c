#include <stdio.h>
#include <stdlib.h>


/*
 * Definition of a struct that contains an int value
 */
typedef struct container* Container;


// TRIVIA: Guess what the struct size is
//
// Structs on my machine are 8 bytes aligned
// On my macOS (64 bit), pointers are 8 bytes. 
// Integers are 4 bytes. Which means the total size
// of the struct is 12 bytes. if you print sizeof(struct container),
// you will notice that the size is 16 bytes. So, in my case,
// the struct will always be a mulitple of 8. Experiment
// with data types and combinations of variables in the struct
// to test this idea out
struct container {
   int val;
   Container next;
};

/*
 * Function prototypes go here
 */
Container create_container(int val);
Container create_linked_containers(int numContainers, int startingValue);
void show_addresses(Container container);
void free_list(Container container);

int main(int argc, char* argv[]) {

   Container head = create_linked_containers(10, 1);

   Container curr = head;

   while (curr != NULL) {
      show_addresses(curr);
      curr = curr->next;
   }

   free_list(head);

   return EXIT_SUCCESS;
}

Container create_container(int val) {

   Container newContainer = malloc(sizeof(*newContainer));
   newContainer->val = val;
   newContainer->next = NULL;

   return newContainer;
}

Container create_linked_containers(int numContainers, int startingValue) {

   Container head = create_container(startingValue);
   Container current = head;
   
   int i = 0;
   int currentValue = startingValue + 1;

   while (i < numContainers) { 
      current->next = create_container(currentValue);

      i++;
      current = current->next;
      currentValue++;
   }

   return head;
}

void free_list(Container container) {
   Container curr = container;
   Container prev = NULL;

   while (curr != NULL) {
      prev = curr;
      curr = curr->next;
      free(prev);
   }
}

// Get your hands dirty with actual pointer addresses and 
// see how linkedlists are actually linked
void show_addresses(Container container) {

   printf("===============================\n");
   printf("Pointer pointing to container at: %p\n", container);
   printf("Container contains: %d\n", container->val);
   printf("Pointer containing address to the next pointer: %p\n", container->next);
   printf("===============================\n");
}
