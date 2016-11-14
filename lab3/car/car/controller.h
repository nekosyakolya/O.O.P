#pragma once
#include <boost/noncopyable.hpp>
#include <functional>
#include "car.h"

class CCar;

class CCarController : boost::noncopyable
{
public:
	CCarController(CCar & car, std::istream & input, std::ostream & output);

	bool HandleCommand();

private:
	bool Info(std::istream & args);
	bool EngineOn(std::istream & args);
	bool EngineOff(std::istream & args);
	bool SetGear(std::istream & args);
	bool SetSpeed(std::istream & args);
	std::string GetCurrentDirection()const;
	using ActionMap = std::map<std::string, std::function<bool(std::istream & args)>>;

	CCar & m_car;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};
