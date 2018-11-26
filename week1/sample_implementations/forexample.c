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
