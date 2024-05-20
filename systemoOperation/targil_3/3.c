#include <stdio.h>
#include <dlfcn.h>

int main() {

    void *lib = dlopen("./libpoisson.so", RTLD_LAZY);
    if (!lib) {
        printf("Error loading library!");
        return 1;
    }

    // address of the poisson function from library
    typedef double (*poisson_f)(double, int);
    
    poisson_f poisson = (poisson_f)dlsym(lib, "poisson");
    if (!poisson)
     {
        printf("Error finding func 'poisson()'");
        dlclose(lib);
        return 1;
    }

    // Calculate 5 values of poisson
    int arrK[] = {1, 10, 2, 3, 3};
    double arrLamda[] = {2, 2, 2, 3, 100};
    
    int size = sizeof(arrLamda) / sizeof(arrLamda[0]);

    for (int i = 0; i < size; i++) 
    {
        int k = arrK[i];
        double lamda = arrLamda[i];
        
        //uses a function we imported
        double possionRes = poisson(lamda, k);

        printf("Value %d: k = %d, lamda = %f, result = %f\n", i+1, k, lamda, possionRes);
    }

    // Close the library
    dlclose(lib);

    return 0;
}
