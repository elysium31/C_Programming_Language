#include <stdio.h>

#define swap(t, x, y) { t tmp; \
                        tmp = x; \ 
						x = y; \
						y = tmp; } \


main()
{
	int x = 5;
	int y = 7;
	printf("%d %d\n", x, y);
	swap(int, x, y);
	printf("%d %d\n", x, y);
}
