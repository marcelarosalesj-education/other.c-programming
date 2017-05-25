#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int bool;
#define true 1
#define false 0

struct node{
  int val;
  struct node *row;
  struct node *col;
};

struct node* CreateRandomMatrix(int rows, int cols) {
  int i,j, control=0;
  double max = 100.0, min=1.0;
  double factor = (max - min)/RAND_MAX;
  struct node* origin = (struct node*)malloc(sizeof(struct node));

  struct node* this = origin;
  (*this).val=control;//factor*rand();
  control+=10;
  (*this).row = NULL;
  (*this).col = NULL;

  struct node* cpythis = this;

  for(i=0; i<rows; i++){
    for(j=0; j<cols-1; j++){

      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      (*newnode).val=control;//factor*rand();
      control+=10;
      (*newnode).row = NULL;
      (*newnode).col = NULL;
      (*this).col = newnode;
      printf("this(%p):%d->%p , new(%p):%d->%p \n", this , this->val , this->col,
                                this->col, this->col->val , this->col->col);
      
      if(j < cols ){
        this=newnode;
      }
      

      /*
      (*this+i*cols+j).val=factor*rand();
      (*this+i*cols+j).row = nextrow;
      (*this+i*cols+j).col = nextcol;

      (*thiscol+i*cols+j).col = nextcol;
      thiscol = (*thisrow+i*cols+j+1);
      nextcol = thiscol+1;*/
    }
    printf("i is = %d\n",i );
    if(i<rows-1){
      this = cpythis; // go back to the begining
      printf("\n");
      struct node* newnode2 = (struct node*)malloc(sizeof(struct node));
      (*newnode2).val=control;//factor*rand();
      control+=10;
      (*newnode2).row = NULL;
      (*newnode2).col = NULL;
      (*this).row = newnode2;
      this = this->row;
      cpythis = this;
    }
  }



printf("\nORIGIN(%p):%d->%p , next(%p):%d->%p \n", origin , origin->val , origin->col,
                                origin->col, origin->col->val , origin->col->col);

  return origin;

}

void PrintMatrix(struct node* ptr){
  bool finish = false;

  struct node* cpy = ptr;
  printf("addr inicio : %p (%d) \n", ptr, ptr->val);
  printf("second row : %p (%d) \n", cpy->row, cpy->row->val );

  while( !finish ) {

    // printing first row, every column
    while( ptr != NULL ) {
      printf(" ( %d ) ->", ptr->val);
      ptr = ptr->col;
    }

    printf(" NULL \n");
    printf("   |        |        | \n");
    
    // next row
    ptr = cpy->row;
    cpy = ptr;
    
    if( ptr != NULL) {
      // repete printing row
    } else {
      finish = true;
      printf("  NULL     NULL     NUL\n");  
    }

  }

}

bool DeleteMatrix(struct node* origin){


}

int main(int argc, char *argv[]){
  
  if(argc < 3){
    printf("Call: <file> <num of rows> <num of columns>\n");
    return 1;
  }

  struct node *n1;
  n1 = (struct node*)malloc(sizeof(struct node));
  n1 = CreateRandomMatrix(atoi(argv[1]), atoi(argv[2])); // 2 rows, 3 cols
  

  printf("Create Matrix of n1( %p )\n", n1);
  PrintMatrix(n1);

  return 0;
}
