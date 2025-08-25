#include <stdio.h>

int countWords(char* str)
{
	int count = 0;
	int index = 0;
	
	while (str[index] != '\0')
	{
		index++;
		char c = str[index];
		
		if (c == '\0' || c == ' ' )
		{
			count++;
		}
	}
	
	return count;
}

int main()
{
	char str[] = "This paragraph has 23 words. It contains letters, numbers, punctuation marks, spaces and last but not least, the null character at the end!\0";

	printf("The string contains %d words.\n", countWords(str));

	return 0;
}