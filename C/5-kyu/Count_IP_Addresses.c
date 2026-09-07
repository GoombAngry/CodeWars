#include <inttypes.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

uint32_t getValueFromChar(const char* chain,size_t* expo){
    uint32_t s = 0;
    size_t length = strlen(chain) - 1;
    while(*(chain) != '\0'){
        s+= ((uint32_t)pow(10,length)) * (uint32_t)(*(chain) - '0');
        chain++;
        length--;
    }
    s = (*(expo) != 0)? s * (uint32_t)(pow((double)256,(double)*(expo))):s;
    *(expo)-=1;
    return s;
}

uint32_t getValueDecimal(const char *ip){
    uint32_t total = 0;
    char* iter = NULL;
    char* tmp = NULL;
    size_t size = 0,expo = 3;
    while (*(ip) != '\0')
    {
        if(*(ip) == '.'){
            tmp = realloc(iter,(size+1)*sizeof(char));
            if(!tmp){
                free(iter);
                return 0;
            } 
            iter = tmp;
            iter[size] = '\0';
            total += getValueFromChar(iter,&expo);
            free(iter);
            iter = NULL;
            tmp = NULL;
            size = 0;
        }else{
            size++;
            if(!iter){
                tmp = calloc(size,sizeof(char));
            }else{
                tmp = realloc(iter,size*sizeof(char));
            }
            if(!tmp){
                free(iter);
                return 0;
            }
            iter = tmp;
            iter[size-1] = *(ip);
        }
        ip++;
        if(*(ip) == '\0'){
            tmp = realloc(iter,(size+1)*sizeof(char));
            if(!tmp){
                free(iter);
                return 0;
            }
            iter = tmp;
            iter[size] = '\0';
            total += getValueFromChar(iter,&expo);
            free(iter);
            iter = NULL;
            tmp = NULL;
        }
    }
    return total;
}
uint32_t ips_between (const char *start, const char *end)
{
    return getValueDecimal(end) - getValueDecimal(start);
}

int main(){
    printf("%" PRIu32 "\n", ips_between("20.0.0.10","20.0.1.0"));
    return EXIT_SUCCESS;
}