#include <ctype.h>
#include <stdio.h>

#include "calc.h"

int getop(char s[])
{
	int i, c;
	static int sc = 0;

	if (sc == 0){
		c = getch();
	} else {
		c = sc;
		sc = 0;
	}

	while (c  == ' '|| c == '\t')
		c = getch();
	s[0] = c;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		sc = c;
	return NUMBER;
}
