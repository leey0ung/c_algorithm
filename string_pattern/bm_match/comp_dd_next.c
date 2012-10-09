#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define TEST 1
#define MAX 512
int *comp_dd(char *pat){
	int i,j;
	char *p,*text;
	int len;
	int offset = 0;

	p = pat;
	text =pat;
	len = strlen(p);

	int *dd = (int *)malloc(sizeof(int)*len);
	int *next = (int *)malloc(sizeof(int)*len); /* next[]　一致してない時,pのポイントの遷移 */
	
	for(i = 0; i <= len -1; i++){
		dd[i] = len;
	}
	
	i = len -1;
	j = len;
	while(i >= 0){
		next[i] = j;
		while(j <= len -1 && text[i] != p[j]){
			if(dd[j] > j-i)
				dd[j] = j - i;
			j = next[j];
		}
		i--;
		j--;
	}
	 /* j => offset  j = len-1の時　しっぽパターンの特殊形が存在しない */
	 /* 　　　　　　 j < len-1の時　しっぽパターンの特殊形が存在する */
	offset = j + 1;
	for(j = 0; j <= len -1; j++){
		if(j < offset && dd[j] > offset)
			dd[j] = offset;
	}
	free(next);
	next = NULL;
	return dd;
}
#ifdef TEST
int main(char argc, char *args[]){
	int *dd = NULL;
	int i;
	char text[MAX] = "";

	while(1){
		printf("input the text:\n");
		gets(text);
		if(strcmp(text, "quit") == 0)
			break;
		dd = comp_dd(text);
		for(i = 0; i <= strlen(text)-1; i++){
			printf("%d\t", dd[i]);
		}
		printf("\n");
	}
	return 1;

}
#endif
