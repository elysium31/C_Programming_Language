#include <stdio.h>

#define IN 1
#define OUT 2

main()
{
	int c, state;
    state = IN;
	
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t'){
			if (state != OUT){
				printf("\n");
				state = OUT;
			}
		}
		else {
			printf("%c", c);
			state = IN;
		}	
		
	}
}
