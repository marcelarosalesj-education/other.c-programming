#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <unistd.h>


/*
Rotabit

*/

void display_vector(unsigned short int vector){
    unsigned int size, i;
    unsigned short int mask;
    size = 8*sizeof(vector);

    mask = 1 << (size - 1);
    for(i=0; i<size; i++){
        if(mask & vector){
            putchar('O');
        } else {
            putchar('-');
        }
        mask = mask >> 1;
    }
    printf("\n");
}

int main(){
    unsigned int val = 0x220;
    char direccion = 'L'; // 0 izq, 1 der
    printf("Empieza\n");

    display_vector(val);
    while(!kbhit()){
        if(direccion == 'L'){ // izq
            val = val << 1;
            display_vector(val);
            if(val & 0x8000) {
                direccion = 'R';
            }
        } else { // der
            val = val >> 1;
            display_vector(val);
            if(val & 0x01) {
                direccion = 'L';
            }
        }
        usleep(100000); // 100,000 us = 100 ms
    }
}
