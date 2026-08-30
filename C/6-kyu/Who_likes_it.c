#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char *likes(size_t n, const char *const names[]) {
    char* result = NULL;
    size_t total;
    /*
        []                                -->  "no one likes this"
        ["Peter"]                         -->  "Peter likes this"
        ["Jacob", "Alex"]                 -->  "Jacob and Alex like this"
        ["Max", "John", "Mark"]           -->  "Max, John and Mark like this"
        ["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others like this"
    */
    if(n == 0){
        result = malloc(18);
        if(!result) return NULL;
        snprintf(result,18,"no one likes this");
        return result;
    } 
    if(n == 1){
        total = strlen(names[0]) + (size_t)12;
        result = calloc(total,sizeof(char)); // Reservamos los bytes (mas el null byte)
        if(!result) return NULL;
        snprintf(result,50,"%s likes this",names[0]); 
        return result;

    }
    else if(n == 2){
        total = strlen(names[0]) + strlen(names[1]) + (size_t)16;
        result = calloc(total,sizeof(char)); // Reservamos los bytes (mas el null byte)
        if(!result) return NULL;
        snprintf(result,total,"%s and %s like this",names[0],names[1]);
        return result;

    }else if (n == 3){
        total = strlen(names[0]) + strlen(names[1]) + strlen(names[2]) + (size_t)18;
        result = calloc(total,sizeof(char)); // Reservamos los bytes (mas el null byte)
        if(!result) return NULL;
        snprintf(result,total,"%s, %s and %s like this",names[0],names[1],names[2]);
        return result;
    }else{
        size_t rest = n - 2;
        size_t lengthNumber = 1;
        while(rest % ((size_t)pow(10,lengthNumber)) != rest) lengthNumber++;
        total = strlen(names[0]) + strlen(names[1]) + lengthNumber + (size_t) 25;
        result = calloc(total,sizeof(char));
        if(!result) return NULL;
        snprintf(result,total,"%s, %s and %zu others like this",names[0],names[1],rest);
        return result;
        
    }
}

int main(){
    const char* const cadena[] = {"Alex", "Jacob", "Mark","Pep"};
    size_t size = sizeof(cadena) / sizeof(cadena[0]);
    printf("Resultado -> [%s]\n",likes(size,cadena));
    
    return EXIT_SUCCESS;
}