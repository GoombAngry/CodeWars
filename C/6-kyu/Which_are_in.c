#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a,const void* b ){
    return strcmp(*(char**)a,*(char**)b);
}

const char **inArray(
    const char *const array1[/* sz1 */], int sz1,
    const char *const array2[/* sz2 */], int sz2,
    int *lg
) {
    *lg = 0;
    const char** result = malloc(sz1*sizeof(char*));
    if(result == NULL) return NULL;

    for (size_t i = 0; i < (size_t)sz1; i++) // Recorre array1
    {
        size_t range = strlen(array1[i]);
        int next = 0;
        for (size_t x = 0; x < sz2; x++) // Recorre array2
        {       
            if(strlen(array2[x]) < strlen(array1[i])) continue;
            // Comprobara palabra
            for (size_t p = 0; p <= (strlen(array2[x]) - range) ; p++)
            {
                if(strncmp(array2[x]+p,array1[i],range) == 0){
                    *lg+=1;
                    result[*(lg)-1] = array1[i];
                    next = 1;
                    break;
                }
                
            }
            if(next == 1) break; // Next word array1
        }
    }
    qsort(result,*(lg),sizeof(char*),compare);
    return result; // return a free-able pointer
}

int main(){
    const char* array1[] = {"arp", "live", "strong"};
    int sz1 = sizeof(array1) / sizeof(array1[0]);
    const char* array2[] = {"lively", "alive", "harp", "sharp", "armstrong"};
    int sz2 = sizeof(array2) / sizeof(array2[0]);
    int length = 0;
    printf("Array1 Size -> %d\n",sz1);
    printf("Array2 Size -> %d\n",sz2);

    inArray(array1,sz1,array2,sz2,&length);

    return 0;
}