/* `
Write a function reverse(s) that reverses the character
string s. Use to write a program that reverses input a line at a time
*/

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);

main()
{
	int len;
	char line[MAXLINE];
	
	while((len = get_line(line, MAXLINE)) > 0){
		reverse(line); 
		printf("%s", line);
	}
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;
	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void reverse(char s[]){
	int len, i;
	for(i=0; s[i]!='\0'; ++i)
		;
	--i;
	if (s[i-1] == '\n')
		--i;
	int j, k;
	char temp;
	
	for(j=0, k=i; j < k; ++j, --k){
		temp = s[j];
		s[j] = s[k];
		s[k] = temp;
	}
	
		
}


