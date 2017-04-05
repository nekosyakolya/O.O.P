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



string CCarController::GetCurrentDirection() const
{
	string direction = "";
	auto it = DIRECTION.find(m_car.GetDirection());
	if (it != DIRECTION.end())
	{
		direction = it->second;
	}
	return direction;
}

bool CCarController::Info(std::istream & /*args*/)
{
	string info = (m_car.IsTurnedOn())
		? ("Engine is turned on\nGear is: " + to_string(m_car.GetGear()) + 
			"\nSpeed is: " + to_string(m_car.GetSpeed()) + 
			"\nDirection is: " + GetCurrentDirection() + "\n")
		: "Engine is turned off\n";

	m_output << info;

	return true;
}


bool CCarController::EngineOn(std::istream & /*args*/)
{
	string info = (m_car.TurnOnEngine()) ? "Engine is turned on\n" : "Engine is already on!\n";
	m_output << info;
	return true;
}

bool CCarController::EngineOff(std::istream & /*args*/)
{
	string info = (m_car.TurnOffEngine()) ? "Engine is turned off\n" : "Engine is already off, not on neutral gear or not zero speed!\n";
	m_output << info;
	return true;
}

bool CCarController::SetGear(std::istream & args)
{
	int gear = 0;
	args >> gear;

	string info = (!m_car.SetGear(gear)) ? "Engine is turned off or gear does not match current speed\n" : "Gear is changed\n";
	m_output << info;
	return true;
}

bool CCarController::SetSpeed(std::istream & args)
{
	int speed = 0;
	args >> speed;
	string info = (!m_car.SetSpeed(speed)) ? "Engine is turned off or speed does not match current gear\n" : "Speed is changed\n";
	m_output << info;
	return true;
}





