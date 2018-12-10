#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long polynomial(unsigned long long constValue, int power, unsigned long long input);

int main(int argc, char* argv[]) 
{
   if (argc == 1) 
   {
      printf("Usage: ./analyse <inputsize>\n");
      abort();
   }
   
   unsigned long long n = atoi(argv[1]);
   printf("N = Number of inputs\n");
   printf("N=%llu --> 100000N --> %llu steps\n", n, polynomial(100000, 1, n)); 
   printf("N=%llu --> 100N^2 --> %llu steps\n", n, polynomial(100, 2, n)); 
   printf("N=%llu --> N^3    --> %llu steps\n", n, polynomial(1, 3, n)); 

   return EXIT_SUCCESS;
}

unsigned long long polynomial(unsigned long long constValue, int power, unsigned long long input)
{
   // constValue * (input ^ (power))
   return constValue * pow(input, power);
}

