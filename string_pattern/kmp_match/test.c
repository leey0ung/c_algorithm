#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern int * compnext(char *pattern, int pat_eln);

int main(int argc, char *argv[]){
   int *next = NULL;
   int i =0;
   if(NULL != argv[1]){
     int len = strlen(argv[1]);
    next = compnext(argv[1], len);
    while(NULL != next && i < len){
      printf("%d\t",*next++);
       i++;
    }
    printf("\n");

   }
      return 0;
}
