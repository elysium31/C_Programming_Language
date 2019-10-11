/*
Expand dcl to handle dec;arations with function argument
types, qualifiers like const, and so on.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "dcl.h"

main()
{
	while (gettoken() != EOF) {
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
			errmsg("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}
