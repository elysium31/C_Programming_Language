/*
Write the program expr, which evaluates a reverse Polish 
expression from the command line, where each operator or operand is a separate
argument. For example,
    expr 2 3 4 + *
evaluates 2 * (3+4)
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXVAL 100
#define NUMBER '0'
#define MAXOP 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stach full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}


int getop(char *arg, char s[])
{
	int i, c;

	while ((s[0] = c = *arg++) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while(isdigit(s[++i] = c = *arg++))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = *arg++))
			;
	s[i] = '\0';
	if (c != EOF)
		--arg;
	return NUMBER;
}

main(int argc, char *argv[])
{
    char s[MAXOP];
	double op2;

	while(--argc > 0){
		switch(getop(*++argv, s)){
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() /op2);
				else
					printf("error: zero divisor\n");
				break;
			default:
				printf("error: unknow command %s\n", s);
				break;
			}
	}
	printf("\t%.8g\n", pop());
	return 0;
}

