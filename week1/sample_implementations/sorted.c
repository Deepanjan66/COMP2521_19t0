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
void test_sorted(void);

int main(int argc, char* argv[]) 
{
   int a[5] = {1,2,3,4,5};

   print_sorted(a, 5);
   // print_sorted(b, 5);
   test_sorted();

   return EXIT_SUCCESS;
}

void print_sorted(int *a, int n) 
{
   if (is_sorted(a, n))
      printf("The array is sorted\n");
   else
      printf("The array is not sorted\n");
}

void test_sorted() {
    int b[6] = {1,2,3,4,5,6};
    assert(is_sorted(b, 6) == TRUE);
    int a[4] = {2,1,3,4};
    assert(is_sorted(a, 4) == FALSE);
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
    int i = 0;
    for (i = 0; i < (n - 2); i++) {
        if (a[i] > a[i+1]) return FALSE; 
    }

   return TRUE;
}
