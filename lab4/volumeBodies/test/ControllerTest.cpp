#include "stdafx.h"
#include "../volumeBodies/controller.h"
#include "../volumeBodies/Body.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;


struct ControllerDependencies
{
	vector<shared_ptr<CBody>> bodies;
	stringstream input;
	stringstream output;
};

struct ControllerFixture : ControllerDependencies
{
	CBodyController controller;

	ControllerFixture()
		: controller(bodies, input, output)
	{
	}


	void VerifyCommandHandling(const string& command, const string& expectedOutput)
	{
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		controller.HandleCommand();
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Controller, ControllerFixture)

	BOOST_AUTO_TEST_CASE(can_handle_sphere)
	{
		VerifyCommandHandling("Sphere 5 20", "");
	}
	BOOST_AUTO_TEST_CASE(can_handle_invalid_input)
	{
		VerifyCommandHandling("Cone 3", "Invalid count of arguments\nUsage: Cone <height> <radius> <density>\n");
	}
	BOOST_AUTO_TEST_CASE(can_handle_negative_values)
	{
		VerifyCommandHandling("Sphere -9 13", "Radius or density should not be negative\n");
	}
BOOST_AUTO_TEST_SUITE_END()