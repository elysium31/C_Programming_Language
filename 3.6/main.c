/*In a two's complement number representation, out version of
itoa does not handle the largest negative number, that is, the value of n equal
to -(2wordsize-1). Explain why not. Modify it to print value correctly,
regardless of the machine on which it runs.
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}


void itoa(long long n, char s[], int w)
{
	int i, sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	do {
		s[i++] = sign * (n % 10) + '0';
	} while (sign * (n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	while (w > i){
		s[i++] = ' ';
	}
	s[i] = '\0';
	reverse(s);
}

int main(){
	char s[MAXLINE];
	long long n;
	n = 678;
	itoa(n, s, 6);
	printf("%lli:%s\n", n, s);
}
