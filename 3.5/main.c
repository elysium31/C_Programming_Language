/* Write the function itob(n, s, b) that converts the integer n
into a base b character representation in the string s. In particular,
itob(n, s, 16) formats n as a hexadecimal integer in s.
*/

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char s[])
{
        int c, i, j;

        for (i = 0, j = strlen(s)-1; i < j; i++, j--)
                c = s[i], s[i] = s[j], s[j] = c;
}


void itob2(int n, char s[], int b){
	int i = 0;
	int reminder;
	char c;
	do {
	     reminder = n % b;
		 switch (reminder){
			case 10: 
				c = 'A'; 
				break;
			case 11: 
				c = 'B'; 
				break;
			case 12:	
				c = 'C';
				break;
			case 13: 
				c = 'D';
				break;
			case 14: 
				c = 'E';
				break;
			case 15: 
				c = 'F';
				break;
			default:
				c= n % b + '0';
				break;
		}
		 s[i++] = c;
	} while ((n /= b) > 0);
   s[i] = '\0';
   reverse(s);
}

int main(){
	char s[MAXLINE];
	itob2(42, s, 16);
	printf("%s\n", s);
	itob2(42, s, 8);
	printf("%s\n", s);
	itob2(42, s, 2);
	printf("%s\n", s);
}

