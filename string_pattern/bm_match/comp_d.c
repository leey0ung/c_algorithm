#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/***********************/
/* unsigned char (256) */
/***********************/


#define MAX 256

int *comp_d(char *pat){
	int i;
	int len;
	char *p;
	int *d = (int *)malloc(sizeof(int) * MAX);
	p = pat;
	len = strlen(p);
	for(i = 0; i <= MAX-1; i++){
		d[i] = len;
	}
	for(i = 0; i <= len-1; i++){
		d[p[i]] = len - i - 1;
	}	

	return d;
}
