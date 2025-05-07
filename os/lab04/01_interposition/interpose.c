#include <stdio.h>

// Original function name is prefixed with '__real_' by --wrap
extern void __real_fred();

// Wrapper function
void __wrap_fred() {
    printf("Interposing fred: Before calling real fred\n");
    __real_fred(); // Call the original fred
    printf("Interposing fred: After calling real fred\n");
}