#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool validNumbersString(const char* _init,const char* _end){
    while(_init <= _end){
        size_t id = (size_t)(*(_init));
        if(id < 48 || id > 57) return false;
        _init++;
    }
    return true;
}
bool valid_phone_number(const char* number) {
    if(strlen(number) != (size_t) 14) return false;        // "??????????????"
    if(number[5] != ' ' || number[9] != '-') return false; // "????? ???-????"
    if(number[0] != '(' || number[4] != ')') return false; // "(???) ???-????"
    if(!validNumbersString((number+1),(number+3)) || !validNumbersString((number+6),(number+8)) || !validNumbersString((number+10),(number+13))) return false;
    return true;
}

int main(){
    const char* cadena = "(123) 456-7890";
    printf("%d\n",valid_phone_number(cadena));

    return EXIT_SUCCESS;
}