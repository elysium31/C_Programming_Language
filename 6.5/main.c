/*
Write a function undef that will remove a name and definition
from the table maintained by lookup and install.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};

static struct nlist *hashtab[HASHSIZE];
struct nlist *lookup(char *);
char *mstrdup(char *);
int undef(char *);

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

char *mstrdup(char *s)
{
        char *p;

        p = (char *) malloc(strlen(s)+1);
        if (p != NULL)
                strcpy(p, s);
        return p;
}

int undef(char *name)
{
	struct nlist *np;
	struct nlist *prev = NULL;

	unsigned hashval = hash(name);

	for (np=hashtab[hashval]; np != NULL; np = np->next)
		if (strcmp(name, np->name) == 0){
			if (prev != NULL)
				prev->next = np->next;
			else
				hashtab[hashval] = np->next;
			free(np->name);
			free(np->defn);
			free(np);
			return 1;
		}
		prev = np;
	return 0;
}

main(){
	struct nlist *np;
	install("IN", "1");
	np = lookup("IN");
	printf("np->name=%s, np->defn=%s\n", np->name, np->defn);
	undef("IN");
	np = lookup("IN");	
	printf("np=%d\n", np==NULL);
}

