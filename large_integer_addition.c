#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int getStringLength(char* str);
char* pad(char* str, int stringSize, char paddingChar);

char* add(char* numOne, char* numTwo, char* result, int stringSize)
{
	bool toCarry = false;

	for (int i = stringSize - 2; i >= 0; i--)
	{
		char c = (numOne[i] - 48) + (numTwo[i] - 48);

		if (true == toCarry)
		{
			c = c + (49 - 48); //Add char(1) and do not forget to subtract ASCII-48
			toCarry = false;
		}

		if (c > 9)
		{
			toCarry = true;
			c = c % 10;
		}

		result[i] = c + 48;
	}

	result[stringSize - 1] = '\0';

	return result;	
}


int main(void)
{
	char smallWithoutCarryOne[20] = "14\0";
	char smallWithoutCarryTwo[20] = "14\0";
	
	char smallWithCarryOne[20] = "15\0";
	char smallWithCarryTwo[20] = "15\0";
	
	char mediumOne[20] = "109876201453\0";	//Ans: 111079211407
	char mediumTwo[20] = "1203009954\0";

	char largeOne[20] = "999999999999999999\0";	//Ans: 1999999999999999998
	char largeTwo[20] = "999999999999999999\0";

	char largeOverFlowOne[20] = "9999999999999999999\0";	//Actual ans: 19999999999999999998
	char largeOverflowTwo[20] = "9999999999999999999\0";	//Our ans: 9999999999999999998

	char result[20];	


	pad(smallWithoutCarryOne, 20, '0');
	pad(smallWithoutCarryTwo, 20, '0');
	printf("%s\n", add(smallWithoutCarryOne, smallWithoutCarryTwo, result, 20));

	pad(smallWithCarryOne, 20, '0');
	pad(smallWithCarryTwo, 20, '0');
	printf("%s\n", add(smallWithCarryOne, smallWithCarryTwo, result, 20));

	pad(mediumOne, 20, '0');
	pad(mediumTwo, 20, '0');
	printf("%s\n", add(mediumOne, mediumTwo, result, 20));

	pad(largeOne, 20, '0');
	pad(largeTwo, 20, '0');
	printf("%s\n", add(largeOne, largeTwo, result, 20));

	pad(largeOverFlowOne, 20, '0');
	pad(largeOverflowTwo, 20, '0');
	printf("%s\n", add(largeOverFlowOne, largeOverflowTwo, result, 20));

	return 0;
}

char* pad(char* str, int stringSize, char paddingChar)
{
	int noOfRightShifts = stringSize - getStringLength(str) - 1;
	int stringLength = getStringLength(str);

	for (int i = stringSize - 2; i >= 0; i--)
	{
		str[i] = str[i - noOfRightShifts];
	}

	for (int i = 0; i < noOfRightShifts; i++)
	{
		str[i] = paddingChar;
	}

	str[stringSize - 1] = '\0';

	return str;
}

int getStringLength(char* str)
{
	int stringLength = 0;
	int index = 0;

	while (str[index] != '\0')
	{
		stringLength++;
		index++;
	}

	return stringLength;
}