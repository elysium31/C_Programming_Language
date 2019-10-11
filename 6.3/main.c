/*
Write a cross-referencer that prints a list of all words in a docu-
ment, and, for each word, a list of the line numbers on which it occurs. Remove
noise words like "the", "and", and so on.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "getch.h"

#define MAXWORD 100

struct tnode {
	char *word;
	char *refs;
	struct tnode *left;
	struct tnode *right;
};

int getword(char *, int, int *);
struct tnode *addtreex(struct tnode *, char *, int *);
void treexprint(struct tnode *);
int compare(char *, struct tnode *, int *, int);
char *mstrdup(char *);
struct tnode *talloc(void);
char *mitoa(int *);
void addline(struct tnode *, int *);
int noiseword(char *);

char *nw[] = {
	"a",
	"an",
	"and",
	"the",
	"are",
	"be",
	"been",
	"being",
	"did",
	"do",
	"has",
	"had",
	"have",
	"might",
	"must",
	"or",
	"should",
	"to",
	"was",
	"were",
	"which",
	"would"
};


main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int linenum = 0;

	root = NULL;
	while (getword(word, MAXWORD, &linenum) != EOF)
		if (isalpha(word[0]) && noiseword(word) == 0)
			root = addtreex(root, word, &linenum);
	treexprint(root);
	return 0;
}

int noiseword(char *word)
{
	int size = sizeof(nw) / sizeof(char *);
	int i;

	for (i = 0; i<size; i++)
		if (strcmp(nw[i], word) == 0)
			return 1;
	return 0;
}

struct tnode *addtreex(struct tnode *p, char *w, int *linenum)
{
	int cond;
	if (p == NULL) {
		p = talloc();
		p->word = mstrdup(w);
		p->refs = mitoa(linenum);
		p->left = p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0)
		addline(p, linenum);
	else if (cond < 0)
		p->left = addtreex(p->left, w, linenum);
	else 
		p->right = addtreex(p->right, w, linenum);
	return p;
}

void addline(struct tnode *p, int *linenum)
{
	char *new_line, *temp;
	int new_size;

	new_line = mitoa(linenum);
	new_size = strlen(new_line) + strlen(p->refs) + 1;
	
	temp = (char *) realloc(p->refs, new_size+1);
	strcat(temp, " ");
	strcat(temp, new_line);

	p->refs = temp;
}

char *mitoa(int *n)
{
	int size_n = *n;
	int size_nn = *n;
	int size = 0;
	char *p;
	char c;
	int i, j;

	while ((size_n /= 10) > 0)
		size++;
	
	p = (char *) malloc(size+1);
	char *s = p;
	char *s2 = p;

	do {
		*p++ = size_nn % 10 + '0';
	} while ((size_nn /= 10) > 0);
	*p++ = '\0';
	
	
	for (i = 0, j = size; i < j; i++, j--) {
		c = s2[i];
		s2[i] = s2[j];
		s2[j] = c;
	}	
	
	return s;

}

int getword(char *word, int lim, int *linenum)
{
	int c, d, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			if (*w == '\n')
				++(*linenum);
			ungetch(*w);
			break;
		}
	*w = '\0';

	return c;
}

void treexprint(struct tnode *p)
{
	if (p != NULL) {
		treexprint(p->left);
		printf("%s %s\n", p->word, p->refs);
		treexprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mstrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}

