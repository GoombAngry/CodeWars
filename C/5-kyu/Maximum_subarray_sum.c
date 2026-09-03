#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>

int maxSequence(const int array[/* n */], size_t n) {
    if(n == (size_t)0) return 0;
    int sum_total = 0,iter = 0;
    for (size_t i = 0; i < n; i++)
    {
        if(array[i] > 0){
                iter = 0;
                for (size_t x = i; x < n; x++)
                {
                    iter+=array[x];
                    if(iter > sum_total) sum_total = iter;
                }
        }
    }
    
    return sum_total;
}
int main(){
    const int arreglo[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    size_t s = sizeof(arreglo) / sizeof(arreglo[0]);
    printf("Resultado -> %d\n",maxSequence(arreglo,s));

    return EXIT_SUCCESS;
}