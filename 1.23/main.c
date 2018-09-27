/*
Write a program to remove all comments from a C program.
Don't forget to handle quoted strings and character constants properly. C com-
ments do not nest.
*/

#include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];

void get_line(void);
void uncomment(void);

main()
{
	int len;

	while (1){
		get_line();
		uncomment();
	}
	return 0;
}

void get_line(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF; ++i)
		line[i] = c;
	line[i] = '\0';
}

void uncomment(void)
{
	char temp[MAXLINE];
	int i, j;
	i = 0;
	j = 0;
	int in_comment_1; 
	int in_comment_2;
	in_comment_1 = 0;
	in_comment_2 = 0;

	while(line[i] != '\0')
	{
		if (line[i] == '/' && line[i+1] == '*')
			in_comment_1 = 1;
		if (line[i-2] == '*' && line[i-1] == '/')
			in_comment_1 = 0;
		if (line[i] == '/' && line[i+1] == '/')
			in_comment_2 = 1;
		if (line[i] == '\n')
			in_comment_2 = 0;
		if (in_comment_1 == 0 && in_comment_2 == 0)
			temp[j++] = line[i];
			
		++i;
	}
	temp[++i] = '\0';

	printf("\nuncommented\n%s", temp);
}
