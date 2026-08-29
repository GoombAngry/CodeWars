#include <stddef.h>
#include <stdio.h>

int find_outlier(const int values[/* count */], size_t count)
{
    if( count < ((size_t)(3)) ) return 0;
    int  c_par = 0, c_impar = 0;
    for (size_t i = 0; i < count; i++)
    {
        int iter = (values[i] >= 0)?values[i]:values[i]*-1;
        (iter == 0 || iter % 2 == 0)?c_par++:c_impar++;
        unsigned char flag = (c_par > 1 && c_impar == 1)?1:(c_impar > 1 && c_par == 1)?2:0; // - 1 Impar - 2 Par - 0 Nada
        if(flag != 0){
            for (size_t x = i; x >= 0; x--)
            {
                int iter_2 = (values[x] >= 0)?values[x]:values[x]*-1;
                if(flag == 1 && iter_2 % 2 != 0) return values[x];
                if(flag == 2 && iter_2 % 2 == 0) return values[x];
            }
            
        } 
    }
}

int main(){
    const int lista[] = {160, 3, 1719, 19, 11, 13, -21};
    size_t size = sizeof(lista) / sizeof(lista[0]);
    printf("%d\n",find_outlier(lista,size)); 
    return 0;
}