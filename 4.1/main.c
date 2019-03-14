/*
Write the function strrindex(s, t), which returns the position
of the rightmost occurence of t in s, or -1 if there is none.
*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int strrindex(char s[], char t[]){
	int i, j, k;
	for(i = strlen(s); i > 0; i--){
		for(j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int main(){
	char s[] = "jkdjkdjksznkuieqoznmc";
	char t[] = "zn";
	printf("Input string: %s\n, pattern %s\n, index: %d\n", s, t, strrindex(s, t));	
}


