
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int* compnext(char *pattern, int pat_len);


int kmp_index(char *text, char *pattern){
    char *t,*p;
    int p_len,t_len;
    int i=0,j=0;
    int *next =NULL;
    
    t = text;
    p= pattern;
    if(NULL ==t || NULL ==p){
          return -1;
   } 
   p_len = strlen(p);
   t_len = strlen(t);
   next = compnext(p,p_len);
   while(i< t_len){
      while( j >= 0 && t[i] != p[j]){
          j=next[j];
      }
      if(j == p_len-1){
        return i-p_len+1;
      }else{
        i++;
        j++;
      }
   }
    return -1;
}

int main(char args, char *argv[]){
  int i;
  printf("The index is:%d\n", kmp_index(argv[1], argv[2]));
}
