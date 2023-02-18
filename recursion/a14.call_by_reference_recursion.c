int recurse(int &x, int c)
{
	c = c - 1;

	if (c == 0)
	{
		return (1);
	}
	x = x + 1;

	return (recurse(x, c) * x);
}

#include <stdio.h>
int main()
{
	int p = 5;

	printf("%d\n", recurse(p, p));
	return (recurse(p, p));
}