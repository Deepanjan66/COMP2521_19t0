#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

typedef int Item;
typedef struct btree_node btree_node;

struct btree_node {
	Item item;
	btree_node *left;
	btree_node *right;
};


bool btree_search_iter (btree_node *tree, Item key);
btree_node* new_node(Item);
int btree_sum (btree_node *tree);
void btree_prefix(btree_node *tree);
void btree_postfix(btree_node *tree); 
void btree_infix(btree_node *tree); 
bool btree_search_iter (btree_node *tree, Item key);
bool btree_search_rec (btree_node *tree, Item key); 
btree_node* insert(btree_node* tree, Item item);


int main(int argc, char* argv[]) 
{
   btree_node* root = insert(NULL, 10);
   root = insert(root, 20);
   root = insert(root, 5);
   root = insert(root, 30);
   root = insert(root, 15);
   root = insert(root, 25);
   root = insert(root, 24);
   
   // very basic test cases for demo

   Item sum = btree_sum(root);
   assert(sum == 129);

   printf("prefix: ");
   btree_prefix(root);
   printf("\n");
   printf("postfix: ");
   btree_postfix(root);
   printf("\n");
   printf("infix: ");
   btree_infix(root);
   printf("\n");


   assert(btree_search_iter(root, 20) == TRUE); 
   assert(btree_search_iter(root, 15) == TRUE); 
   assert(btree_search_iter(root, 39) == FALSE); 

   assert(btree_search_rec(root, 20) == TRUE); 
   assert(btree_search_rec(root, 15) == TRUE); 
   assert(btree_search_rec(root, 39) == FALSE); 

   return EXIT_SUCCESS;
}

btree_node* new_node(Item item)
{
   btree_node* node = malloc(sizeof(btree_node));
   node->item = item;
   node->left = NULL;
   node->right = NULL;

   return node;
}

void do_something(btree_node* tree)
{
   printf("%d ", tree->item);
}

void btree_prefix(btree_node *tree) 
{
   // NLR
}

void btree_postfix(btree_node *tree) 
{
   // LRN
}

void btree_infix(btree_node *tree) 
{
   // LNR
}

int btree_sum (btree_node *tree) 
{
   return 0;
}

bool btree_search_iter (btree_node *tree, Item key) 
{
   return FALSE;
}

bool btree_search_rec (btree_node *tree, Item key) 
{
   return FALSE;
}

btree_node* insert(btree_node* tree, Item item) 
{
   return NULL;
}
