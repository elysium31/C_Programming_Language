/*
Add the -d ("directory order") option, which makes comparis-
ons only on letters, numbers and blanks. Make sure it works in conjunction
with -f.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lines.h"

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);
int fldcmp(char *, char *);
int dircmp(char *, char *);
int flddircmp(char *, char *);


main (int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
	int reverse = 0;
	int fold = 0;
	int dir = 0;

	if (argc > 1) {
		while (argc--){
			if (strcmp(argv[argc], "-n") == 0)
				numeric = 1;
			else if (strcmp(argv[argc], "-r") == 0)
				reverse = 1;
			else if (strcmp(argv[argc], "-f") == 0)
				fold = 1;
			else if (strcmp(argv[argc], "-d") == 0)
				dir = 1;
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		if (numeric) 
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))numcmp, reverse);
		else if (fold && !dir)			
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))fldcmp, reverse);
		else if (fold && dir)
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))flddircmp, reverse);
		else if (!fold && dir)	
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))dircmp, reverse);
		else
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))strcmp, reverse);
			
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

int fldcmp(char *s1, char *s2){
	for(; tolower(*s1) == tolower(*s2); s1++, s2++)
		if (*s1 == '\0')
			return 0;
	return tolower(*s1) - tolower(*s2);
}

int dircmp(char *s1, char *s2){
	do {
		while(!isalnum(*s1) && *s1 != ' ' && *s1 != '\0')
			s1++;
		while(!isalnum(*s2) && *s2 != ' ' && *s2 != '\0')
			s2++;
		if (*s1 == *s2 && *s1 == '\0')
			return 0;
	} while (*s1 == *s2);
	return *s1 - *s2;
}

int flddircmp(char *s1, char *s2){
	do {
		while(!isalnum(*s1) && *s1 != ' ' && *s1 != '\0')
			s1++;
		while(!isalnum(*s2) && *s2 != ' ' && *s2 != '\0')
			s2++;
		if (tolower(*s1) == tolower(*s2) && *s1 == '\0')
			return 0;
	} while (tolower(*s1) == tolower(*s2));
	return tolower(*s1) - tolower(*s2);
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
