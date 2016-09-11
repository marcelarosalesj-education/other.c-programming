#include <stdio.h>

struct node_t{
    int data;
    struct node_t *next;
};


struct node_t *head;
int len;

// 1) Create Linked List
void create_list(){
    printf("Dame N: ");
    scanf("%d", &len);
    head  = (struct node_t*)malloc( sizeof(struct node_t) );
    struct node_t *ptr_aux = head;

    printf("head: %p aux: %p \n", head, ptr_aux);

    int i;
    for(i=0; i<len; i++){
        printf("Dato: ");
        scanf("%d", &(*ptr_aux).data );

        printf("Addr: %p  , Data: %d , ", ptr_aux, (int)(*ptr_aux).data);

        if(i == (len-1)){
            (*ptr_aux).next = NULL;
        } else
            (*ptr_aux).next = (struct node_t*)malloc(sizeof(struct node_t));

        printf("Next: %x\n", (*ptr_aux).next );
        ptr_aux = (*ptr_aux).next;
    }
}

// 2) Display
int display_list() {
    if(head == NULL)
        return 1;
    else {
        struct node_t *ptr_aux = head;
        int i;
        for(i=0; i<len; i++) {
            printf("POS = %d, DATA = %d, ADDR = %p, NADDR = %p \n", i+1, (int)(*ptr_aux).data, ptr_aux, (*ptr_aux).next);
            ptr_aux = (*ptr_aux).next;
        }
    }
    return 0;
}

// 3) Select Node
void select_node(int sel) {
    struct node_t *ptr_aux = head;
    printf("head: %p aux: %p \n", head, ptr_aux);
    int j;
    for(j=0; j<len; j++) {
        printf("j: %d sel: %d \n", j, sel);
        if(j == sel) {
            printf("Dato que buscas: %d, addr %p \n ", (int)(*ptr_aux).data, ptr_aux);
            j=len;
        }
        ptr_aux = (*ptr_aux).next;
    }
}
// 4) Insert Node
void insert_node(int pos, struct node_t *insert){
    printf("pos in: %d\n", pos);

    struct node_t *ptr_aux = head;
    printf("head: %p aux: %p \n", head, ptr_aux);
    int j;
    for(j=0; j<(pos-1); j++) {
        /*printf("j: %d sel: %d \n", j, sel);
        if(j == sel) {
            printf("Dato que buscas: %d, addr %p \n ", (int)(*ptr_aux).data, ptr_aux);
            j=len;
        }*/
        ptr_aux = (*ptr_aux).next;
        printf("ptr is in %p\n", ptr_aux);
    }
    struct node_t *ptr_next = (*ptr_aux).next;
    printf("ptr_next is in %p\n", ptr_next);

    // create a mem space with structure and insert between ptr_aux and ptr_next
    //struct node_t *insert  = (struct node_t*)malloc( sizeof(struct node_t) );
    //(*insert).data = 555;
    // ptr_aux point to insert
    (*ptr_aux).next = insert;
    // insert point to ptr_next
    (*insert).next = ptr_next;
    len++;
}



// 5) Remove Node
void remove_node(int pos){
    printf("pos rn: %d\n", pos);
}


// 6) Delete All Nodes
void delete_all() {
    struct node_t *ptr_aux;
    while(head != NULL) {
        ptr_aux = head;
        head = (*head).next;
        free(ptr_aux);
    }
    head = NULL;
    len=0;
}

int main(){

    /*
    // Linked list de un arreglo de 10 elementos

    struct node_t arr[10];
    printf("PREV: %x %x %x \n", &arr[0], &arr[1], &arr[2]);

    int i;
    for(i=0; i<10; i++){
        arr[i].next = &arr[i+1];
        printf("addr %d :  0x%p == 0x%p \n", i, &arr[i], arr[i].next);
    } // Hasta ahora el arr[9].next tiene basura


    */


    int menu;
    do{
        printf("Menu:\n");
        printf("1) Create Linked List\n");
        printf("2) Display\n");
        printf("3) Select Node\n");
        printf("4) Insert Node\n");
        printf("5) Remove Node\n");
        printf("6) Delete All Nodes\n");
        printf("0) Exit\n");
        printf("> ");
        scanf("%d", &menu);

        // 1) Create Linked List
        if(menu == 1){
            printf(" create \n");
            create_list();
        }
        // 2) Display
        else if(menu == 2){
            printf(" display \n");
            if(display_list()){ // if it returns a 1, it failed.
                printf("Error: List is empty \n");
            }
        }
        // 3) Select Node
        else if(menu == 3){
            printf(" sel \n");
            int selection;
            printf("Select Node [0:N-1]: ");
            scanf("%d", &selection);
            select_node(selection);

        }
        // 4) Insert Node
        else if(menu == 4){
            printf(" insert \n");
            int selection;
            printf("Insert Node [0:N-1]: ");
            scanf("%d", &selection);
            struct node_t *insert  = (struct node_t*)malloc( sizeof(struct node_t) );
            printf("Dato a insertar: ");
            scanf("%d", &(*insert).data );

            insert_node(selection, insert);
        }

        // 5) Remove Node
        else if(menu == 5){
            printf(" remove \n");
            int selection;
            printf("Remove Node [0:N-1]: ");
            scanf("%d", &selection);
            remove_node(selection);
        }

        // 6) Delete All Nodes
        else if(menu == 6){
            printf(" del all \n");
            delete_all();
        }

    } while(menu != 0);



    /*
    (*ptr_aux).data = (int)N;
    printf("%d", (*ptr_aux).data);
    */


  /*
  // Linked list con selector

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

*/
    printf("head: %p \n", head);
    return 0;
}
