/*
Modify the sort program to handle a -r flag, which indicates 
sorting in reverse (descreasing) order. Be sure that -r works with -n.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lines.h"

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);

main (int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
	int reverse = 0;

	if (argc > 1) {
		while (argc--){
			if (strcmp(argv[argc], "-n") == 0)
				numeric = 1;
			else if (strcmp(argv[argc], "-r") == 0)
				reverse = 1;
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : strcmp), reverse);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort \n");
		return 1;
	}
}

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i<=right; i++){
		if (reverse){
			if ((*comp)(v[i], v[left]) > 0)
				swap(v, ++last, i);
		} else {
			if ((*comp)(v[i], v[left]) < 0)
				swap(v, ++last, i);
		}
 	}		
	swap(v, left, last);
	mqsort(v, left, last-1, comp, reverse);
	mqsort(v, last+1, right, comp, reverse);
}

int numcmp(char *s1, char *s2){
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
