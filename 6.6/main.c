/*
Implemnt a simple version of the #define processor (i.e., no 
arguments) suitable for use with C programs, based on the routines of this sec-
tion. You may also find getch and ungetch helpful.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "getch.h"
#include "mstrdup.h"

#define HASHSIZE 101
#define MAXWORD 100

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];
struct nlist *lookup(char *);
void setup();

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np ->name = mstrdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np-> defn);
    if ((np->defn = mstrdup(defn)) == NULL)
        return NULL;
    return np;
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

void setup()
{
	char define[MAXWORD], name[MAXWORD], defn[MAXWORD];
	char c;
	int i = 0;
	getword(define, MAXWORD);
	if (strcmp(define, "define") == 0){
		getword(name, MAXWORD);

		while(isspace(c = getch()))
			;
		if (c != EOF)
			defn[i++] = c;
		for ( ; i < MAXWORD-1; i++)
			if((c = getch()) != EOF && c != '\n')
				defn[i] = c;
			else
				break;
		defn[i] = '\0';
		if (i > 0)
			install(name, defn);
	}
		
}

main()
{
	char word[MAXWORD];
	struct nlist *p;

	while(getword(word, MAXWORD) != EOF){
		if (word[0] == '#')
			setup(word);
		else if ((p = lookup(word)) != NULL)
			printf("%s", p->defn);
		else
			printf("%s", word);
	}	
}

