#include <stdio.h>
#include <stdbool.h>s

int getFactorial(int n);
int factorial(int n, int accumulator);	//Tail recursive
bool isStrongNumber(int n);

int main(void)
{
	isStrongNumber(1);
	isStrongNumber(2);
	isStrongNumber(145);
	isStrongNumber(40585);
	isStrongNumber(45);
	
	return 0;
}

bool isStrongNumber(int n)
{
	int originalN = n;
	int digit = n % 10;
	int sumOfFactorialsOfDigits = getFactorial(digit);

	while (n != 0)
	{
		n = n / 10;
		digit = n % 10;
		sumOfFactorialsOfDigits += getFactorial(digit);
	}
	
	sumOfFactorialsOfDigits = sumOfFactorialsOfDigits - 1;
	
	if (originalN == sumOfFactorialsOfDigits)
	{
//		printf("%d is a strong number.\tSum of factorials of digits = %d\n", originalN, sumOfFactorialsOfDigits);
		printf("Yes\n");
	}
	else
	{
//		printf("%d is not a strong number.\tSum of factorials of digits = %d\n", originalN, sumOfFactorialsOfDigits);
		printf("No\n");
	}
}

int getFactorial(int n)
{
	return factorial(n, 1);
}

int factorial(int n, int accumulator)
{
	if (n <= 1)
	{
		return accumulator;
	}
	else
	{
		return factorial(n - 1, accumulator * n);
	}
}

