# include "stdio.h"

int main (void)
{
	int n = 6;
	double x = 5.8721;

	x += 0.2;
	printf("%d\n", (int)x);

//	closer to next > facing east
	if ((int)(x + 0.5) == (int)(x + 1))
		return (4);
	else
		return (2);
}