/*
	Double Linked List
	I choose to use pointer to pointer to head in order to 
	make the add beginning easier. 
*/


#include <stdio.h>
#include <stdlib.h>

struct node{
	int Data;
	struct node *next;
	struct node *prev;
};


struct node * create_node(int d){
	struct node *n = (struct node*)malloc( sizeof(struct node) );
	(*n).Data = d;
	(*n).next = NULL;
	(*n).prev = NULL;
	return n;
}

void add_last(struct node **h, int d){
	struct node *n = create_node(d);
	struct node *aux = (*h);
	// go to end of h list
	while( (*aux).next != NULL ){
		(aux)=(*aux).next;	
	}
	(*aux).next = n;
	(*n).prev = aux;
}

void add_beginning(struct node **h, int d){
	struct node *n = create_node(d);
	(*n).next = (*h); // new next is pointing to head
	(**h).prev = n; // head prev is pointing to new
	(*h) = n; // now, new head is the new node.
}

void display_list( struct node **h){
	struct node *aux = (*h);
	while( (*aux).next != NULL ){
		printf("%p-%d \n", &aux, (*aux).Data );
		aux = (*aux).next;
	
	}
	printf("%p-%d \n", &aux, (*aux).Data );
}

int main() {
	struct node * head;
	struct node ** ptr_head;
	ptr_head = &head;

	head = create_node(10);
	add_last(ptr_head, 5);
	add_last(ptr_head, 20);
	printf("----\n" );
	display_list(ptr_head);
	add_beginning(ptr_head, 123);
	add_last(ptr_head, 40);
	add_beginning(ptr_head, 100);
	printf("----\n" );
	display_list(ptr_head);

	return 0;
}