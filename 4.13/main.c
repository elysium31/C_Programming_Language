#include <stdio.h>
#include <string.h>

void _reverse(char s[], int i, int j)
{
	if (i < j){
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
		_reverse(s, i, j);
	}
}

void reverse(char s[])
{
	int i = 0;
	int j = strlen(s) - 1;

	_reverse(s, i, j);
}

main()
{
	char s[10] = "abcdef";
	reverse(s);
	printf("%s\n", s);
}
