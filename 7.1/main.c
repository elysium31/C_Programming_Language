/*
Write a program that converts upper case to lower case
to upper, depending on the name it is invoked with, as found in argv[0].
*/

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int upper, c;
	upper = 1;
	while ((c = *++argv[0]))
		if (islower(c)){
			upper = 0;
			break;
		}		

	while((c = getchar()) != EOF)
		if (upper)
			putchar(toupper(c));
		else
			putchar(tolower(c));
			
	return 0;
}
