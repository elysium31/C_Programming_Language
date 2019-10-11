/*
Write a progran that reads a C program and prints in alphabeti=
cal order each group of variale names that are identical in the first 6 charac-
ters, but different somewhere thereafter. Don't count words within strings and
comments. Make 6 a paramneter that can be set from the command line.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "getch.h"

#define MAXWORD 100

struct tnode {
	char *word;
	int match;
	struct tnode *left;
	struct tnode *right;
};

int getword(char *, int);
struct tnode *addtreex(struct tnode *, char *, int *, int);
void treexprint(struct tnode *);
int compare(char *, struct tnode *, int *, int);
char *mstrdup(char *);
struct tnode *talloc(void);

main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int num;
	
	num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;

	int match = 0;
	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]) && strlen(word) >= num)
			root = addtreex(root, word, &match, num);
		match = 0;
	treexprint(root);
	return 0;
}

struct tnode *addtreex(struct tnode *p, char *w, int *match, int num)
{
	int cond;
	if (p == NULL) {
		p = talloc();
		p->word = mstrdup(w);
		p->match = *match;
		p->left = p->right = NULL;
	} else if ((cond = compare(w, p, match, num)) < 0)
		p->left = addtreex(p->left, w, match, num);
	else if (cond > 0)
		p->right = addtreex(p->right, w, match, num);
	return p;
}

int compare(char *s, struct tnode *p, int *match, int num)
{
	char *t = p->word;
	int i;

	for (i = 0; *s == *t; s++, t++, i++)
		if (*s == '\0')
			return 0;

	if (i > num){
		p->match = 1;
		*match = 1;
	}
	return *s - *t;
}

int getword(char *word, int lim)
{
	int c, d, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	
	if (c  == '/')
		if ((d = getch()) =='*')
			while((c = getch()) != EOF)
				if ((c = getch()) == '*')
					if ((c = getch()) == '/')
						break;
					else
						ungetch(c);
		else
			ungetch(d);		
	if (c == '\'' || c == '"')
		while ((d = getch()) != EOF)
			if (d == c){
				c = getch();
				break;
			}
    if (isalnum(c) || c == '_' || c == '#'){	
		for ( ; --lim > 0; w++)
			if (!isalnum(*w = getch()) && *w != '_') {
				ungetch(*w);
				break;
			}
	}
	*w = '\0';
	return c;
}

void treexprint(struct tnode *p)
{
	if (p != NULL) {
		treexprint(p->left);
		if (p->match)
			printf("%s\n", p->word);
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

