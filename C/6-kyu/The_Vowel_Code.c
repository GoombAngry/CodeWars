#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// in both functions, return heap-allocated strings:

char *encode(const char *string) {
    char* text_encode = calloc(strlen(string)+1,sizeof(char));
    if(!text_encode) return NULL;
    for(size_t i = 0; i < strlen(string);i++ ){
        switch (string[i])
        {
        case 'a':
            text_encode[i] = '1';
            break;
        case 'e':
            text_encode[i] = '2';    
            break;
        case 'i':
            text_encode[i] = '3';    
            break;
        case 'o':
            text_encode[i] = '4';    
            break;
        case 'u':
            text_encode[i] = '5';
            break;
        default:
            text_encode[i] = string[i];
            break;
        }
    }
    text_encode[strlen(string)] = '\0';
    return text_encode;
}

char *decode(const char *string) {
    char* text_decode= calloc(strlen(string)+1,sizeof(char));
    if(!text_decode) return NULL;
    for(size_t i = 0; i < strlen(string);i++ ){
        switch (string[i])
        {
        case '1':
            text_decode[i] = 'a';
            break;
        case '2':
            text_decode[i] = 'e';    
            break;
        case '3':
            text_decode[i] = 'i';    
            break;
        case '4':
            text_decode[i] = 'o';    
            break;
        case '5':
            text_decode[i] = 'u';
            break;
        default:
            text_decode[i] = string[i];
            break;
        }
    }
    text_decode[strlen(string)] = '\0';
    return text_decode;
}

int main(){
    char* encode_text = "hi there";
    char* decode_text = "h3 th2r2";
    printf("Result -> [%s]\n",encode(encode_text));
    printf("Result -> [%s]\n",decode(decode_text));

    return EXIT_SUCCESS;
}