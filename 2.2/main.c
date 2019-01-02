/* Write a loop equivalent to the for loop above without using &&
or ||. */

#include <stdio.h>

#define MAXLINE 100

int main(){
	int i = 0;
	char c;
	char s[MAXLINE];
	while(1){
		if (i < MAXLINE -2)
			if ((c=getchar()) != '\n')
				if (c != EOF){
					s[i] = c;
					++i;
					continue;					
				}
		break;
	}
	s[++i] = '\0';
	printf("%s\n", s);
	return 0;
}
