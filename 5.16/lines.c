#include "lines.h"

char *alloc(int n)                                                                                            
{                                                                                                             
    if (allocbuf + MAXLEN * MAXLINES - allocp >= n) {                                                         
        allocp += n;                                                                                          
        return allocp - n;                                                                                    
    }                                                                                                         
    else                                                                                                      
        return 0;                                                                                             
}                                                                                                             
                                                                                                              
void writelines(char *lineptr[], int nlines)                                                           
{                                                                                                             
	int i;                                                                                                              
    for (i = 0; i < nlines; i++)                                                                          
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
