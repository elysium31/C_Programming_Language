#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 3

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
	   int s = c;
	   c = getch();
	   if (!isdigit(c)){
			ungetch(c);
			ungetch(s);
			return s;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

main()
{
	int n, array[SIZE];
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;
	for (n = 0; n < SIZE; n++)
		printf("%d, ", array[n]);
	printf("\n");
	
}
