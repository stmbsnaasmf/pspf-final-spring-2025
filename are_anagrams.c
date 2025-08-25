#include <stdio.h>
#include <stdbool.h>

int getStringLength(char* str)
{
	int length = 0, index = 0;
	while ('\0' != str[index])
	{
		length++;
		index++;
	}
	return length;
}

bool areAnagrams(char* strOne, char* strTwo)
{
	int frequencyOne[128] = {0};
	int frequencyTwo[128] = {0};

	for (int i = 0; i < getStringLength(strOne); i++)
	{
		frequencyOne[strOne[i]]++;
	}

	for (int i = 0; i < getStringLength(strTwo); i++)
	{
		frequencyTwo[strTwo[i]]++;
	}

	for (int i = 0; i < 128; i++)
	{
		printf("%d: %d\t%d\n", i, frequencyOne[i], frequencyTwo[i]);
	}

	for (int i = 0; i < 128; i++)
	{
		if (frequencyOne[i] != frequencyTwo[i])
		{
			return false;
		}
	}

	return true;
}

int main(void)
{
	char strOne[] = "silent\0";
	char strTwo[] = "listen\0";

//	printf("Length of \"%s\" is %d.\n", strOne, getStringLength(strOne));
	
	if (areAnagrams(strOne, strTwo))
	{
		printf("%s and %s are anagrams.\n", strOne, strTwo);
	}
	
	return 0;
}