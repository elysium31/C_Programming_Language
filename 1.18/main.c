/*
Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines.
*/

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

main(){
	char line[MAXLINE];
	int len;
	while((len = get_line(line, MAXLINE)) > 0)
		printf("%s\n", line);
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;
	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	int j;
	for(j=i-1; j>=0; --j)
	{
		if (s[j] == ' ' || s[j] == '\t')
			continue;
		break;
	}
	s[++j] = '\0';
	return j;
}
