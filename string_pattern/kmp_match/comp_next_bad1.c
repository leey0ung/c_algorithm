#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*KMP法のNEXTをもとめる
*/
int* compnext(char *pattern, int pat_len){
  char *s = pattern;
  int *next = (int*)malloc(pat_len*sizeof(int));
 //  int *next;
  *next = 0;
  if(NULL == pattern || 0 == pat_len) // 
     return NULL;
  if(pat_len >= 2 && *s != *(s+1)){
      *(next+1)=1;
   }else{
     *(next+1)=0;
   }
   
  int m = 0;
  int i;
  for(i = 2; i< pat_len; i++){
     //init
     m = *s==*(s+i)?0:1;
     // index
     int j;
     for(j =1; j<= i-1 ;j++){
        if(*s ==*(s+j)){
            //candicate
             if(*(s+i) != *(s+i-j)){// tail is different
                 // content is the same
                 int k = 0;
                 while(*(s+k) == *(s+j+k)){
                      k++;
                 }
                 if(k == i-j){ //ok
                   m=(k+1)>m?k+1:m;  
                 }
             }
        }
     }
    *(next+i) =m;
  }
    return next;
}

