#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <string.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define NAME 'n' /* signal that a function was found */

int getop(char []);
void push(double);
double pop(void);
double top(void);
void swap(void);
void clear(void);

/* reverse Polish calculator */
main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
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
				printf("error: operator not supported");				
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
