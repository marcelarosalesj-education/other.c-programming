#include <stdio.h>

unsigned int get_fibonacci_val(int num){
    if (num == 0) return 1;
    else if (num == 1) return 1;
    else return ( get_fibonacci_val(num-1) + get_fibonacci_val(num-2) );
}

int main(){
    unsigned int res, n;
    n = 60;
    res = get_fibonacci_val(n);
    printf("Fibonacci of %d is %d\n", n, res);

    return 0;
}
