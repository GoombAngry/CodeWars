#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char *alphabet_position(const char *text) {
    if(!text || *(text) == '\0' ) return NULL;
    char* result = NULL;
    size_t length = 0;
    while(*(text) != '\0'){
        unsigned char iter = *(text);
        unsigned char positionAlphabet = (iter >= 65 && iter <= 90 )?((iter - 65) + 1):(iter >= 97 && iter <= 122)?((iter - 97) + 1):0;
        if(positionAlphabet != 0){

            if(length > 0){
                length++;
                result = realloc(result,(length*sizeof(char)));
                result[length-1] = ' ';
            }

            if((positionAlphabet >= 1 && positionAlphabet <= 9)){ // 1 - digit
                length++;
                result = realloc(result,(length*sizeof(char)));
                result[length-1] = (unsigned char)(48 + positionAlphabet);
            }else{ // 2 - digit
                length+=2;
                result = realloc(result,(length*sizeof(char)));
                result[length-2] = (unsigned char)(48 + positionAlphabet / (unsigned char)10);
                result[length-1] = (unsigned char)(48 + positionAlphabet % (unsigned char)10);
            }        
        }
        text++;
    }
    length++;
    result = realloc(result,(length*sizeof(char)));
    result[length-1] =  '\0';

  return result;
}

int main(){
    char* result = alphabet_position("The sunset sets at twelve o' clock.");
    if(result != NULL){
        char* iter = result;
        while(*(iter) != '\0'){
            printf("%c",*(iter));
            iter++;
        }
    }else{
        printf("Nulo!\n");
    }
    return 0;
}