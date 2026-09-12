#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t getMin(const uint64_t _i_2,const uint64_t _i_3,const uint64_t _i_5){
    if (_i_2 <= _i_3 && _i_2 <= _i_5) return _i_2;
    if (_i_3 <= _i_2 && _i_3 <= _i_5) return _i_3;
    return _i_5;
}

uint64_t hamber(int n)
{
    size_t size = 1; // Only first 15000 Hamming numbers
    uint64_t *list = calloc(size,sizeof(uint64_t));
    uint64_t *temp = NULL;
    if(!list) return 0;
    size_t index = 0;
    list[index] = 1;
    index++;
    // Aux array 
    uint64_t aux[] = {0,0,0};
    size_t i_2 = 0,i_3 = 0,i_5 = 0;
    const size_t length = 3;
    n--;
    while(n>0){
        aux[0] = list[i_2] * 2;
        aux[1] = list[i_3] * 3;
        aux[2] = list[i_5] * 5;
        const uint64_t lower = getMin(aux[0],aux[1],aux[2]);
        i_2+=(aux[0] == lower)?1:0;
        i_3+=(aux[1] == lower)?1:0;
        i_5+=(aux[2] == lower)?1:0;
        size++;
        temp = realloc(list,(size*sizeof(uint64_t)));
        if(!temp){
            free(list);
            return 0;
        }
        list = temp;
        list[index] = lower;
        index++;
        n--;
    }
    uint64_t _result = list[index-1];
    free(list);
    return _result;
}

int main(){
    printf("Resultado -> %" PRIu64 "\n", hamber(10));
    return 0;
}