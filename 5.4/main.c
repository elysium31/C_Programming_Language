#include <stdio.h>

int strend(char *s, char *t)
{
	char *s_start = s;
	char *t_start = t;
	while (*s != '\0')
		s++;
	while (*t != '\0')
		t++;
	for(; s >= s_start && t >= t_start; s--, t--)
		if (*s != *t)
			return 0;
	return 1;
}

main()
{
	char *s = "abcdef";
	char *t1 = "ef";
	char *t2 = "ff";

	printf("%s in %s - %d\n", s, t1, strend(s, t1));
	printf("%s in %s - %d\n", s, t2, strend(s, t2));
}
