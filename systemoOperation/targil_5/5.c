#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINUS -70

// A function to calculate the maximum complexity subseries operations O(n^3)
int maxSubArrAlgo3(int a[], int size) {
    int maxSum = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    printf("algo 3 %d\n",maxSum);
    return maxSum;
}

// A function to calculate the maximum complexity subseries operations O(n^2)
int maxSubArrAlgo2(int a[], int size) {
    int maxSum = 0;
    for (int i = 0; i < size; i++) {
        int sum = 0;
        for (int j = i; j < size; j++) {
            sum += a[j];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
     printf("algo 2 %d \n",maxSum);
    return maxSum;
}

// A function to calculate the maximum complexity subseries operations O(n)
int maxSubArrAlgo1(int a[], int size) {
    int maxSum = 0;
    int sum = 0;
    
    for (int k = 0; k < size; k++)
    {
        if(a[k] > sum+a[k])
        {
            sum = a[k];
        }
        else
        {
            sum= sum + a[k];
        }

        if (sum > maxSum) 
        {
            maxSum = sum;
        }
    }

    printf("algo 1 %d \n",maxSum);
    return maxSum;
}

// A function to create a random array
void generateRandomArray(int a[], int size, int seed) {
    srand(seed);
    for (int i = 0; i < size; i++) {
        a[i] = rand() % (seed - MINUS + 1) + MINUS;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error- invalid input\n");
        return 1;
    }

    int seed = atoi(argv[1]);
    if(seed < 0)
    {
        printf("Error- you need to input possitve value of seed\n");
        return 1;
    }
    int size = atoi(argv[2]);
    if(size < 0)
    {
        printf("Error- you need to input possitve value of size array\n");
        return 1;
    }
    int* a = (int*)malloc(size * sizeof(int));

    generateRandomArray(a, size, seed);

    // printf("[");
    // for (int i = 0; i < size; i++) {
    //     printf("%d", a[i]);
    //     if (i < size - 1) {
    //         printf(", ");
    //     }
    // }
    // printf("]\n");
    
    maxSubArrAlgo1(a,size);
    maxSubArrAlgo2(a,size);
    maxSubArrAlgo3(a,size);


    free(a);
    return 0;
}