#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int * compnext(char *pattern);

int kmp_index(char *text, char *pattern){
  char *t,*p;
  int p_len,t_len;
  int i=0,j=0;
  int *next = NULL;

  t = text;
  p = pattern;
 
  if(NULL == t || NULL == p){
     return -1;
  } 
  next = compnext(p);
  p_len = strlen(p);
  t_len = strlen(t);

  while(j < t_len){
    while(p[i] == t[j]){
       i++;
       j++;     
    }
    if(i >= p_len){ //ok
       return i==p_len?j-p_len:j-p_len-1;
    }else{
      j+=1-next[i];
      i=0;
    }
  }
  return -1;
}

