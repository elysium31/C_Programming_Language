#include <stdio.h>

#define IN 1
#define OUT 0
#define SIZE 20

main(){
	int c, i, state, wlength;
	state = IN;
    wlength = 0;
	int length[SIZE];
	for(i=0; i < SIZE; ++i)
		length[i] = 0;
	while((c=getchar()) != EOF){
		if (c == ' ' || c == '\n' || c == '\t'){
			if (state == IN)
				++length[wlength];
				wlength = 0;
			state = OUT;
		} else {
			state = IN;
            ++wlength;
		}	
	}
	// Horizontal histogram
	int y;
	for(i=0; i<SIZE; ++i)	{
	    printf("%d: ", i);
	    for(y=0; y<length[i]; ++y){
			printf("=");
		}
		printf("\n");
	}
	printf("Vertical");
	// Vertical histogram
	// find max value
	int max_val = 0;
	int max_pos = 0;
	for(i=0; i<SIZE; ++i){
		if(length[i]>max_val){
			max_val = length[i];
			max_pos = i;
		}			
	}
	printf("Max val - %d", max_val);
	for(i=max_val; i>=0; --i)
	{
		for(y=0; y<SIZE; y++)	{
			if(length[y]>=i && i != 0){
				printf("|");
			}
			else {
				printf(" ");
			}
				
		}
		printf("\n");
	}




}
