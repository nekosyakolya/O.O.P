#pragma once
#include <boost/noncopyable.hpp>
#include <functional>
#include "Body.h"

class CBody;

class CBodyController : boost::noncopyable
{
public:
	CBodyController(std::vector<std::shared_ptr<CBody>> &bodies, std::istream & input, std::ostream & output);

	bool HandleCommand();
	void Info();
	void PrintBodies(std::vector<std::shared_ptr<CBody>> const &bodies, std::ostream &output);
	void FindBodyWithMaxMass(std::vector<std::shared_ptr<CBody>> const &bodies, std::ostream &output);
	void FindBodyWithMinWeightInWater(std::vector<std::shared_ptr<CBody>> const &bodies, std::ostream &output);
private:
	bool CreateCylinder(std::istream &args);
	bool CreateCone(std::istream &args);
	bool CreateSphere(std::istream &args);
	bool CreateParallelepiped(std::istream &args);
	using ActionMap = std::map<std::string, std::function<bool(std::istream & args)>>;

	std::vector<std::shared_ptr<CBody>> &m_bodies;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};
