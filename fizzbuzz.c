#include <stdio.h>

void fizzbuzz(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0)
		{
			printf("fizz");
		}
		if (i % 5 == 0)
		{
			printf("buzz");
		}
		if (!(i % 3 == 0 || i % 5 == 0))
		{
			printf("%d", i);
		}
		printf("\n");
	}
}

int main()
{
	fizzbuzz(100);

	return 0;
}