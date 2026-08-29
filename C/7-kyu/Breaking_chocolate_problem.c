#include <stdint.h>
#include <stdio.h>
uint32_t breaking_chocolate(uint32_t n, uint32_t m){
    if(n == ((uint32_t)(0)) || m == ((uint32_t)(0)) ) return 0;
    if(n == m) return ((n*m)-1);
    return ((n - ((uint32_t)(1))) + ((m - ((uint32_t)(1))) * n));
}

int main(){
    uint32_t n = (uint32_t)3;
    uint32_t m = (uint32_t)5;

    printf("Result -> %d\n",breaking_chocolate(n,m));
    return 0;
}