#include <stdio.h>

int main() {
    int *undefinedMemory;
    *undefinedMemory = 10; 
   
    return 0;
}