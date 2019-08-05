#include <stdio.h>                                                                                            
#include <string.h>

#define MAXLEN 100                                                                                            
#define MAXLINES 60                                                                                           
                                                                                                              
static char allocbuf[MAXLEN * MAXLINES];                                                                      
static char *allocp = allocbuf;                                                                               
                                                                                                              
int get_line(char *, int);                                                                                    
int readlines(char *lineptr[], int nlines);                                                                   
void writelines(char *lineptr[], int nlines);

char *lineptr[MAXLINES];

