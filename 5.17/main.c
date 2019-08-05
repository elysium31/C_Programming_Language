/*
Add a field-handling capability, so sorting may be done on fields
within lines, each field sorted according to an independent set of options. (The
index for this book was sorted with -df for index catefory and -n for the 
page numbers.)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "lines.h"

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *, int, int), int reverse, int pos_1, int pos_2);
int numcmp(char *, char *, int, int);
int fldcmp(char *, char *, int, int);
int dircmp(char *, char *, int, int);
int flddircmp(char *, char *, int, int);
int mstrcmp(char *, char *, int, int);

void substr(char *, char *, int, int);


main (int argc, char *argv[])
{
	int nlines;
	int numeric = 0;
	int reverse = 0;
	int fold = 0;
	int dir = 0;

	int pos_1 = 0;
	int pos_2 = 0;

	char c;
	
	if (argc > 1) {
		while (--argc){
			if (*argv[argc] == '-' && !isdigit(*(argv[argc]+1))){
				while(c = *++argv[argc]){
					printf("c = %c\n", c);
					switch (c) {						
						case 'n':
							numeric = 1;
							break;
						case 'r':
							reverse = 1;
							break;
						case 'f':
							fold = 1;
							break;
						case 'd':
							dir = 1;
							break;
						defult:
							printf("Not supported option\n");
							break;
					}
				}
			} else if (*argv[argc] == '-' && isdigit(*(argv[argc]+1)))
				pos_1 = atoi(argv[argc]+1);				
			else if (*argv[argc] = '+' && isdigit(*(argv[argc]+1)))
				pos_2 = atoi(argv[argc]+1);
		}
		if (pos_1 > pos_2)
			printf("Not supported option\n");
	}
	printf("numeric = %d, reverse = %d, fold = %d, dir = %d\n", numeric, reverse, fold, dir);
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		if (numeric) 
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*, int, int))numcmp, reverse, pos_1,
			pos_2);
		else if (fold && !dir)			
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*, int, int))fldcmp, reverse, pos_1,
			pos_2);
		else if (fold && dir)
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*, int, int))flddircmp, reverse,
			pos_1, pos_2);
		else if (!fold && dir)	
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*, int, int))dircmp, reverse,
			pos_1, pos_2);
		else
			mqsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*, int, int))mstrcmp, reverse,
			pos_1, pos_2);
			
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("input too big to sort \n");
		return 1;
	}
}

void substr(char *s, char *subs, int pos_1, int pos_2)
{
	int i, j, len;
	len = strlen(s);
	if (pos_2 == 0 || len < pos_2)
		pos_2 = len;
	for (i = pos_1, j = 0; i < pos_2; i++, j++)
		subs[j] = s[i];
	subs[j] = '\0';
}
	

void mqsort(void *v[], int left, int right, int (*comp)(void *, void *, int, int), int reverse, int pos_1,
int pos_2)
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right)
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i<=right; i++){
		if (reverse){
			if ((*comp)(v[i], v[left], pos_1, pos_2) > 0)
				swap(v, ++last, i);
		} else {
			if ((*comp)(v[i], v[left], pos_1, pos_2) < 0)
				swap(v, ++last, i);
		}
 	}		
	swap(v, left, last);
	mqsort(v, left, last-1, comp, reverse, pos_1, pos_2);
	mqsort(v, last+1, right, comp, reverse, pos_1, pos_2);
}

int mstrcmp(char *s1, char *s2, int pos_1, int pos_2)
{
	char subs1[MAXLEN];
	char subs2[MAXLEN];

	substr(s1, subs1, pos_1, pos_2);
	substr(s1, subs2, pos_1, pos_2);

	return strcmp(subs1, subs2);
		
}

int numcmp(char *s1, char *s2, int pos_1, int pos_2)
{
	double v1, v2;
	
	char subs[MAXLEN];
	substr(s1, subs, pos_1, pos_2);
	v1 = atof(subs);
	substr(s2, subs, pos_1, pos_2);
	v2 = atof(subs);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int fldcmp(char *s1, char *s2, int pos_1, int pos_2)
{
	char subs1[MAXLEN];
	char subs2[MAXLEN];

	substr(s1, subs1, pos_1, pos_2);
	substr(s1, subs2, pos_1, pos_2);
	
	int i, j;

	for(i = 0, j=0; tolower(subs1[i]) == tolower(subs2[j]); i++, j++)
		if (subs1[i] == '\0')
			return 0;
	return tolower(subs1[i]) - tolower(subs2[j]);
}

int dircmp(char *s1, char *s2, int pos_1, int pos_2)
{
	char subs1[MAXLEN];
	char subs2[MAXLEN];

	substr(s1, subs1, pos_1, pos_2);
	substr(s1, subs2, pos_1, pos_2);

	int i = 0;
	int j = 0;
	
	do {
		while(!isalnum(subs1[i]) && subs1[i] != ' ' && subs1[i] != '\0')
			i++;
		while(!isalnum(subs2[j]) && subs2[j] != ' ' && subs2[j] != '\0')
			j++;
		if (subs1[i] == subs2[j] && subs1[i] == '\0')
			return 0;
	} while (subs1[i] == subs2[j]);
	return subs1[i] - subs2[j];
}

int flddircmp(char *s1, char *s2, int pos_1, int pos_2)
{
	char subs1[MAXLEN];
	char subs2[MAXLEN];

	substr(s1, subs1, pos_1, pos_2);
	substr(s1, subs2, pos_1, pos_2);

	int i = 0;
	int j = 0;

	do {
		while(!isalnum(subs1[i]) && subs1[i] != ' ' && subs1[i] != '\0')
			i;
		while(!isalnum(subs2[j]) && subs2[j] != ' ' && subs2[j] != '\0')
			j++;
		if (tolower(subs1[i]) == tolower(subs2[j]) && subs1[i] == '\0')
			return 0;
	} while (tolower(subs1[i]) == tolower(subs2[j]));

	return tolower(subs1[i]) - tolower(subs2[j]);
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
