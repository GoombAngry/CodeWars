#include<stdio.h>
#include<stdlib.h>

int *parse (const char *program)
{
    int* values = NULL;
    unsigned int size= 0;
    int sum = 0;

    while(*(program) != '\0'){
        switch (*(program))
        {
        case 'i': sum++;    break;
        case 'd': sum--;    break;
        case 's': sum*=sum; break;
        case 'o':
            size++;
            values = realloc(values,(size * sizeof(int)));
            if(!values){ free(values); return NULL;}
            values[size-1] = sum;
            break;
        default:
            break;
        }
        program++;
    }
	return values;
}