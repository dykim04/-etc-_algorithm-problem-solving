// o/p (output)
// [1] 312213444
// [2] 312111222
// [3] 312213432
// [4] 312213432
// [5] 312213432
// [6] 312213432

// [1]
#include <stdio.h>

void count(int n)
{
	static int d = 1;
	printf("%d", n);
	printf("%d", d);
	d++;
	if (n > 1)
		count(n - 1);
	printf("%d", d);
}

int main()
{
	count(3);

	return (0);
}

// [2]
#include <stdio.h>

void count(int n)
{
	static int d;
	d = 1;
	printf("%d", n);
	printf("%d", d);
	d++;
	if (n > 1)
		count(n - 1);
	printf("%d", d);
}

int main()
{
	count(3);

	return (0);
}

// [3]
#include <stdio.h>

void count(int n, static int d)
{
	printf("%d", n);
	printf("%d", d);
	d++;
	if (n > 1)
		count(n - 1, d);
	printf("%d", d);
}

int main()
{
	static int d = 1;

	count(3, d);

	return (0);
}

// [4]
#include <stdio.h>
void count(int n, static int d)
{
	printf("%d", n);
	printf("%d", d);
	d++;
	if (n > 1)
		count(n - 1, d);
	printf("%d", d);
}

int main()
{
	static int d;
	d = 1;

	count(3, d);

	return (0);
}

// [5]
#include <stdio.h>

int d = 1; 

void count(int n, static int d)
{
	printf("%d", n);
	printf("%d", d);
	d++;
	if (n > 1)
		count(n - 1, d);
	printf("%d", d);
}

int main()
{
	count(3, d);

	return (0);
}

// [6]
#include <stdio.h>
void count(int n, static int d)
{
	printf("%d", n);
	printf("%d", d);
	d++;
	if (n > 1)
		count(n - 1, d);
	printf("%d", d);
}

int main()
{
	static int d = 1;
	count(3, d);

	return (0);
}