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

int getfloat(float *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	   c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	/*
	if (c == '.'){
		float p;
		c = getch();
		for(p = 1.0; isdigit(c); c = getch()){
			*pn += 0.1 * p * (c - '0');
			p *= 0.1;
		}
	}
	*pn *= sign;
	*/
	if (c == '.')
		c = getch();
	float power;
	for (power = 1.0; isdigit(c); c = getch()){
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}
	*pn *= sign / power;
	if (c != EOF)
		ungetch(c);
	return c;
}

main()
{
	int n;
	float array[SIZE];
	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;
	for (n = 0; n < SIZE; n++)
		printf("%f, ", array[n]);
	printf("\n");
	
}
