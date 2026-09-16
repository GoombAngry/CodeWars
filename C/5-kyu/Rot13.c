#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getDesRootCharacter(const char* _c, unsigned _rot_seq,const char _min, const char _max){
    unsigned iter = (unsigned)(*(_c));
    while(_rot_seq != 0){
    iter = (iter - 1 < (unsigned)(_min))?(unsigned)(_max):iter - 1;
        _rot_seq--;
    }   
    return (char)iter;
}

char *rot13(char *str_out, const char *str_in)
{
    char* f = str_out;
    while (*(str_in) != '\0')
    {
        if((*(str_in) >= 'a' && *(str_in) <= 'z') ){
            *(str_out) = getDesRootCharacter(str_in,13,'a','z');
        }else if((*(str_in) >= 'A' && *(str_in) <= 'Z')){
            *(str_out) = getDesRootCharacter(str_in,13,'A','Z');
        }else{
            *(str_out) = *(str_in);
        }        
        str_in++;
        str_out++;
    }
    
    *str_out = '\0';
    return f;
}

int main(){
    const char* input = "Guvf vf zl svefg EBG13 rkprepvfr!";
    char* output = calloc(strlen(input)+1,sizeof(char));
    if(!output) return EXIT_FAILURE;
    printf("Codificada [%s] Descodificada [%s]\n",input,rot13(output,input));
    free(output);
    return EXIT_SUCCESS;
}