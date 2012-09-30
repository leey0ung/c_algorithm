#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *KMP法のnext配列を作成
 * [ACAACAB]  => [0102104]
*/
int* compnext(char *pattern){
  char *t;
  int len,*p = NULL ;
  int i,j = 0,k = 0;
  if(NULL == pattern)
    return NULL;
  t = pattern;
  len = strlen(t);
  p = (int *)malloc(sizeof(int)*len);
  *p = 0;
  for(i=1;i<len;i++){
    //  *(p+i) = 0;　初期化の時
      if(*t == *(t+i)){
        while(i+j < len && *(t+j) == *(t+i+j))
          j++;
        if(i+j <len){
             k = j+1;
           *(p+i+j)= k>*(p+i+j)?k:*(p+i+j);
           }
        j = 0;
      }else{
         *(p+i) =*(p+i)>1?*(p+i):1;
      }
  }
return p;
}

