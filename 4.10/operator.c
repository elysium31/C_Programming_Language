#include <ctype.h>
#include <stdio.h>

int get_line(char [], int);

#define NUMBER '0'
#define NAME 'n'
#define VAR 'v'
#define MAXLINE 100

int li = 0;
int llen = 0;
char line[MAXLINE];

int getop(char s[])
{
	int i, c;
	if (line[li] == '\0')
		if (get_line(line, MAXLINE) == 0)
			return EOF;
		else
			li = 0;

	while ((s[0] = c = line[li++]) == ' '|| c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (isalpha(c)){
		while(isalpha(s[++i] = c = line[li++]))
			;
		s[i] = '\0';
		--li;
		if (strlen(s) > 1)
			return NAME;
		else 
			if (isupper(s[0]))
				return VAR;
	}
	if (isdigit(c) || c == '-') {
		while(isdigit(s[++i] = c = line[li++]))
			;
		if (c == '.')
			while(isdigit(s[++i] = c = line[li++]))
				;
		s[i] = '\0';
		--li;
		if (strlen(s) == 1 && s[0] == '-')
			return '-';
		else
			return NUMBER;
	}
	return c;
}
