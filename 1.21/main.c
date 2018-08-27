/*
Write a program entab taht replaces strings of blacnks by the
minimum number of tabs and blanks to achieve the same spacing. Use the
same tab stios as for detab. when either a tab or a single blank would suffice
to reach a tab stopm which should be given preference?
*/

#include <stdio.h>

#define MAXLINE 1000
#define TAB_SPACES 4

char line[MAXLINE];

int get_line(void);
void entab(void);

main()
{
	int len;
	extern char longest[];

	while ((len=get_line()) > 0){
		entab();
		printf("%s", line);
	}
	return 0;
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

void entab(void)
{
	int i, j, k;
	char temp[MAXLINE];
	extern char line[];

	i = 0;
	while ((temp[i] = line[i]) != '\0')
		++i;
	j = 0;
	for (i=0; i < MAXLINE - 1; ++i)
	{
		if (temp[i] == '\0')
			break;
		
		if (temp[i] == ' '){
			int t, k;
			int tab;
			tab = 1;
			t = i;
			for (k = 0; k  < TAB_SPACES - 1 && t < MAXLINE; ++k){
				if (temp[++t] != ' '){
					tab = 0;
					break;
				};
			
			}
			if (tab == 1) {
				printf("detabing\n");
				line[j++] = '\t';
				i = i + TAB_SPACES - 1;
			}
			else
				line[j++] = ' ';
		}
		else
			line[j++] = temp[i];
	}
	line[j++] = '\0';
}
