#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    int r, g, b;
} rgb;

unsigned calculate(const char* const hex,int expo){
    unsigned i = (unsigned)*(hex);
    unsigned total = (i >= (unsigned)(48) && i <= (unsigned)(57))? i - (unsigned)(48):(i >= (unsigned)(97) && i <= (unsigned)(102))? i - (unsigned)(97) + (unsigned)10:i - (unsigned)(65) + (unsigned)10;
    return total * (unsigned)pow((double)16,expo);

}

unsigned getValue(const char* _start,const char* _end){
    return calculate(_start,1) + calculate(_end,0);
}
rgb hex_str_to_rgb(const char *hex_str) {
    return (rgb) {.r = getValue(hex_str+1,hex_str+2), .g =getValue(hex_str+3,hex_str+4), .b = getValue(hex_str+5,hex_str+6)};
}

int main(){
    rgb data = hex_str_to_rgb("#FF9933");
    printf("Resultado -> %d\n",data.r);
    printf("Resultado -> %d\n",data.g);
    printf("Resultado -> %d\n",data.b);

    
    return 0;
}