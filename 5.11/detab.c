#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TAB_SPACES 4

char line[MAXLINE];

int get_line(void);
void detab(char *tab);
void fill_tabs(int argc, char *argv[], char *tab);

main(int argc, char *argv[])
{
        int len;
        extern char longest[];

        char tab[MAXLINE];

        fill_tabs(argc, argv, tab);

        while ((len=get_line()) > 0){
                detab(tab);
                printf("%s", line);
        }
        return 0;
}


void fill_tabs(int argc, char *argv[], char *tab)
{
        int i, pos;
        for(i = 0; i<MAXLINE-1; i++)
                tab[i] = 0;
        
        if (argc <=1)
                for(i = TAB_SPACES-1; i<MAXLINE-1; i+=TAB_SPACES)
                        tab[i] = 1;
        else {
                while(--argc > 0){
                        pos = atoi(*++argv) - 1;
                        if (pos > 0 && pos < MAXLINE - 1)
                                tab[pos] = 1;
                }
        }
}

char is_tab(int pos, char *tab)
{
        if (pos > 0 && pos < MAXLINE)
                return tab[pos];
        else
                return -1;
}

int get_line(void)
{
        int c, i;
        extern char line[];

        for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n'; ++i)
                line[i] = c;
        if (c == '\n') {
                line[i] = c;
                ++i;
        }
        line[i] = '\0';
        return i;
}

void detab(char *tab)
{
        int i, j, k;
        char temp[MAXLINE];
        extern char line[];

        i = 0;
        while ((temp[i] = line[i]) != '\0')
                ++i;
        j = 0;
		k = 0;
        for (i=0; i < MAXLINE - 1; ++i)
        {
			if (temp[i] == '\0')
				break;
                
            if (temp[i] == '\t'){
				do {
					line[j] = '*';
				} while (is_tab(j++, tab) == 0);
			}
            else
                line[j++] = temp[i];
        }
        line[j++] = '\0';
}

