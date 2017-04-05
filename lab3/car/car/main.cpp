#include "stdafx.h"
#include "Car.h"
#include "controller.h"

using namespace std;
int main()
{
	CCar car;
	CCarController controller(car, cin, cout);
	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!controller.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return EXIT_SUCCESS;
}