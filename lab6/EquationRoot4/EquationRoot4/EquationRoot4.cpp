#include "stdafx.h"
#include "Solve4Facade.h"
#include <vector>


void ReadCoefficients(std::vector <double> &coefficients)
{
	size_t i = 0;
	double value;
	while (std::cin >> value)
	{
		if (i < 5)
		{
			coefficients[i] = value;
			++i;
		}
	}
}


int main()
{
	//CSolve4Facade eq(1, 4, -4, -20, -5);
	//CSolve4Facade eq(2, 5, -11, -20, 12);


	std::vector <double> coefficients = {0, 0, 0, 0, 0};
	ReadCoefficients(coefficients);

	try
	{
		CSolve4Facade equation(coefficients[0], coefficients[1], coefficients[2], coefficients[3], coefficients[4]);
		equation.PrintRoots();
	}
	catch (const std::invalid_argument &err)
	{
		std::cerr << err.what() << std::endl;
	}
	catch (const std::domain_error &err)
	{
		std::cerr << err.what() << std::endl;
	}

	return EXIT_SUCCESS;
}

