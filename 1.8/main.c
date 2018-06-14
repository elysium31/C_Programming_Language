#include <stdio.h>

main()
{
    int nl = 0;
    int space = 0;
    int se = 0;
    int c;
	while (( c = getchar()) != EOF)
		{
			if (c == '\n')
				++nl;
			if (c == ' ')
				++space;
			if (c == '\0')
				++se;
		}
	printf("new line: %d, space: %d, string end: %d\n", nl, space, se);
}

