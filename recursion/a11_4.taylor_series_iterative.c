#include <stdio.h>

double e(int x, int n)
{
	double s = 1;
	
	while (n > 0)
	{
		s = 1 + (x * s) / n;
        n--;
    }

    return (s);
}

int main()
{
    int n;
    while (n++ < 10)
	    printf("[%d] %lf\n", n, e(2, n));
	
	return (0);
}