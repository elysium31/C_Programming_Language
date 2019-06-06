/*Rewrite the routines day_of_year and month_day with pointers instead of indexing.*/


#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	if (year < 1)
		return -1;
	if (month < 1 || month > 12)
		return -1;

	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	
	if (day < 1 || day > daytab[leap][month])
		return -1;

	char *pdaytab = daytab[leap];

	for(i = 1; i < month; i++)
		day += *++pdaytab;
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	int days = 0;

	if (year < 1){
		*pmonth = -1;
		*pday = -1;
		return;
	}

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	for(i = 1; i < 12; i++)
		days += daytab[leap][i];

	if (yearday > days){
		*pmonth = -1;
		*pday = -1;
		return;
	}
	
	char *pdaytab = daytab[leap];

	i = 1;
    while(yearday > *pdaytab){
		yearday -= *++pdaytab;
		i++;
	}
	*pmonth = i;
	*pday = yearday;
}

main()
{
	int year = 2019;
	int month = 6;
	int day = 3;
	
	int yearday = day_of_year(year, month, day);
	printf("day of year = %d\n", yearday);
	int pmonth, pday;

	month_day(year, yearday, &pmonth, &pday);
	printf("month = %d, day = %d\n", pmonth, pday);
}


