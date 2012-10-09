#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *comp_dd(char *pat){
	int i,j;
	char *p,*text;
	int len;
	int offset = 0;

	p = pat;
	text =pat;
	len = strlen(p);

	int *dd = (int *)malloc(sizeof(int)*len);
	for(i = 0; i <= len - 1; i++){
		dd[i] = len;
	}
	
	/* dd[len-1] */
	i = len-2;
	j = 1;
	while(0 != i && text[i] == text[len-1]){
		i--;
		j++;
	}
	dd[len-1] = j;

	i = len - 2;
	j = len -1;
	while(i >= 0){

		while(text[i] != p[j]){
			i--;
	
		}
		
		while(text[i] != '\0'&& text[--i] == p[--j]);
		if(text[i] == '\0'){
			offset = j + 1;
		}
		dd[j] = j-i;
		j = len-1;
		
	}
	for(j = 0; j <= len -1 ; j++){
		if(j < offset && dd[j] == len){
			dd[j] = offset;
		}
	}
	return dd;
}
