#include <stdio.h>

float to_fahr(int celsius){
	return (9.0*celsius + 32.0*5.0)/5.0;
}


main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;
	
	printf(" Cs     Fh\n");
	while (celsius <= upper) {
		fahr = to_fahr(celsius);
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
