#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 512
extern int *comp_dd(char *pat);
extern int *comp_d(char *pat);


int bm_match(char *text, char *pat){
	int i,j;
	char *t, *p;
	int p_len, t_len;
	int offset = 0;
	int *dd, *d;
	
	p = pat;
	t = text;
	p_len = strlen(p);
	t_len = strlen(t);
	dd = comp_dd(p);
	d = comp_d(p);

	j = p_len -1;
	i = p_len -1;
	while(i <= t_len -1){
		while(p[j] != '\0' && p[j] == t[i]){
			i--;
			j--;
		}
		if(p[j] == '\0'){
			return i + 1;
		}
		else{
			offset = p_len - j + dd[j] -1;
			i += offset > d[t[i]]?offset:d[t[i]];
			j = p_len -1;
		}
	}
	return -1;
}

int main(char argc, char *args[]){
	int i;
	char text[MAX] = "";
	char pat[MAX] = "";

	while(1){
		printf("input the text:\n");
		gets(text);
		printf("input the pattern:\n");
		gets(pat);

		if(strcmp(text, "quit") == 0 || strcmp(pat, "quit") == 0)
			break;
		i = bm_match(text, pat);
		printf("%d\n", i);
	}
	return 1;

}
