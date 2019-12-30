/*
Write a program that prints the distinct words in its input sorted
into decreasing order of frequency of occurrence. Precede each word by its count.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "getch.h"

#define MAXWORD 100
#define NUM 100

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

int getword(char *, int);
struct tnode *addtreex(struct tnode *, char *, int *);
char *mstrdup(char *);
struct tnode *talloc(void);
void listtree(struct tnode **, struct tnode *);
void printlist(struct tnode **, int);
int compare_tnode(const void *, const void *);

main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	struct tnode **list;

	int tree_size = 0;

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtreex(root, word, &tree_size);
	printf("tree size = %d\n", tree_size);
	list = (struct tnode **) malloc(tree_size * sizeof(struct tnode *));
	listtree(list, root);
	qsort(list, tree_size, sizeof(struct tnode *), compare_tnode);
	printlist(list, tree_size);
	return 0;
}

void listtree(struct tnode **l, struct tnode *t)
{
	static int i = 0;
	if (t != NULL){
		listtree(l, t->left);
		l[i++] = t;
		listtree(l, t->right);
	}
}

int compare_tnode(const void *a, const void *b)
{
	const struct tnode *A = *(struct tnode * const *)a;
	const struct tnode *B = *(struct tnode * const *)b;
	return B->count - A->count;
}

void printlist(struct tnode **l, int size)
{
	int i;
	for (i = 0; i < size; i++){
		printf("%s %d\n", l[i]->word, l[i]->count);
	}
}


struct tnode *addtreex(struct tnode *p, char *w, int *tree_size)
{
	int cond;
	if (p == NULL) {
		p = talloc();
		p->word = mstrdup(w);
		p->count = 1;
		p->left = p->right = NULL;
		++(*tree_size);
	} else if ((cond = strcmp(w, p->word)) == 0)
		++p->count;
	else if (cond < 0)
		p->left = addtreex(p->left, w, tree_size);
	else 
		p->right = addtreex(p->right, w, tree_size);
	return p;
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
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';

	return c;
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

