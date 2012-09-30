
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
*KMP法のNEXTをもとめる
* 再帰的な構造
*/
int* compnext(char *pattern, int pat_len){
  char *p = pattern;
  int *next = (int*)malloc(pat_len*sizeof(int));
  if(NULL == pattern || 0 == pat_len) // 
     return NULL;
  
   int i =0;      // pattern point
   int s = -1;    // child point
   next[0]=s;
   
    while(i< pat_len){
      while(s>=0 && p[i] != p[s]){
          s = next[s];
     }
     /*
      * s=-1の時　一気に右シフト　s=0; i++;
      * s!=-1の時　次の位の比較を行う　s++;i++;
      * 1/ 次の位が一致する場合、pattern と　child の対応する位のNEXT値が同じ
　　　* 2/ 相違の場合、NEXT値を求める
      */
     if(p[++s] == p[++i]){
        next[i] =next[s];
     }else
       next[i] = s;
   }
    return next;
}

