#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <err.h>

#define TRUE 1
#define FALSE 0

typedef int bool;
// Task 3
bool is_sorted (int *a, int n);
void print_sorted(int *a, int n);

int main(int argc, char* arhv[]) 
{
   int a[5] = {1,2,3,4,5};
   int b[5] = {3,2,6,3,1};

   print_sorted(a, 5);
   print_sorted(b, 5);

   return EXIT_SUCCESS;
}

// Given an array of length n,
// return TRUE if the array is sorted
// in ascending order and FALSE otherwise
// You can have consequtive equal numbers
// Hence, 1,1,2,2,3,3,3,4,5,6 is a sorted
// array
bool is_sorted (int *a, int n)
{
   // TODO
   return FALSE;
}

void print_sorted(int *a, int n) 
{
   if (is_sorted(a, n))
      printf("The array is sorted\n");
   else
      printf("The array is not sorted\n");
}
