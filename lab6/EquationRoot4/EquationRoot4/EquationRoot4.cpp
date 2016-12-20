#include "stdafx.h"
#include "Solve4Facade.h"
#include <vector>


int main()
{
	//CSolve4Facade eq(1, 4, -4, -20, -5);
	//CSolve4Facade eq(2, 5, -11, -20, 12);


	std::vector <double> args = {0, 0, 0, 0, 0};


	size_t i = 0;
	double value;
	while (std::cin >> value)
	{
		if (i < 5)
		{
			args[i] = value;
			++i;
		}
	}

	try
	{

		CSolve4Facade eq(args[0], args[1], args[2], args[3], args[4]);
		eq.PrintRoots();
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

