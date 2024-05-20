#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//calculate the poisson
double poisson(double lamda, int k) 
{
    return (expf(-lamda) * pow(lamda, k)) / tgamma(k + 1);
}

