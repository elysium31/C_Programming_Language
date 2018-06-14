#include <stdio.h>

main(){
    int c;
    int prev;
    while((c = getchar()) != EOF){
        if (prev != ' '){
            putchar(c);
        }
        prev = c;
    }
}
