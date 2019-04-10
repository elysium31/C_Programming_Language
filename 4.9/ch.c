#include <string.h>

#define BUFSIZE 100

char buf = 0;

char getch(void)
{
	if (buf > 0){
		char c = buf;
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

void ungets(char s[])
{
	len = strlen(s);
	
	for(int i = len; i >0; i--)
		ungetch(s[i]);
}

