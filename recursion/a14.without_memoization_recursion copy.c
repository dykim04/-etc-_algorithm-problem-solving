#include <stdio.h>

int recurse(int n)
{
	int x = 1, k;

	if (n == 1)
	{
		return (x);
	}
	for (k = 1; k < n; k++)
	{
        x = x + recurse(k) * recurse(n - k);
	}
	return (x);
}

int main()
{
    int i;

    i = 0;
    while (i < 30)
    {
	    printf("[%d] %d\n",i , recurse(i));
        i++;
    }
	return (0);
}