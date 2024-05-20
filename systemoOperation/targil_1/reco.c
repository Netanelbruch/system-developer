#include <stdio.h>

void infiniteRecursion() {

    infiniteRecursion();
}

int main() {
    infiniteRecursion();
    return 0;
}
