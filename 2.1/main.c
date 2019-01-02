/*
Write a program to determine the ranges of char, short, int,
and long variables, both signed and unsigned, by printing appropriate
values from standard headers and by direct computation. Harder if you com-
pute them: determine the ranges of the various floating-point types.
*/

#include <stdio.h>
#include <limits.h>

long min_value(int size);
long max_value(int size);
unsigned long unsigned_max_value(int size);
unsigned long power_of(int base, int exponent);

int main()
{
	printf("char min = %d, calculated = %d\n", CHAR_MIN, min_value(sizeof(char)));
	printf("char max = %d, calculated = %d\n", CHAR_MAX, max_value(sizeof(char)));
	printf("signed char min = %d, calculated = %d\n", SCHAR_MIN, min_value(sizeof(signed char)));
	printf("signed char max = %d, calculated = %d\n", SCHAR_MAX, max_value(sizeof(signed char)));
	printf("unsigned char max = %d, calculated = %d\n", UCHAR_MAX, unsigned_max_value(sizeof(unsigned char)));
	printf("\n");
	printf("short min = %d, calculated = %d\n", SHRT_MIN, min_value(sizeof(short)));
	printf("short max = %d, calculated = %d\n", SHRT_MAX, max_value(sizeof(short)));
	printf("unsigned short max = %u, calculated = %u\n", USHRT_MAX, unsigned_max_value(sizeof(unsigned short)));
	printf("\n");
	printf("int min = %d, calculated = %d\n", INT_MIN, min_value(sizeof(int)));
	printf("int max = %d, calculated = %d\n", INT_MAX, max_value(sizeof(int)));
	printf("unsigned int max = %u, calculated = %u\n", UINT_MAX, unsigned_max_value(sizeof(unsigned int)));
	printf("\n");
	printf("long min = %ld, calculated = %ld\n", LONG_MIN, min_value(sizeof(long)));
	printf("long max = %ld, calculated = %ld\n", LONG_MAX, max_value(sizeof(long)));
	printf("unsigned long max = %lu, calculated = %lu\n", ULONG_MAX, unsigned_max_value(sizeof(unsigned long)));
}

unsigned long power_of(int base, int exponent)
{
	unsigned long result = base;
	for(int i=1; i < exponent; i++)
		result = base * result;
	return result;
}

long min_value(int size)
{
	long min;

	min = -power_of(2, size*8 - 1);

	return min;
}

long max_value(int size)
{
	long long max;

	max = power_of(2, size*8 - 1) - 1;

	return max;
}

unsigned long unsigned_max_value(int size){

	unsigned long max;

	max = power_of(2, size*8) - 1;

	return max;
}

