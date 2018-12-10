#include <stdio.h>
#include <stdlib.h>


void initialise(int *arr, int size);
int binary_search(int *arr, int lo, int hi, int key);
int linear_search(int *arr, int size, int key);

int main(int argc, char* argv[]) 
{
   int arr[10000000];
   initialise(arr, 10000000);

   int index = binary_search(arr, 0, 10000000, 10000001);
   // int index = linear_search(arr, 10000000, 100000001);
}

void initialise(int *arr, int size) {
   int i = 0;
   for (i = 0; i < size; i++) {
      arr[i] = i + 1;
   }
}

int linear_search(int *arr, int size, int key) {
   return -1;
}

int binary_search(int *arr, int lo, int hi, int key) 
{
   return -1;
}
