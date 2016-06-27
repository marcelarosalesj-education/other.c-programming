/*
    Unidirectional Linked List with many functions
    This approach to linked list 
*/

#include <stdio.h>
#include <stdlib.h>

struct node_t{
    int data;
    struct node_t *next;
};


struct node_t *head = NULL;
int len = 0;

void print_menu(){
    printf("----------------------\n");
    printf("Menu:\n");
    printf("1) Create Linked List\n");
    printf("2) Display\n");
    printf("3) Select Node\n");
    printf("4) Insert Node\n");
    printf("5) Remove Node\n");
    printf("6) Delete All Nodes\n");
    printf("0) Exit\n");
    printf("> ");
}


// 1) Create Linked List
void create_list(){
    printf("N : ");
    scanf("%d", &len);

    if(len > 0){
        head  = (struct node_t*)malloc( sizeof(struct node_t) );
        struct node_t *ptr_aux = head;

        int i;
        for(i=0; i<len; i++){
            printf("LIST[%d] = ", i);
            scanf("%d", &(*ptr_aux).data );

            if(i == (len-1)){
                (*ptr_aux).next = NULL;
            } else
                (*ptr_aux).next = (struct node_t*)malloc(sizeof(struct node_t));

            ptr_aux = (*ptr_aux).next;
        }
    }   
}

// 2) Display
int display_list() {
    if(head == NULL)
        return 1;
    else {
        printf("Length %d\n", len);
        struct node_t *ptr_aux = head;
        int i;
        for(i=0; i<len; i++) {
            printf("LIST[%d] = %d, ADDR = %p, NADDR = %p \n", i, (int)(*ptr_aux).data, ptr_aux, (*ptr_aux).next);
            ptr_aux = (*ptr_aux).next;
        }
    }
    return 0;
}

// 3) Select Node
void select_node(int sel) {
    struct node_t *ptr_aux = head;
    int j;
    for(j=0; j<len; j++) {
        if(j == sel) {
            printf("LIST[%d] = %d, ADDR = %p \n ", j, (int)(*ptr_aux).data, ptr_aux);
            j=len;
        }
        ptr_aux = (*ptr_aux).next;
    }
}
// 4) Insert Node
void insert_node(int pos, struct node_t *insert){
    struct node_t *ptr_aux = head;
    if(pos == 0){
        // In this case the node goes between head and ptr_aux
        head = insert;
        (*insert).next = ptr_aux;
    } else {
        // Node goes between ptr_aux and ptr_next
        int j;
        for(j=0; j<(pos-1); j++) {
            ptr_aux = (*ptr_aux).next;
        }
        struct node_t *ptr_next = (*ptr_aux).next;
        (*ptr_aux).next = insert;   // ptr_aux point to insert
        (*insert).next = ptr_next;  // insert point to ptr_next
    } 
    len++;
}

// 5) Remove Node
void remove_node(int pos){
    struct node_t *ptr_aux = head;
    if(pos == 0) {
        // The head is removed
        head = (*head).next;
        free(head);
    } else {
        // Node to be removed is between ptr_aux and ptr_next
        int j;
        for(j=0; j<(pos-1); j++) {
            ptr_aux = (*ptr_aux).next;
        }
        // check if the next.next is NULL 
        struct node_t *ptr_next = (*ptr_aux).next;
        if( (*ptr_next).next == NULL ){
            (*ptr_aux).next = NULL;
        } else {
            (*ptr_aux).next = (*ptr_next).next;   // ptr_aux point to what ptr_next points.
        }
        free(ptr_next);
    } 
    len--;
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
    int menu;
    do{

        print_menu();
        scanf("%d", &menu);
        printf("----------------------\n");

        // 1) Create Linked List
        if(menu == 1){
            if(head != NULL)
                printf("- Error: You already have a list.\n");
            else
                create_list();
        }
        // 2) Display
        else if(menu == 2){
            if(display_list()){ // if it returns a 1, it failed.
                printf("- Error: List is empty \n");
            }
        }
        // 3) Select Node
        else if(menu == 3){
            int selection;
            printf("> Select Node [0:N-1]: ");
            scanf("%d", &selection);
            if(selection >= len || selection < 0)
                printf("- Error: Not available position.\n");
            else
                select_node(selection);

        }
        // 4) Insert Node
        else if(menu == 4){
            int selection;
            printf("> Insert Node [0:N]: ");
            scanf("%d", &selection);
            if(selection > len || selection < 0){
                printf("- Error: Not available position.\n");
            } else {
                struct node_t *insert  = (struct node_t*)malloc( sizeof(struct node_t) );
                printf("> Dato a insertar: ");
                scanf("%d", &(*insert).data );
                insert_node(selection, insert);
            }
        }
        // 5) Remove Node
        else if(menu == 5){
            int selection;
            printf("> Remove Node [0:N-1]: ");
            scanf("%d", &selection);
            if(selection >= len || selection < 0)
                printf("- Error: Not available position.\n");
            else
                remove_node(selection);
        }
        // 6) Delete All Nodes
        else if(menu == 6){
            delete_all();
            printf("- All nodes deleted.\n");
        }

    } while(menu != 0);
  
    return 0;
}
