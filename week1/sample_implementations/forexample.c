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

int main(int argc, char* argv[]) {

   char ch;
   // Write an equivalent while loop for this for loop
   for (ch = getchar (); ch != EOF; ch = getchar ()) {
       putchar (ch);
   }

   return EXIT_SUCCESS;
}
