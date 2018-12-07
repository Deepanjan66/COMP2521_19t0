//===================================================//
// Author: Deepanjan Chakrabarty
// Data: 07/12/2018
//
// Program: Check if a string is an emordnilap
//
// A string is an emordnilap when it has even number of 
// characters and it can be read the same from both
// ends
//===================================================//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// Item here should be a char
#include "Item.h"
#include "Stack.h"

#define TRUE 1
#define FALSE 0

// Bonus: Function macros
#define LOWER(ch) ((ch >= 'A' && ch <= 'Z')? ch - 'A' + 'a' : ch)

// You can also use this function but now you know 
// how to write macros in C
char lower(char c);
bool valid(char c);
void runtests( bool (*emordnilap_func)(char*) );

// TIME COMPLEXITY O(N); SPACE COMPLEXITY: O(N)
bool is_emordnilap_imp_1(char *string);
// TIME COMPLEXITY O(N); SPACE COMPLEXITY: O(1)
bool is_emordnilap_imp_2(char *string);

int main(int argc, char* argv[]) 
{
   // Create a string and take user input
   if (argc == 1) {
      printf("No arguments provided. Running all tests\n");
      // Pass function pointers to runtests. runtests uses
      // the function pointer to call the function. So, we 
      // can use the same function to test both implementations
      runtests( is_emordnilap_imp_1 );
      runtests( is_emordnilap_imp_2 );
      printf("Passed all tests!\n");
   } else {
      // Use the string provided as argument
      // Remember to use "" when passing argument with spaces
      char *inputString = argv[1];
      printf("Checking if \"%s\" is an emordnilap\n", inputString);
      // check if emordnilap or not
      if (is_emordnilap_imp_1(inputString)) printf("\"%s\" is an emordnilap\n", inputString);
      else printf("\"%s\" is not an emordnilap\n", inputString);
   }
   
   return EXIT_SUCCESS;

}

char lower(char c) {
   if (c >= 'A' && c <= 'Z') return (c - 'A') + 'a';
   return c;
}

bool valid(char c) {
   if (c >= 'a' && c <= 'z') return TRUE;
   else if (c >= 'A' && c <= 'Z') return TRUE;

   return FALSE;
}

bool is_emordnilap_imp_1(char *string) {
   // TIME COMPLEXITY: O(N)
   // SPACE COMPLEXITY: O(N)
   // TODO: Implement algorithm with the above requirements
   return FALSE;
}

bool is_emordnilap_imp_2(char *string) {
   // TIME COMPLEXITY: O(N)
   // SPACE COMPLEXITY: O(1) because we only need 
   // TODO: Implement algorithm with the above requirements
   return FALSE;
}

void runtests( bool (*emordnilap_func)(char*) ) {
   // The argument to this function is a function pointer
   // that returns a bool and takes (char*) as argument

   // I got lazy and put them all in the same function
   // You should create separate functions for each of
   // the test cases. 
   assert(emordnilap_func("Aa") == TRUE);
   assert(emordnilap_func("AA") == TRUE);
   assert(emordnilap_func("b b b      b b b    b                            b") == TRUE);
   assert(emordnilap_func("b b         b   ###@1  ...,$! #b . ,b .  ,@ b") == TRUE);
   assert(emordnilap_func("baaaab") == TRUE);
   assert(emordnilap_func("rats live on no evil star") == TRUE);
   assert(emordnilap_func("RatS lIVe oN nO EVil StAr") == TRUE);
   assert(emordnilap_func("Hannah") == TRUE);
   assert(emordnilap_func("uHannah,,,,,,,,56576,7463524,314,356,3421,245,678,75,4321,,546576,5645342312u") == TRUE);


   assert(emordnilap_func(NULL) == FALSE);
   assert(emordnilap_func("") == FALSE);
   assert(emordnilap_func("A") == FALSE);
   assert(emordnilap_func("a") == FALSE);
   assert(emordnilap_func("AaA") == FALSE);
   assert(emordnilap_func("aAa") == FALSE);
   assert(emordnilap_func("aAa ") == FALSE);
   assert(emordnilap_func(" aAa            ") == FALSE);
   assert(emordnilap_func("Very wrong") == FALSE);
   assert(emordnilap_func("tacocat") == FALSE);
   assert(emordnilap_func("b b         b                       b       b") == FALSE);
   assert(emordnilap_func("b    , b  | < .  b   ......  @  < >      b       b") == FALSE);
   assert(emordnilap_func("                                                     ") == FALSE);
   assert(emordnilap_func(" .<          >        %     $         #      <<<<<\n   ") == FALSE);
   assert(emordnilap_func("Citation Needed") == FALSE);
   
}
