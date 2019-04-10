#include <string.h>
#include <stdio.h>

int buf = 0;

int getch(void)
{
	if (buf != 0){
		int c = buf;
		buf = 0;
		return c;
	}
	else
		return getchar();	
}

void ungetch(int c)
{
	if (buf > 0)
		printf("ungetch: too many characters\n");
	else
		buf = c;
}

