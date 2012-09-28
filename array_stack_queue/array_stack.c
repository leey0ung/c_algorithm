#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OVERFLOW 1
#define UNDERFLOW 2
#define ARRAY_LENGTH 5

int t; // stack point
int ARRAY_STACK[ARRAY_LENGTH];

void push(int x){
   if(t > ARRAY_LENGTH - 1 ){
      printf("STACK overflow!");
      exit(OVERFLOW);
    }
   ARRAY_STACK[t++] = x;
}

int pop(){
    if(t <= 0){
      printf("STACK underflow!");
      exit(UNDERFLOW);
    }
     ARRAY_STACK[--t] = 0;
    return ARRAY_STACK[t];
}

void readStack(){
 int i;
 for(i = 0; i < ARRAY_LENGTH; i++){
   printf("%d\t", ARRAY_STACK[i]);
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
      pop();
   }else{
      break;
   }
   readStack();
 }
  return 0;
}
