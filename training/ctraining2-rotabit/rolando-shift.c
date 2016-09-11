#include <stdio.h>
#include <conio.h>
#include <windows.h>

void display_vector(unsigned short int vector);


void main(void){

   unsigned short int vector, mask;
   unsigned int size;
   char left, key;
   size = 8*sizeof(vector);

   vector = 0x1;
   left = 1;
   key = 0;
   while(!key){

      display_vector(vector);

      mask = 1;
      if ((vector & mask) == mask){
        left = 1;
      }

      mask = 1 << (size-1);
      if ((vector & mask) == mask){
        left = 0;
      }
      if (left){
        vector = vector << 1;
      }else{
        vector = vector >> 1;
      }

      Sleep(100);
      key = kbhit();
   }

   key = getch();
   printf("Key: %c \n", key);
   Sleep(10000);

}


void display_vector(unsigned short int vector){

   unsigned int size, i;
   unsigned short int mask;
   size = 8*sizeof(vector);

   mask = 1 << (size-1);
   for (i=0; i<size; i++){
     if(mask & vector){
        putchar('|');
     }else{
        putchar('O');
     }
     mask = mask >> 1;

   }
   printf("\n");

}


