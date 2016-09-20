#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#define MAX_NUMBER_OF_ARGUMENT 2
#define EXIT_ERROR 1
#define NUMBER_OF_ROWS_OF_MATRIX 3
#define NUMBER_OF_COLUMNS_OF_MATRIX 3


using namespace std;
typedef double Matrix[NUMBER_OF_ROWS_OF_MATRIX][NUMBER_OF_COLUMNS_OF_MATRIX];

void ReadMatrixInFile(ifstream &input, Matrix &matrix);
void FormingAnInverseMatrix(Matrix &matrix, Matrix &newMatrix, const double &determinant);
void PrintAnInverseMatrix(Matrix &newMatrix);
bool NeedReplaceSign(const int &numberOfColumn, const int &numberOfRow);
double FindDeterminant(const double &a11, const double &a12, const double &a21, const double &a22);
double FindMinor(Matrix &matrix, const int &i, const int &j);
double FindDeterminantOfOriginalMatrix(Matrix &matrix);

void ReadMatrixInFile(ifstream &input, Matrix &matrix)
{
	for (int i = 0; i < NUMBER_OF_ROWS_OF_MATRIX; ++i)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; ++j)
		{
			input >> matrix[i][j];
		}
	}
}

void FormingAnInverseMatrix(Matrix &matrix, Matrix &newMatrix, const double &determinant)
{
	for (int i = 0; i < NUMBER_OF_ROWS_OF_MATRIX; ++i)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; ++j)
		{
			newMatrix[j][i] = (1 / determinant) * FindMinor(matrix, i, j);
			if (NeedReplaceSign(j, i))
			{
				newMatrix[j][i] = newMatrix[j][i] * (-1);
			}
		}
	}
}

void PrintAnInverseMatrix(Matrix &newMatrix)
{
	for (int i = 0; i < NUMBER_OF_ROWS_OF_MATRIX; ++i)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; ++j)
		{
			cout << newMatrix[i][j] << ' ';
		}
		cout << endl;
	}
}

double FindDeterminantOfOriginalMatrix(Matrix &matrix)
{
	double determinant = 0;
	determinant += matrix[0][0] * FindMinor(matrix, 0, 0);
	determinant -= matrix[0][1] * FindMinor(matrix, 0, 1);
	determinant += matrix[0][2] * FindMinor(matrix, 0, 2);
	return determinant;
}


bool NeedReplaceSign(const int &numberOfColumn, const int &numberOfRow)
{
	bool replace;
	int result = numberOfColumn + numberOfRow;
	(result == 1 || result == 3) ? replace = true : replace = false;
	return replace;
}

double FindDeterminant(const double &a11, const double &a12, const double &a21, const double &a22)
{
	double determinant = 0;
	determinant = (a11 * a22) - (a12 * a21);
	return determinant;
}


double FindMinor(Matrix &matrix, const int &i, const int &j)
{
	double minor;
	double value[4];
	int count = 0;
	for (int row = 0; row < NUMBER_OF_ROWS_OF_MATRIX; ++row)
	{
		if (row != i)
		{
			for (int coloumn = 0; coloumn < NUMBER_OF_COLUMNS_OF_MATRIX; ++coloumn)
			{
				if (coloumn != j)
				{
					value[count] = matrix[row][coloumn];
					count++;
				}
			}
		}
	}
	minor = FindDeterminant(value[0], value[1], value[2], value[3]);
	return minor;
}


int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "rus");
	if (argc != MAX_NUMBER_OF_ARGUMENT)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: replace.exe <input file>\n";
		return EXIT_ERROR;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return EXIT_ERROR;
	}
	Matrix matrix, newMatrix;
	ReadMatrixInFile(input, matrix);
	double determinant = FindDeterminantOfOriginalMatrix(matrix);
	if (determinant == 0)
	{
		cout << "определитель равен 0,она не имеет обратной матрицы\n";
		return EXIT_ERROR;
	}
	FormingAnInverseMatrix(matrix, newMatrix, determinant);
	PrintAnInverseMatrix(newMatrix);
    input.close();
	return EXIT_SUCCESS;
}



