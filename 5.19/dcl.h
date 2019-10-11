#define MAXTOKEN 100

void dcl(void);
void dirdcl(void);
int gettoken(void);
int getnexttoken(void);
void errmsg(char *);

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

enum { NAME, PARENS, BRACKETS };
