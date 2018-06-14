#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_CHARS 128

main(){
	int c;
	int i;
	int chars[MAX_CHARS];
	
	for (i = 0; i < MAX_CHARS - 1; i++)
		chars[i] = 0;
	
	while((c = getchar()) != EOF){
		chars[c]++; 
	}

	for(i=0; i < MAX_CHARS - 1; i++){
		if (chars[i] > 0)
			printf("%c : %d\n", i, chars[i]);
	}


}
