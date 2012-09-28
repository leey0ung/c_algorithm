#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MALLOCERROR -2
#define UNDERFLOW -1

struct stack{
  int data;
  struct stack *next;
};

struct stack *p,*top = NULL;   // 外部変数

void get_cell(){
  if(NULL == (p = (struct stack *)malloc(sizeof(struct stack)))){
     printf("Malloc error!");
     exit(MALLOCERROR); 
  }
}

void push(int x){
  get_cell();
  p->data = x;
  p->next = top;
  top = p;
}

int pop(){
  int value;

  p = top;
  if(NULL == p){
     printf("Stack is empty");
     exit(UNDERFLOW);
   }
  value = p->data;
  top = p->next;
  free(p);
  return value;
}

void readStack(){
  p = top;
  printf("The stack is:\t");
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
   printf("pushup: push\tnumber; popup: pop 0;\n");
   printf(">");
   scanf("%s%d",order, &i);
   if(0 == strcmp(order, "push")){
      push(i);
    }
   else if(0 == strcmp(order,"pop")){
     printf("pop: %d\n",pop());
   }else{
      break;
   }
   readStack();
 }
  return 0;
}
