/*
	Creates an array of node_t and link each node to the next node in the array.
*/

#include <stdio.h>

struct node_t{
    int data;
    struct node_t *next;
};


int main(){
    // Linked list de un arreglo de 10 elementos

    struct node_t arr[10];
    printf("PREV: %x %x %x \n", &arr[0], &arr[1], &arr[2]);

    int i;
    for(i=0; i<10; i++){
        arr[i].next = &arr[i+1];
        printf("addr %d :  0x%p == 0x%p \n", i, &arr[i], arr[i].next);
    } // Hasta ahora el arr[9].next tiene basura

	return 0;
}
