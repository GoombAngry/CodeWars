#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

size_t lengthNumber(size_t n){

    if(n < (size_t)10) return (size_t)1;

    size_t length = 0;
    while(n / (size_t)10 != (size_t) 0){
        n /= (size_t)10;
        length++;
    }
    length++;

    return length;
}

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
        strcpy(result,"no one likes this");
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
        char* numbers = NULL;
        if(rest < 10){  // 1 solo digito sobre el total
            numbers = malloc(2); // 2 bytes (null byte incluido) 
            if(!numbers) return NULL;
            numbers[0] = (char) (rest+48);
            numbers[1] = '\0';
        }else{
            size_t iter = 0;
            size_t divsor = (size_t)(pow((size_t)10,lengthNumber(rest) - 1 ));
            while(rest / divsor != (size_t)0){
                iter++;
                numbers = realloc(numbers,(iter*sizeof(char)));
                if(!numbers) return NULL;
                numbers[iter-1] =(char)((rest / divsor)+(size_t)48);
                rest %= divsor;
                divsor = (size_t)(pow((size_t)10,lengthNumber(rest)));
            }
            iter+=2;
            numbers = realloc(numbers,(iter*sizeof(char)));
            if(!numbers) return NULL;
            numbers[iter-2] = (char)(rest+(size_t)48);
            numbers[iter-1] = '\0';
        }
        total = strlen(names[0]) + strlen(names[1]) + strlen(numbers) + (size_t) 25;
        result = calloc(total,sizeof(char));
        if(!result) return NULL;
        snprintf(result,total,"%s, %s and %s others like this",names[0],names[1],numbers);
        return result;
    }
}

int main(){
    const char* const cadena[] = {"Alex", "Jacob", "Mark","Pep","Pep","Pep","Pep","Pep","Pep","Pep","Pep","Pep","Pep","Pep"};
    size_t size = sizeof(cadena) / sizeof(cadena[0]);
    printf("Resultado -> [%s]\n",likes(size,cadena));
    
    return EXIT_SUCCESS;
}