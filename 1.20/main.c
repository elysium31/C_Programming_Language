/*
Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixes set of
tab stops, say every n columns. Should n be a variable or a symbolic parame-
ter?
*/

#include <stdio.h>

#define MAXLINE 1000
#define TAB_SPACES 4

char line[MAXLINE];

int get_line(void);
void detab(void);

main()
{
	int len;
	extern char longest[];

	while ((len=get_line()) > 0){
		detab();
		printf("%s", line);
	}
	return 0;
}

int get_line(void)
{
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

void detab(void)
{
	int i, j, k;
	char temp[MAXLINE];
	extern char line[];

	i = 0;
	while ((temp[i] = line[i]) != '\0')
		++i;
	j = 0;
	for (i=0; i < MAXLINE - 1; ++i)
	{
		if (temp[i] == '\0')
			break;
		
		if (temp[i] == '\t')
			for (k =0; k < TAB_SPACES; ++k)
				line[j++] = ' ';
		else
			line[j++] = temp[i];
	}
	line[j++] = '\0';
}
