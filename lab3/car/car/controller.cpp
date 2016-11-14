#include "stdafx.h"
#include "controller.h"
#include "car.h"

using namespace std;
using namespace std::placeholders;

CCarController::CCarController(CCar &car, std::istream &input, std::ostream &output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "Info", bind(&CCarController::Info, this, _1) },
	{ "EngineOn", bind(&CCarController::EngineOn, this, _1) },
	{ "EngineOff", bind(&CCarController::EngineOff, this, _1) },
	{ "SetGear", bind(&CCarController::SetGear, this, _1) },
	{ "SetSpeed", bind(&CCarController::SetSpeed, this, _1) }
})
{
}

bool CCarController::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	return false;
}

string ConvertToString(int direction)
{
	string directionStr = "";
	switch (direction)
	{
	case 1:
		directionStr = "forward";
		break;
	case 0:
		directionStr = "stay";
		break;
	case -1:
		directionStr = "backward";
		break;
	}

	return directionStr;
}

bool CCarController::Info(std::istream & args)
{
	string info = (m_car.IsTurnedOn())
		? ("Engine is turned on\nDirection is: " + ConvertToString(m_car.GetDirection()) + "\nGear is: " + to_string(m_car.GetGear()) +
			"\nSpeed is: " + to_string(m_car.GetSpeed()) + "\n")
		: "Engine is turned off\n";

	m_output << info;

	return true;
}


bool CCarController::EngineOn(std::istream & args)
{
	m_car.TurnOnEngine();
	return true;
}

bool CCarController::EngineOff(std::istream & args)
{
	m_car.TurnOffEngine();
	return true;
}

bool CCarController::SetGear(std::istream & args)
{
	int gear = 0;
	args >> gear;

	if (!m_car.SetGear(gear))
	{
		m_output << "Engine is turned off or gear does not match current speed\n";
	}
	return true;
}

bool CCarController::SetSpeed(std::istream & args)
{
	int speed = 0;
	args >> speed;
	if (!m_car.SetSpeed(speed))
	{
		m_output << "Engine is turned off or gear does not match current gear\n";
	}
	return true;
}



