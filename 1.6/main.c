#include <stdio.h>

main(){
	int c;
	c = getchar();
	while(c != EOF ){
		c = getchar();
		printf("%d\n", c!=EOF);
	}
}
