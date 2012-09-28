#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OVERFLOW -1
#define UNDERFLOW -2
#define ARRAY_LENGTH 5

int f = 0; // front index
int r = 0; // rear index 
int ARRAY_QUEUE[ARRAY_LENGTH];

void enQueue(int x){
   if( f+ARRAY_LENGTH-r == 1 || f-r == 1){ // (r+1)%ARRAT_LENGTH=f 
      printf("Queue Overflow!");
      exit(OVERFLOW);
    }
   ARRAY_QUEUE[r++] = x;
   r %= ARRAY_LENGTH;
}

int deQueue(){
    int value;
    if(r == f){
      printf("Queue Underflow!");
      exit(UNDERFLOW);
    }
     value = ARRAY_QUEUE[f];
     ARRAY_QUEUE[f++] = 0;
     f %= ARRAY_LENGTH;
    return value;
}

void readQueue(){
 int i;
 for(i = 0; i < ARRAY_LENGTH; i++){
   printf("%d\t", ARRAY_QUEUE[i]);
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
      deQueue();
   }else{
      break;
   }
   readQueue();
 }
  return 0;
}
