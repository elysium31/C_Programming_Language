#include <stdio.h>

void _strcat(char *s, char *t)
{
	while (*s)
		s++;
	while (*s++ = *t++)
		;
}

main()
{
	char s1[10] = "abc";
	char s2[10] = "def";
	
	_strcat(s1, s2);

	printf("%s\n", s1);

}
