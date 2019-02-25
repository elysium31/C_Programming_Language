/* Write a function expand(s1, s2) that expands shorthand nota-
tions like a-z in the equivalent complete list abc..xyz in
s2. Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is 
taken literally.
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void expand(char s1[], char s2[]){
	int lenght = strlen(s1);
	int k = 0;

	for (int i = 0; i <= lenght; i++)
		if(s1[i+1] == '-' && i + 3 <= lenght && s1[i] < s1[i+2] && 
		   ((s1[i] >= 'A' && s1[i] <= 'Z' && s1[i+2] >= 'A' && s1[i+2] <= 'Z') ||
		   (s1[i] >= 'a' && s1[i] <= 'a' && s1[i+2] >= 'a' && s1[i+2] <= 'z') ||
		   (s1[i] >= '0' && s1[i] <= '9' && s1[i+2] >= '0' && s1[i+2] <= '9'))){
			for(char j=s1[i]; j<=s1[i+2]; j++)
					s2[k++] = j;			
			i += 2;
		}
		else {
			s2[k++] = s1[i];
		}
	
	s2[k] = '\0';
}

int main(){
	char s1_0[MAXLINE] = "a-z\0";
	char s1_1[MAXLINE] = "a-b-c\0";
	char s1_2[MAXLINE] = "a-z0-9\0";
	char s1_3[MAXLINE] = "-a-z\0";
	char s2[MAXLINE];
	expand(s1_0, s2);
	printf("%s: %s\n", s1_0, s2);	
	expand(s1_1, s2);
	printf("%s: %s\n", s1_1, s2);	
	expand(s1_2, s2);
	printf("%s: %s\n", s1_2, s2);	
	expand(s1_3, s2);
	printf("%s: %s\n", s1_3, s2);
}
