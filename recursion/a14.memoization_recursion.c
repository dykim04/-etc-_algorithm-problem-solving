#include <stdio.h>

int recurse(int n);

int memoization(int k, int buff[])
{
	buff[k] = recurse(k);

	return (buff[k]);
}

int recurse(int n)
{
	static int buff[10001] = { 0, 1, 2, 0 };
	int x = 1, k;

	if (n == 1)
	{
		return (x);
	}
	for (k = 1; k < n; k++)
	{
		if (buff[k])
		{
			if (buff[n - k])
			{
				x = x + buff[k] * buff[n - k];
			}
			else
			{
				x = x + buff[k] * recurse(n - k);
			}
		}
		else
		{
			if (buff[n - k])
			{
				x = x + memoization(k, buff) * memoization(n - k, buff);
			}
			else
			{
				x = x + memoization(k, buff) * memoization(n - k, buff);
			}
		}
	}
	return (x);
}

int main()
{
    int i;

    i = 0;
    while (i < 20)
    {
	    printf("[%d] %d\n",i , recurse(i));
        i++;
    }
	return (0);
}