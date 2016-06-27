/*
	Simple Linked List Generator and Selector
*/

#include <stdio.h>

struct node_t{
    int data;
    struct node_t *next;
};


int main(){

    int N;
    struct node_t *head  = (struct node_t*)malloc( sizeof(struct node_t) );
    printf("Dame N: ");
    scanf("%d", &N);

    struct node_t *ptr_aux = head;

    printf("size of struct %d \n", sizeof(struct node_t) );
    printf("head: %p aux: %p \n", head, ptr_aux);


    int i;
    for(i=0; i<N; i++){
        printf("Dato: ");
        scanf("%d", &(*ptr_aux).data );

        printf("Addr: %p  , Data: %d , ", ptr_aux, (int)(*ptr_aux).data);

        (*ptr_aux).next = (struct node_t*)malloc(sizeof(struct node_t));

        printf("Next: %x\n", (*ptr_aux).next );
        ptr_aux = (*ptr_aux).next;
    }

    int sel=0;
    do{
        ptr_aux = head;
        printf("Selecciona un dato por posicion [0:N-1]: ");
        scanf("%d", &sel);

        int j;
        for(j=0; j<N; j++){

            if(j == sel){
                printf("Dato que buscas: %d, addr %p \n ", (int)(*ptr_aux).data, ptr_aux);
                j=N;

            }
            ptr_aux = (*ptr_aux).next;
        }
    }while(sel < N && sel >= 0);

    return 0;
}