#include <stdio.h>

void printd(int n)
{
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

void itoa(int n, char s[])
{
	static int i = 0;

	if (n < 0){
		s[i++] = '-';
		n = -n;
	}
	if (n /10)
		itoa(n / 10, s);
	s[i++] = n % 10 + '0';
	s[i] = '\0';
	
}
		

main()
{
	char s[10];
	itoa(123, s);
	printf("%s\n", s);
}
