/*
Write a program entab taht replaces strings of blacnks by the
minimum number of tabs and blanks to achieve the same spacing. Use the
same tab stios as for detab. when either a tab or a single blank would suffice
to reach a tab stopm which should be given preference?
*/

#include <stdio.h>

#define MAXLINE 1000
#define WIDTH 14

char line[MAXLINE];

int get_line(void);
void entab(void);

main()
{
	int len;
	extern char longest[];

	while ((len=get_line()) > 0){
		entab();
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
	char temp[MAXLINE];
	int i;
	i = 0;
	int j;
	j = 0;
	int b = -1;
	int k = 0;
	while(line[i] != '\0'){
		if (line[i] == ' ' || line[i] == '\t'){ 
			b = j;
		}
		if (k > WIDTH ){
			if (b >= 0){
				temp[b] = '\n';
				b = -1;
				k = 0;
			}
			else {
				temp[j++] = '\n';
				k = 0;
				b = -1;
								
			}
		}
		temp[j++] = line[i++];
		++k;
	}
	temp[++j] = '\0';
	printf("%s", temp);
}
