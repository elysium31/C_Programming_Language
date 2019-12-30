/*
Write a program that will print arbitrary input in a sensible way.
As a minimum, it should print non-graphic characters in octal or hexadecinal
according to local custom, and break long text lines.
*/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 80

enum type {oct = 8, dex = 16};


int main()
{
	char c;
	int pos = 0;
	int type = dex;
	while ((c = getchar()) != EOF){
		if (iscntrl(c)){
			if (pos + 3 > MAXLINE){
				printf("\n");
				pos = 0;
			}
			if (type == oct)
				printf("\\%2o", c);
			else if (type == dex)
				printf("\\0x%2x");
			pos = pos + 3;
		}
		else {
			if (pos + 1 > MAXLINE){
				printf("\n");
				pos = 0;
			}
			printf("%c", c);
			++pos;
		}
	}
	return 0;
}
