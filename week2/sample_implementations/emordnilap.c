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
   //                  One O(N) pass to find the size of the array
   //                  One O(N/2) =~ O(N) pass to push characters on to the stack
   //                  One O(N/2) =~ O(N) pass to pop from the stack and check if emordnilap
   // SPACE COMPLEXITY: O(N)
   //                   We need to store at least O(N/2) =~ O(N) characters in the stack
   if (string == NULL) return FALSE;
   // Find number of valid characters in the string
   size_t count = 0;
   size_t i = 0;

   for (i = 0; string[i] != '\0'; i++) {
      if (valid(string[i])) count++;
   }

   // If odd number of valid characters exist, return FALSE
   // as emordnilaps have to have even number of characters
   if (count % 2 != 0 || count == 0) return FALSE;
   
   // Create a new stack for storing characters
   Stack newStack = stack_new();
   // Now, put everything upto count/2 in the stack
   size_t mid = (count / 2);
   i = 0;
   size_t currCount = 0;
   // while the number of valid characters seen so far is less
   // than half of the total number of valid characters
   while (currCount < mid) {
      if (valid(string[i])) {
         currCount++;
         stack_push(newStack, string[i]);
      }
      i++;
   }
   
   // Intialise a flag with TRUE. This will be
   // used in determining if the string is an
   // emordnilap later.
   bool flag = TRUE;
   // i from the previous loop should already have
   // the next index we have to start looking from
   while (currCount < count) {
      if (!valid(string[i])) {
         i++;
         continue;
      }
      Item ch = stack_pop(newStack);

      // printf("%c and %c\n", LOWER(ch), LOWER(string[i]));
      if (LOWER(ch) != LOWER(string[i])) {
         //printf("%c and %c don't match\n", LOWER(ch), LOWER(string[i]));
         flag = FALSE;
         break;
      }
      currCount++;
      i++;
   }
   
   stack_drop(newStack);

   return flag;
}

bool is_emordnilap_imp_2(char *string) {
   // TIME COMPLEXITY: O(N)
   //                  1. One O(N) pass to calculate string size
   //                  2. Another O(N) pass to check if emordnilap
   // SPACE COMPLEXITY: O(1) because we only need 
   //                   constant space for the counters

   if (string == NULL) return FALSE;

   size_t left = 0;
   size_t right = strlen(string);
   if (right == 0) return FALSE;

   size_t count = 0;

   while (left <= right) {
      // If the left character is not valid, move right
      if (!valid(string[left])) left++;
      // If the right character is not valid, move left 
      else if (!valid(string[right])) right--;
      // if the two characters are not equal, we can
      // safely return FALSE. Early return is fine as
      // we don't have anything to free
      else if (LOWER(string[left]) != LOWER(string[right])) return FALSE;
      else {
         // If i and j are not the same, we have
         // seen two new characters
         count += (left == right)? 1 : 2;
         // Update counters
         left++;
         right--;
      }
   }
   
   // If odd number of characters or if string has no valid characters
   // return false
   if (count % 2 != 0 || count == 0) return FALSE;
   // We have now established that we have the even number of characters
   // and that one half can be reversed to equal the other half of the string
   return TRUE;
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
