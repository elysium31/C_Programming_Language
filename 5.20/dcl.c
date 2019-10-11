#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "dcl.h"
#include "getch.h"

enum { NAME, PARENS, BRACKETS };

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int prevtoken = 0;

void errmsg(char *msg)
{
	printf("%s", msg);
	char c;
	while ((c = getch()) != '\n')
		;
}

int gettoken(void)
{
	int c, getch(void);
	void ungetch(int);
	char *p = token;
	if (prevtoken == 1){
		prevtoken = 0;
		return tokentype;
	}

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; )
			;
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}

void dcl(void)
{
	int ns;

	for (ns = 0; gettoken() == '*'; ) 
		ns++;
	dirdcl();
	while (ns-- > 0)
		strcat(out, " pointer to");
}

void funcdcl()
{	
	do {
		gettoken();
		do {
			if (tokentype == NAME) {
				strcat(out, " ");
				strcat(out, token);
				gettoken();
			} else {
				prevtoken = 1;
				dcl();
			}
		} while (tokentype != ',' && tokentype != ')');
	} while (tokentype == ',');
}

void dirdcl(void)
{
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')')
			errmsg("error: missing )\n");
	} else if (tokentype == NAME)
		strcpy(name, token);
	else
		/*errmsg("error: expected name or (dcl)\n");*/
		prevtoken = 1;
	while ((type=gettoken()) == PARENS || type == BRACKETS || type == '(')
		if (type == PARENS)
			strcat(out, " function returning");
		else if (type == '(') {
			strcat(out, " function expecting");
			funcdcl();
			strcat(out, " and returning");
		} else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}
