#include <stdio.h>
#include <stdlib.h>

void printSnake(int** matrix, int noOfRows, int noOfCols)
{
	for (int i = 0; i < noOfRows; i++)
	{
		for (int j = 0; j < noOfCols; j++)
		{
			if (i % 2 == 0)
			{
				printf("%d\t", matrix[i][j]);
			}
			else
			{
				printf("%d\t", matrix[i][noOfCols - j - 1]);
			}
		}

		printf("\n");
	}
}

int main()
{
	int noOfRows = 4, noOfCols = 4;
	int arr[] = {1, 2, 3, 4,
				 5, 6, 7, 8,
				 9, 10, 11, 12,
				 13, 14, 15, 16};

	int** matrix = (int**) malloc(noOfRows * sizeof(int*));
	for (int i = 0; i < noOfRows; i++)
	{
		matrix[i] = (int*) malloc (noOfCols * sizeof(int));
	}

	for (int i = 0; i < noOfRows; i++)
	{
		for (int j = 0; j < noOfCols; j++)
		{
			matrix[i][j] = arr[i * noOfCols + j];
		}
	}

	printSnake(matrix, 4, 4);

	for (int i = 0; i < noOfRows; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	//Do not forget to free the dynamically allocated memory.

	return 0;
}