#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#define MAX_NUMBER_OF_ARGUMENT 2
#define EXIT_ERROR 1
#define NUMBER_OF_ROWS_OF_MATRIX 3
#define NUMBER_OF_COLUMNS_OF_MATRIX 3


using namespace std;
bool NeedReplaceSign(const int &a, const int &b);
double FindDeterminant(const double &a11, const double &a12, const double &a13, const double &a14);
double FindMinor(const double matrix[NUMBER_OF_ROWS_OF_MATRIX][NUMBER_OF_COLUMNS_OF_MATRIX], const int &i, const int &j);

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


double FindMinor(const double matrix[NUMBER_OF_ROWS_OF_MATRIX][NUMBER_OF_COLUMNS_OF_MATRIX], const int &i, const int &j)
{
	double minor;
	if ((i == 0) && (j == 0))
	{
		minor = FindDeterminant(matrix[1][1], matrix[1][2], matrix[2][1], matrix[2][2]);
	}
	if ((i == 0) && (j == 1))
	{
		minor = FindDeterminant(matrix[1][0], matrix[1][2], matrix[2][0], matrix[2][2]);
	}
	if ((i == 0) && (j == 2))
	{
		minor = FindDeterminant(matrix[1][0], matrix[1][1], matrix[2][0], matrix[2][1]);
	}
	if ((i == 1) && (j == 0))
	{
		minor = FindDeterminant(matrix[0][1], matrix[0][2], matrix[2][1], matrix[2][2]);
	}
	if ((i == 1) && (j == 1))
	{
		minor = FindDeterminant(matrix[0][0], matrix[0][2], matrix[2][0], matrix[2][2]);
	}
	if ((i == 1) && (j == 2))
	{
		minor = FindDeterminant(matrix[0][0], matrix[0][1], matrix[2][0], matrix[2][1]);
	}
	if ((i == 2) && (j == 0))
	{
		minor = FindDeterminant(matrix[0][1], matrix[0][2], matrix[1][1], matrix[1][2]);
	}
	if ((i == 2) && (j == 1))
	{
		minor = FindDeterminant(matrix[0][0], matrix[0][2], matrix[1][0], matrix[1][2]);
	}
	if ((i == 2) && (j == 2))
	{
		minor = FindDeterminant(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]);
	}
	return minor;
}


int main(int argc, char * argv[])
{
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

	double matrix[NUMBER_OF_ROWS_OF_MATRIX][NUMBER_OF_COLUMNS_OF_MATRIX];

	double value = 0;
	int rows = 0, columns = 0;
	while (input >> value)
	{
		if (columns == NUMBER_OF_COLUMNS_OF_MATRIX)
		{
			columns = 0;
			rows++;
		}
		matrix[rows][columns] = value;
		columns++;
	}
	//определитель матрицы

	double determinant = 0;
	determinant += matrix[0][0] * FindMinor(matrix, 0, 0);
	determinant -= matrix[0][1] * FindMinor(matrix, 0, 1);
	determinant += matrix[0][2] * FindMinor(matrix, 0, 2);
	cout << determinant;

	cout << endl;
	// определили трансп матрицу 
	double newMatrix[NUMBER_OF_ROWS_OF_MATRIX][NUMBER_OF_COLUMNS_OF_MATRIX];
	for (int i = 0; i < NUMBER_OF_ROWS_OF_MATRIX; i++) 
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; j++) 
		{
			newMatrix[j][i] =  (1/ determin) * FindMinor(matrix, i, j);
			if (NeedReplaceSign(j, i))
			{
				newMatrix[j][i] = newMatrix[j][i] * (-1);
			}
		}
	}
	
	for (int i = 0; i < NUMBER_OF_ROWS_OF_MATRIX; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS_OF_MATRIX; j++)
		{
			cout << newMatrix[i][j] << ' ';
		}
		cout << endl;
	}


    input.close();

	return EXIT_SUCCESS;
}



