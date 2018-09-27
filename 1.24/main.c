/*
Write a program to check a C program for rudimentary syntax
errors like unbalanced parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This pro-
gram is hard if you do it in full generality.)
*/

#include <stdio.h>

#define MAXLINE 1000

void get_line(void);
void check(void);

char line[MAXLINE];

main()                                                                                                        
 {                                                                                                             
     int len;                                                                                                  
                                                                                                                
     while (1){                                                                                                
         get_line();                                                                                           
         check();                                                                                          
     }                                                                                                         
     return 0;                                                                                                 
 }                                                                                                             
                                                                                                                
 void get_line(void)                                                                                           
 {                                                                                                             
     int c, i;                                                                                                 
     extern char line[];                                                                                       
                                                                                                                
     for (i = 0; i < MAXLINE-1 && (c=getchar()) != EOF; ++i)                                                   
         line[i] = c;                                                                                          
     line[i] = '\0';                                                                                           
 }  

 void check(void){
	int parentheses, brackets, braces, single_quotes, double_quotes, comment, comment_inline;
	parentheses = 0;
	brackets = 0;
	braces = 0;
	single_quotes = 0;
	double_quotes = 0;
	comment = 0;
	comment_inline = 0;
	char c;
	char previous_c;
	previous_c = 0;
	
	int i;
	i = 0;

	while(line[i] != '\0'){
		c = line[i];
		if (previous_c == '\\'){
			i++;
			previous_c = c;
			continue;
		}

		if(previous_c == '/' && c == '*')
			comment = 1;

		if (previous_c == '*' && c == '/')
			comment = 0;

		if (previous_c == '/' && c == '/')
			comment_inline = 1;

		if (c == '\n')
			comment_inline = 0;

		if (comment == 0 && comment_inline == 0){
			if (c == '(' && double_quotes == 0 && single_quotes == 0)
				++parentheses;
			else if (c == '[' && double_quotes == 0 && single_quotes == 0)
				++brackets;
			else if (c == '{' && double_quotes == 0 && single_quotes == 0)
				++braces;
			else if (c == '"' && single_quotes == 0){
				if (double_quotes == 0)
					double_quotes = 1;
				else if (double_quotes == 1)
					double_quotes = 0;
				}
			else if (c == '\'' && double_quotes == 0){
				if (single_quotes == 0)
					single_quotes = 1;
				else if (single_quotes == 1)
					single_quotes = 0;
				}
			else if (c == ')' && single_quotes == 0 && double_quotes == 0)
				--parentheses;
			else if (c == ']' && single_quotes == 0 && double_quotes == 0)
				--brackets;
			else if (c == '}' && single_quotes == 0 && double_quotes == 0)
				--braces;
		}
		previous_c = c;
		++i;

	}
	if (parentheses == 0 && brackets == 0 && braces == 0 && double_quotes == 0 && single_quotes == 0)
		printf("\nAll ok!\n");
	else
		{
			printf("\nSomething wrong\n");
			if (parentheses != 0)
				printf("\nMissed parenthes: %d\n", parentheses);
			if (brackets != 0)
				printf("\nMissed bracker: %d \n", brackets);
			if (braces != 0)
				printf("\nMissed brace: %d\n", braces);
			if (double_quotes != 0)
				printf("\nMissed double quote\n");
			if (single_quotes != 0)
				printf("\nMissed single quote\n");
		}
}
