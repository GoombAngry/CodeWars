#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *add(const char *a, const char *b) {

    if(strlen(a) == 0 || strlen(b) == 0) return NULL;

    char* total = NULL;
    char* tmp = NULL;
    size_t size = 0;
    int a_i = strlen(a)-1, b_i = strlen(b)-1;
    unsigned acum = 0,iter = 0;
    unsigned a_iter = 0, b_iter = 0;
    while (a_i >= 0 || b_i >= 0)
    {

        size++;
        if(!total){
            total = calloc(size,sizeof(char));
            if(!total) return NULL;
        }else{
            tmp = realloc(total,size*sizeof(char));
            if(!tmp){
                free(total);
                return NULL;
            }
            total = tmp;
        }
        
        a_iter = (a_i >= 0)?(unsigned)(a[a_i] - '0'):0;
        b_iter = (b_i >= 0)?(unsigned)(b[b_i] - '0'):0;
        iter = a_iter + b_iter + acum;
        if((a_i == 0 && b_i == 0) || (a_i == 0 && b_i < 0) || (b_i == 0 && a_i < 0)){
            if(iter > 9){
                total[size-1] = iter%10 + '0';
                iter/=10;
                while(iter!=0){
                    size++;
                    tmp = realloc(total,size*sizeof(char));
                    if(!tmp){
                        free(total);
                        return NULL;
                    }
                    total = tmp;
                    total[size-1] = iter%10 + '0';
                    iter/=10;
                }    
            }else{
                total[size-1] = iter%10 + '0'; 
            }   
        }else{
            if( iter > 9){
                acum = iter / 10;
                iter %= 10;
            }else{
                acum = 0;
            }
            total[size-1] = iter%10 + '0';  
        }


        if(a_i >= 0) a_i--;
        if(b_i >= 0) b_i--;
    }


    size++;
    tmp = realloc(total,size*sizeof(char));
    if(!tmp){
        free(total);
        return NULL;
    }
    total = tmp;
    total[size-1] = '\0';

    char* copy = calloc(strlen(total)+1,sizeof(char));
    if(!copy){
        free(total);
        return NULL;
    }
    size_t i_i = 0;
    memcpy(copy,total,strlen(total)+1); 

    for (int i = strlen(copy)-1; i >= 0; i--)
    {
        total[i_i] = copy[i];
        i_i++;
    }
    free(copy);
    
    return total;    
}


int main(){
    char* r = add("123456","123");
    printf("Resultado -> %s\n",r); // A + B
    free(r);

    return EXIT_SUCCESS;
}



