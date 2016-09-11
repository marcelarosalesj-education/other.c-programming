#include    <stdio.h>
#include <stdlib.h>

#define MEMORY_REQUEST 1024
/*
 SIZE OF THE HEAP
*/

int main(){
    int size = 0;
    char *ptr;

    do {
            ptr = (char*)malloc(MEMORY_REQUEST);
            size++;

    }while(ptr);

    printf("Size: %d", size);
    /* A este size se le resta 1 porque el size++
    ya habia sumado cuando el ptr se hizo null.

    */
    return 0;
}
