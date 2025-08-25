#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isSudokuRowValid(int** matrix, int rowNo);
bool isSudokuColValid(int** matrix, int colNo);
bool isSudokuSubMatrixValid(int** matrix, int matrixNo);
bool isSudokuValid(int** matrix);
void printSudoku(int** matrix);

int main()
{
	int arr[] = { 9, 3, 0, 0, 7, 0, 0, 0, 0,
				  6, 0, 0, 1, 9, 5, 0, 0, 0,
				  0, 5, 8, 0, 0, 0, 0, 6, 0,
				  8, 0, 0, 0, 6, 0, 0, 0, 3,
				  4, 0, 0, 8, 0, 3, 0, 0, 1,
				  7, 0, 0, 0, 2, 0, 0, 0, 6,
				  0, 6, 0, 0, 0, 0, 2, 8, 0,
				  0, 0, 0, 4, 1, 9, 0, 0, 5,
				  0, 0, 0, 0, 8, 0, 0, 7, 9 };

	int brr[] = { 9, 3, 0, 0, 7, 0, 0, 3, 0,
				  6, 0, 0, 1, 9, 5, 0, 0, 0,
				  0, 5, 8, 0, 0, 0, 0, 6, 0,
				  8, 0, 0, 0, 6, 0, 0, 0, 3,
				  4, 0, 0, 8, 0, 3, 0, 0, 1,
				  7, 0, 0, 0, 2, 0, 0, 0, 6,
				  9, 6, 0, 0, 0, 0, 2, 8, 0,
				  0, 0, 0, 4, 1, 9, 7, 0, 5,
				  0, 0, 0, 0, 8, 0, 0, 7, 9 };

	int** matrix = (int**) malloc(9 * sizeof(int*));
	for (int i = 0; i < 9; i++)
	{
		matrix[i] = (int*) malloc (9 * sizeof(int));
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			matrix[i][j] = arr[i * 9 + j];
		}
	}
	
	printSudoku(matrix);
	isSudokuValid(matrix);
	printf("\n");
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			matrix[i][j] = brr[i * 9 + j];
		}
	}
	
	printSudoku(matrix);
	isSudokuValid(matrix);

	for (int i = 0; i < 9; i++)
	{
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}

void printSudoku(int** matrix)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

bool isSudokuValid(int** matrix)
{
	bool isValid = true;

	for (int i = 0; i < 9; i++)
	{
		if (!isSudokuRowValid(matrix, i))
		{
			printf("Row %d is invalid.\n", i);
			isValid = false;
		}

		if (!isSudokuColValid(matrix, i))
		{
			printf("Col %d is invalid.\n", i);
			isValid = false;
		}

		if (!isSudokuSubMatrixValid(matrix, i))
		{
			printf("submatrix %d is invalid.\n", i);
			isValid = false;
		}
	}

	return isValid;
}

bool isSudokuColValid(int** matrix, int colNo)
{
//	for (int i = 0; i < 9; i++)
//	{
//		int number = matrix[i][colNo];
//
//		for (int j = 0; j < i; j++)
//		{
//			if (number != 0 && matrix[j][colNo] == number)
//			{
//				return false;
//			}
//		}
//	}

	return true;
}

bool isSudokuRowValid(int** matrix, int rowNo)
{
//	for (int i = 0; i < 9; i++)
//	{
//		int number = matrix[rowNo][i];
//
//		for (int j = 0; j < i; j++)
//		{
//			if (number != 0 && matrix[rowNo][j] == number)
//			{
//				return false;
//			}
//		}
//	}

	return true;
}

bool isSudokuSubMatrixValid(int** matrix, int subMatrixNo)
{
//	int rowStartNo = 0;
//
//	if (0 == subMatrixNo || 1 == subMatrixNo || 2 == subMatrixNo)
//	{
//		rowStartNo = 0;
//	}
//	else if(3 == subMatrixNo || 4 == subMatrixNo || 5 == subMatrixNo)
//	{
//		rowStartNo = 3;
//	}
//	else if(6 == subMatrixNo || 7 == subMatrixNo || 8 == subMatrixNo)
//	{
//		rowStartNo = 6;
//	}
//
//	int subMatrixValues[9];
//	int index = 0;
//		
//	for (int i = rowStartNo; i < rowStartNo + 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			int number = matrix[i][j + 3 * (subMatrixNo % 3)];
//			subMatrixValues[index++] = number;
//		}
//	}
//		
//	bool isValid = true;
//	
//	for (int i = 0; i < 9; i++)
//	{
//		int number = subMatrixValues[i];
//		
//		for (int j = 0; j < i; j++)
//		{
//			if (number != 0 && subMatrixValues[j] == number)
//			{
//				return false;
//			}
//		}
//	}
	
	return true;
}