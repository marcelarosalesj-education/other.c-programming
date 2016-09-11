#include <stdio.h>
#define MANCHADO 1

/*
Par o Impar con otro metodo que no sea mod %
*/

int main(){
    short edad;
    if(MANCHADO){
        printf("Hola mundo.\n");
        printf("Dame tu edad: \n");
        scanf("%d", &edad);
        printf("abc %d", edad);
    } else {
        printf("Else.\n");
    }
    return 0;
}
