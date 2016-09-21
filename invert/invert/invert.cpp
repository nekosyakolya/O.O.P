#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define NUMBER_OF_ROWS_OF_MATRIX 3
#define NUMBER_OF_COLUMNS_OF_MATRIX 3


using namespace std;
typedef double Matrix[NUMBER_OF_ROWS_OF_MATRIX][NUMBER_OF_COLUMNS_OF_MATRIX];

void ReadMatrixFromFile(ifstream &input, Matrix &matrix);
void FormInverseMatrix(Matrix &matrix, Matrix &newMatrix, const double &determinant);
void PrintInverseMatrix(Matrix &newMatrix, ofstream &output);
bool IsSignReplaceNeeded(const int &numberOfColumn, const int &numberOfRow);
double FindDeterminant(double a11, double a12, double a21, double a22);
double FindMinor(Matrix &matrix, const int &i, const int &j);
double FindDeterminantOfOriginalMatrix(Matrix &matrix);

void ReadMatrixFromFile(ifstream &input, Matrix &matrix)
{
	for (int i = 0; i < NUMBER_OF_ROWS_OF_MATRIX; ++i)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; ++j)
		{
			input >> matrix[i][j];
		}
	}
}

void FormInverseMatrix(Matrix &matrix, Matrix &newMatrix, const double &determinant)
{
	for (int i = 0; i < NUMBER_OF_ROWS_OF_MATRIX; ++i)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; ++j)
		{
			newMatrix[j][i] = (1 / determinant) * FindMinor(matrix, i, j);
			if (IsSignReplaceNeeded(j, i))
			{
				newMatrix[j][i] = newMatrix[j][i] * (-1);
			}
		}
	}
}

void PrintInverseMatrix(Matrix &newMatrix, ofstream &output)
{
	for (int i = 0; i < NUMBER_OF_ROWS_OF_MATRIX; ++i)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; ++j)
		{
			output << fixed << setprecision(3) << newMatrix[i][j] << ' ';
		}
		output << endl;
	}
}

double FindDeterminantOfOriginalMatrix(Matrix &matrix)
{
	double determinant = 0;
	int i = 0;
	for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; ++j)
	{
		if (IsSignReplaceNeeded(i, j))
		{
			determinant -= matrix[i][j] * FindMinor(matrix, i, j);
		}
		else
		{
			determinant += matrix[i][j] * FindMinor(matrix, i, j);
		}
	}
	return determinant;
}


bool IsSignReplaceNeeded(const int &numberOfColumn, const int &numberOfRow)
{
	int result = numberOfColumn + numberOfRow;
	return (result == 1 || result == 3);
}

double FindDeterminant(double a11, double a12, double a21, double a22)
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
	static const int maxNumberOfArgument = 3;
	if (argc != maxNumberOfArgument)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: invert.exe <input file>\n";
		return EXIT_FAILURE;
	}

	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return EXIT_FAILURE;
	}
	ofstream output(argv[2]);

	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return EXIT_FAILURE;
	}
	Matrix matrix;
	ReadMatrixFromFile(input, matrix);
	double determinant = FindDeterminantOfOriginalMatrix(matrix);
	if (determinant == 0)
	{
		cout << "определитель равен 0,она не имеет обратной матрицы\n";
		return EXIT_FAILURE;
	}
	Matrix newMatrix;
	FormInverseMatrix(matrix, newMatrix, determinant);
	PrintInverseMatrix(newMatrix, output);
	if (!output.flush())
	{
		cout << "Failed to save data on disk\n";
		return EXIT_FAILURE;
	}
	input.close();
	output.close();
	return EXIT_SUCCESS;
}



