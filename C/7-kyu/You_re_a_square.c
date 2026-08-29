#include <stdbool.h>
#include <math.h>
#include <stdio.h>

bool is_square(int n) {
    return (n < 0)?false:((int)pow((int)sqrt(n),2) == n);
    // <---- hajime!
}
