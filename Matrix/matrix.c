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

struct node* CreateRandomMatrix(int rows, int cols){
  int i,j, control=0;
  double max = 100.0, min=1.0;
  double factor = (max - min)/RAND_MAX;
  struct node* origin = (struct node*)malloc(sizeof(struct node));

  struct node* this = origin;
  (*this).val=control;//factor*rand();
  (*this).row = NULL;
  (*this).col = NULL;

  struct node* cpythis = this;

  for(i=0; i<rows; i++){
    for(j=1; j<=cols; j++){

      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      (*newnode).val=control;//factor*rand();

      control+=10;
      (*newnode).row = NULL;
      (*newnode).col = NULL;
      (*this).col = newnode;
      printf("this(%p):%d->%p , new(%p):%d->%p \n", (&this) , (*this).val , &(*this).col,
                                &(*this).col, (*(*this).col).val , &(*(*this).col).col );
      this=newnode;
      /*
      (*this+i*cols+j).val=factor*rand();
      (*this+i*cols+j).row = nextrow;
      (*this+i*cols+j).col = nextcol;

      (*thiscol+i*cols+j).col = nextcol;
      thiscol = (*thisrow+i*cols+j+1);
      nextcol = thiscol+1;*/
    }

    if(i<rows){
      this = cpythis;
      printf("\n");
      struct node* newnode = (struct node*)malloc(sizeof(struct node));
      (*newnode).val=factor*rand();
      (*newnode).row = NULL;
      (*newnode).col = NULL;
      (*this).row = newnode;
      this = (*this).row;
    }
  }

  return origin;

}

void PrintMatrix(struct node* ptr){
  bool finish = false;

  struct node* cpy = ptr;
  while(!finish) {

    if((*ptr).val != NULL){
      printf("nn %d ", (*ptr).val);
      ptr=(*ptr).col;
    } else {
      printf("enter \n");
      ptr = (*cpy).row;
      cpy=ptr;
      if((*cpy).val == NULL){
        finish=true;
      }
    }



  }

}

bool DeleteMatrix(struct node* origin){


}

int main(){
  struct node *n1;
  n1 = (struct node*)malloc(sizeof(struct node));
  n1 = CreateRandomMatrix(2,3); // 2 rows, 3 cols

  printf("created matrix %d , %d , %d\n", (*n1).val, *(*n1).col, *(*n1).row);
  //PrintMatrix(n1);

  return 0;
}
