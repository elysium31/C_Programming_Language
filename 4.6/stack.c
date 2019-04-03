#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g/n", f);
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

double top(void)
{
	if (sp > 0)
		return val[sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

void swap(void){
	double t = val[sp];
	val[sp] = val[sp-1];
	val[sp-1] = t;
}

void clear(void){
	sp = 0;
}
