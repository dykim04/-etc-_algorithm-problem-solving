
#include <stdio.h>

unsigned long long recurse(unsigned long long n);

unsigned long long memoization(unsigned long long k, unsigned long long buff[])
{
	buff[k] = recurse(k);

	return (buff[k]);
}

unsigned long long recurse(unsigned long long n)
{
	static unsigned long long buff[10001] = { 0, 1, 2, 0 };
	unsigned long long int x = 1, k;

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
    unsigned long long i;

    i = 1;

	// MAXIMUM CASE (int range)
    while (i < 34)
    {
	    printf("result[%lld] %lld\n",i , recurse(i));
        i++;
    }

	// MAXIMUM CASE (memory_segmentation fault)
	// while (i < 10237)
    // {
	//     printf("result[%lld] %lld\n",i , recurse(i));
    //     i++;
    // }

	return (0);
}