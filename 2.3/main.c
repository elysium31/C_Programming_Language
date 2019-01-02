#include <stdio.h>

#define MAXLINE 80

int htoi(char s[]){
    int i, len;
	len = 0;

	while(s[len] != '\0')
		++len;
	
    i = len - 1;
    
    if (len < 3){
        printf("Error lenght\n");
        return -1;
    } else if (!(s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))){
        printf("Hex value should start from 0x or 0X\n");
		return -1;
    }
    
    
    int result;
    int base = 1;

    while (i >= 2){
        int digit;
        if (s[i] >= '0' && s[i] <= '9')
            digit = s[i] - '0';
        else if (s[i] == 'a' || s[i] == 'A')
            digit = 10;
        else if (s[i] == 'b' || s[i] == 'B')
            digit = 11;
        else if (s[i] == 'c' || s[i] == 'C')
            digit = 12;
        else if (s[i] == 'd' || s[i] == 'D')
            digit = 13;
        else if (s[i] == 'e' || s[i] == 'E')
            digit = 14;
        else if (s[i] == 'f' || s[i] == 'F')
            digit = 15;
        else {
            printf("Parse error: %d\n", i);
            return -1;
        }
        result += base*digit;
        base = base * 16;
        i--;
        
    }
    
    return result;
    
}

int main(){
    int i;
    char c;
    char s[MAXLINE];

    for(i = 0; i<MAXLINE-1 && (c=getchar())!=EOF && c!= '\n'; ++i)
        s[i] = c;
    s[i] = '\0';
    printf("%d\n", htoi(s));
}
