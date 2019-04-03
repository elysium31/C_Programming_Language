#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

#define NUMBER '0'
#define NAME 'n'
#define VAR 'v'

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' '|| c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (isalpha(c)){
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF)
			ungetch(c);
		if (strlen(s) > 1)
			return NAME;
		else 
			if (isupper(s[0]))
				return VAR;
	}
	if (isdigit(c) || c == '-') {
		while(isdigit(s[++i] = c = getch()))
			;
		if (c == '.')
			while(isdigit(s[++i] = c = getch()))
				;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		if (strlen(s) == 1 && s[0] == '-')
			return '-';
		else
			return NUMBER;
	}
	return c;
}
