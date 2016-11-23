// volumeBodies.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Controller.h"

using namespace std;

int main()
{
	vector<shared_ptr<CBody>> bodies;
	CBodyController controller(bodies, cin, cout);
	controller.Info();
	while (cin)
	{
		cout << "> ";
		if (!controller.HandleCommand() && !cin.eof())
		{
			cout << "Error in command!" << endl;
		}
	}
	controller.PrintBodies(bodies, cout);
	controller.FindBodyWithMaxMass(bodies, cout);
	controller.FindBodyWithMinWeightInWater(bodies, cout);
	return EXIT_SUCCESS;
}

