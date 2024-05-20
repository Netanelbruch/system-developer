#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//calculate the poisson
long double poisson(double lamda, int k) 
{
    return (expf(-lamda) * pow(lamda, k)) / tgamma(k + 1);
}

// argv[1] = lamda
// argv[2] = k
int main(int argc, char** argv) {
    
    if (argc != 3) 
    {
        printf("Error- invalid args\n");
        return 1; 
    }
    
    double lamda = strtod(argv[1], NULL); // Convert argv[1] to double
    if(lamda <= 0)
    {
        printf("Error- invalid lamda, need to be lamda > 0\n");
        return 1; 
    }
    printf("Lamda = %f\n", lamda);

    if (strchr(argv[2],'.'))
    {
        printf("Error- invalid k, need to be only integer >= 0\n");
        return 1; 
    }

    int k = atoi(argv[2]);
    if(k < 0)
    {
        printf("Error- invalid k, need to be k >= 0\n");
        return 1; 
    }
    printf("k = %d\n", k);

    printf("Poisson distribution for k = %d and lamda = %f: %Lf\n", k, lamda, poisson(lamda, k));

    return 0;
}
