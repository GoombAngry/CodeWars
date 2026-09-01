#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int extractNumber(const char* cadena){
    int n = 0;
    size_t trash = strlen(cadena) - 1;
    while(*(cadena) != '\0'){
        n+= ((int)*(cadena) - 48) * ((int)pow(10,trash));
        trash--;
        cadena++;
    }
    return n;
}

int last_digit(const char *a, const char *b)
{
    int n1,n2;
    size_t l_a = strlen(a), l_b = strlen(b);
    if(l_a == ((size_t) 1) && (((int)*(a)) - 48 ) == 0 && l_b == 1 && (((int)*(b)) - 48 ) == 0 ) return 1;
    if(l_a == ((size_t) 1) && (((int)*(a)) - 48 ) == 0) return 0;
    if(l_b == ((size_t) 1) && (((int)*(b)) - 48 ) == 0) return 1;
    n1 = (l_a > (size_t)1)?extractNumber(&a[l_a - (size_t)1]):(int)*a - 48;
    n2 = (l_b > (size_t)1)?extractNumber(&b[l_b - (size_t)2]):extractNumber(&b[l_b - (size_t) 1]);
    n2 = n2 % 4 == 0?4:n2 % 4;
    return (int)pow((double)n1,(double)n2) % 10;
}

int main(){

    printf("Result -> %d\n",last_digit("0","0"));
    printf("Result -> %d\n",last_digit("0","2"));
    printf("Result -> %d\n",last_digit("13","0"));
    printf("Result -> %d\n",last_digit("188393","10"));
    
    return 0;
}