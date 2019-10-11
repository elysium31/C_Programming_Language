/*
Modify undcl so that it does not add redundant parentheses to
declarations.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dcl.h"

main()
{
	int type, nexttype;
	char temp[MAXTOKEN];
	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				nexttype = getnexttoken();
				if (nexttype == BRACKETS || nexttype == PARENS) 
					sprintf(temp, "(*%s)", out);
				else
					sprintf(temp, "*%s", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
		printf("%s\n", out);
	}
	return 0;
}
