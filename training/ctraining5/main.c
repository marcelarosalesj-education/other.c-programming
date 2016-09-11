#include <stdio.h>
#include <stdlib.h>

#define STRING "Bonne Voyage"
#define MAX_STRING_LENGHT 50


void f_stringCpy(char *ptr_source, char *ptr_dest){
    int i;
    for(i=0; i<MAX_STRING_LENGHT; i++){
        *(ptr_dest + i) = *(ptr_source + i);
    }

    /*
        // Solucion de Josue
        while( *ptr_dest++ = *ptr_source++ );
    */
}

int main(){
    char *sp_newString = (char *)malloc(MAX_STRING_LENGHT);

    printf("primero %s\n", sp_newString);

    f_stringCpy(STRING, sp_newString);

    printf("OriginalString %s   NewString %s", STRING, sp_newString);

    return 0;
}
