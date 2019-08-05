/*
Write the program tail, which prints the last n lines of its input. By default,
n is 10, let us say, but it can be changed by optional argument, so that

tail -n

prints the last n lines. The program should behave rationally no matter 
how unreasonable the input or the value of n. Write the program so that it makes
the best use of available storage; lines should be stored as in the sorting program
of Section 5.6, not in a two-dimensional array of fixed size.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFLINES 10
#define MAXLEN 100
#define MAXLINES 60

static char allocbuf[MAXLEN * MAXLINES];
static char *allocp = allocbuf;

int get_line(char *, int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int n);

char *alloc(int n)
{
	if (allocbuf + MAXLEN * MAXLINES - allocp >= n) {
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

void writelines(char *lineptr[], int nlines, int n)
{
	int i, first;
	first = nlines - n;
	if (first < 0)
		first = 0;

	for (i = first; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = get_line(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

main(int argc, char *argv[])
{
	int n;
	if (argc == 1)
		n = DEFLINES;
	else if (argc == 2 && (*++argv)[0] == '-'){
		n = atoi(argv[0]+1);
		if (n < 1 ||  n > MAXLINES)
			n = MAXLINES;
	} else {
		printf("Invalid arguments\n");
		return 1;
	}
		
	int nlines;
	char *lineptr[MAXLINES];
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) 
		writelines(lineptr, nlines, n);
	else {
		printf("error: input too big\n");
		return -1;
	}
}

int get_line(char s[], int lim)
{
        int c, i;
        for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n'){
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}
