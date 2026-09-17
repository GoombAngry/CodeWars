#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
bool alphanumeric(const char *str_in) {
    if(strlen(str_in) == 0) return false;
    while(*(str_in) != '\0'){
        char iter = *(str_in);
        if(iter < '0' || (iter > '9' && iter < 'A') || (iter > 'Z' && iter < 'a') || iter > 'z') return false;
        str_in++;
    }
    return true;
}

int main(){
    printf("Resultado -> %s\n",(alphanumeric("hello_world"))?"True":"False");
    printf("Resultado -> %s\n",(alphanumeric("PassW0rd"))?"True":"False");
    printf("Resultado -> %s\n",(alphanumeric(""))?"True":"False");

    return EXIT_SUCCESS;
}