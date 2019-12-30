/* 
Revise minprintf to handle more of hte other facilities of
printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

void minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int i, ival;
	double dval;

	char sfmt[MAXLINE];

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		i = 0;
		do {
			sfmt[i++] = *p++;
		}
		while (*p && !isalpha(*p));
		sfmt[i++] = *p;
		sfmt[i] = '\0';
		switch (*p) {
		case 'd':
			ival = va_arg(ap, int);
			printf(sfmt, ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf(sfmt, dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			printf(sfmt, sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}

int main()
{
	minprintf("%d + %d = %d\n", 2, 2, 2+2);
	minprintf("%10s\n", "hello world");
}


