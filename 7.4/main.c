/*
Write a private version of scanf analogous to minprintf from
the previous section.
*/

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

void minscanf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int *ival;
	double *dval;

	char sfmt[MAXLINE];
	int c;

	int i = 0;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			sfmt[i++] = *p;
			continue;
		}
		do {
			sfmt[i++] = *p++;
		}
		while (*p && !isalpha(*p));
		sfmt[i++] = *p;
		sfmt[i] = '\0';
		switch (*p) {
		case 'd':
			ival = va_arg(ap, int *);
			scanf(sfmt, ival);
			break;
		case 'f':
			dval = va_arg(ap, double *);
			scanf(sfmt, dval);
			break;
		case 's':
			sval = va_arg(ap, char *);
			scanf(sfmt, sval);
			break;
		default:
			scanf(sfmt);
			break;
		}
		i = 0;
	}
	va_end(ap);
}

int main()
{
	int ival;
	float fval;
	char s[MAXLINE];
	
	printf("Enter int float and string:\n");
	minscanf("%d %f %s", &ival, &fval, s);
	printf("You entered: %d %f %s\n", ival, fval, s);

	
}
