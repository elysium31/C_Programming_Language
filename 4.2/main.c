/*
 * Extend atof to handle scientific noation of form
 * 123.45e-6
 * where a floating-point number may be followed by e of E and an optionally
 * signed exponent.
 */


#include <stdio.h>
#include <ctype.h>

double atof(char s[]){
	double val, power;
	int i, sign, esign, exp, k;
	int e = 1;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1: 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	esign = (s[i] == '-') ? -1: 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (exp = 0; isdigit(s[i]); i++){
		exp = 10 * exp + (s[i] - '0');		
	}
	for (k = 0; k < exp; k++)
		if (esign < 0)
			e *= 0.1;
		else
			e *= 10;
	return sign * val / power * e;
}

int main(){
	char s[] = "123.45e-6";
	printf("%g\n", atof(s));
}

