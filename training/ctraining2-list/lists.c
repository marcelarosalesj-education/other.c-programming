#include<stdio.h>
#include<stdlib.h>

struct node_t {
   int data;
   struct node_t *next;
};

struct node_t* create_node(int data);
struct node_t* n_insert(struct node_t *head, int data);
struct node_t* n_remove(struct node_t *head, int data);
void print_list(struct node_t *head);

int main(void){
   struct node_t *list =0;
   list = n_insert(list, 10);
   n_insert(list, 5);
   n_insert(list, 20);
   print_list(list);
   n_remove(list,5);
   print_list(list);
   return 0;
}


struct node_t* create_node(int data)
{
   struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
   node->data=data;
   node->next=NULL;
   return node;
}

struct node_t* n_insert(struct node_t *head, int data)
{
   struct node_t* current=head;

   if(current){
      while(current->next){
         current = current->next;
      }
      current->next = create_node(data);
      return head;
   }else{
      return create_node(data);
   }
}

struct node_t* n_remove(struct node_t *head, int data)
{
   struct node_t *last, *current;
   last=current=head;
   
   if(!head) return head;
   
   if(head->data == data){
      head = current->next;
      free(current);
      return head;
   }
   current=current->next;
   
   while(current){
      if(current->data == data){
         last->next = current->next;
         free(current);
         return head;
      }
      last = current;
      current = current->next;
   }
   printf("ERROR: Nodo no encontrado\n");
   return head;
}

void print_list(struct node_t *head)
{
   printf("head->");
   while(head){
      printf("%d->",head->data);
      head=head->next;
   }
   printf("NULL\n");
}