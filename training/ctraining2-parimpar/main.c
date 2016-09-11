#include <stdio.h>
#define MASK 0x1

unsigned int num;

int main(void){
    printf("Dame un numero \n");
    scanf("%d", &num);

    if( num & MASK ){
        printf("IMPAR\n");
    } else {
        printf("PAR\n");
    }
}
