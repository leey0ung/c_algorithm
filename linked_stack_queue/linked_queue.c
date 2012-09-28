#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOCERROR -2
#define UNDERFLOW -1

struct stack{
  int data;
  struct stack *next;
};

struct stack *p,*front = NULL, *rear = NULL;   // 外部変数

void get_cell(){
  if(NULL == (p = (struct stack *)malloc(sizeof(struct stack)))){
     printf("Malloc error!");
     exit(MALLOCERROR); 
  }
}

void enQueue(int x){
  get_cell();
  p->data = x;
  p->next = NULL;
  if(NULL == rear){  // empty queue
     front = p;
   }else{
      rear->next =p;
   }
    rear =p;
}

int deQueue(){
  int value;

  p = front;
  if(NULL == p){
     printf("Queue is empty");
     exit(UNDERFLOW);
   }
  value = p->data;
  front = p->next;
  free(p);
  return value;
}

void readQueue(){
  p = front;
  printf("The queue is:\t");
  while(NULL != p){
    printf("%d\t",p->data);
    p = p->next;
  }
  printf("\n");
}

int main(){
 int i = 0;
 char order[20];
 while(i >= 0){
   printf("enqueue: en\tnumber; dequeue:de 0;\n");
   printf(">");
   scanf("%s%d",order, &i);
   if(0 == strcmp(order, "en")){
      enQueue(i);
    }
   else if(0 == strcmp(order,"de")){
      printf("deQueue:%d\n",deQueue());
   }else{
      break;
   }
   readQueue();
 }
  return 0;
}
