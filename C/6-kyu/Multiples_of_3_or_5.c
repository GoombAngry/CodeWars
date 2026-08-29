#include<stdio.h>

int solution(int number) {
    if(number <= 0) return 0;
    int total = 0;
    for (size_t i = 1; i < ((size_t)number); i++)
    {
        if( i % (size_t)(3) == 0 || i % (size_t)(5) == 0 ) total+=i;
    }
    
    return total;
} 

int main(){
    printf("Result -> %d\n",solution(10));
    return 0;
}