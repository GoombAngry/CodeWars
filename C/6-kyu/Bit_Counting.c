#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

size_t countBits(unsigned value)
{
	size_t c = 0;
    while(value / (unsigned) 2 != 0){
        if(value%(unsigned)2 == 1) c++;
        value /= (unsigned) 2;
    }
    return (value == (unsigned) 1)?++c:c;
}


int main(){
    printf("%zu\n",countBits(1234));

    return EXIT_SUCCESS;
}