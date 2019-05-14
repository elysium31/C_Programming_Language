#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
	while ((*s++ = *t++) && --n > 0)
		;
	if (n > 0)
		*s = '\0';

}

void strncat(char *s, char *t, int n)
{
	while(*s++ != '\0')
		;
	s--;
	while((*s++ = *t++) && --n > 0)
		;
	if (n > 0)
		*s = '\0';
}

int strncmp(char *s, char *t, int n)
{
	for ( ; *s == *t; s++, t++)
		if (*s == '\0' || --n < 0)
			return 0;
	return *s - *t;
}


main()
{
	/*
	char *s;
	char *t = "proto";
	strncpy(s, t, 7);
	printf("%s\n", s);
	*/
	/*
	char s[10] = "proto";
	char t[10] = "buf";
	strncat(s, t, 6);
	printf("%s\n", s);
	*/
	char *s = "proto";
	char *t1 = "pxro";
	char *t2 = "pato";
	char *t3 = "proto";
	printf("%d\n", strncmp(s, t1, 3));
	printf("%d\n", strncmp(s, t2, 3));
	printf("%d\n", strncmp(s, t3, 3));
}
