#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n' /* signal that a function was found */
#define VAR 'v'

int getop(char []);
void push(double);
double pop(void);
double top(void);
void swap(void);
void clear(void);

#define VARS_SIZE 26

/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];
	double vars[VARS_SIZE];
	char v;

	for (int i=0; i<VARS_SIZE; i++)
		vars[i] = 0.0;

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			printf("put '%s' in stack\n", s);
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
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor\n");
			break;
		case '=':
			op2 = pop();
			vars[v] = op2;
			break;
		case VAR:
			v = s[0] - 'A';
			if (vars[v] != 0.0)
				push(vars[v]);
		case NAME:
			if (strcmp(s, "sin") == 0)
				push(sin(pop()));
			else if (strcmp(s, "cos") == 0)
				push(cos(pop()));
			else if (strcmp(s, "pow") == 0){
				op2 = pop();
				push(pow(pop(), op2));
			}
			else if (strcmp(s, "exp") == 0)
				push(exp(pop()));
			else
				printf("error: operator not supported\n");				
		case 't':
			op2 = top();
			if (op2 != 0.0)
				printf("\t%.8g", op2);
			break;
		case 's':
			swap();
			break;
		case 'c':
			clear();
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}
