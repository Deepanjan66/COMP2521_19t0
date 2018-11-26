#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char* numToDay(int n) {
    assert (n >= 0 && n < 7); 

    char* days[7] = {
                        "Sun",
                        "Mon",
                        "Tue",
                        "Wed",
                        "Thu",
                        "Fri",
                        "Sat"
                    };

    return days[n];
}

int main(int argc, char* argv[]) {
    printf("%d is %s\n", 4, numToDay(4));

    // char* name = (0)? "Hello" : "Bye";
    // printf("%s\n", name);

    return EXIT_SUCCESS;
    
}
