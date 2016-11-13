// car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "car.h"




bool CCar::IsTurnedOn() const
{
	return m_isOn;
}

bool CCar::TurnOnEngine()
{
	return false;
}

CCar::CCar()
{
}


CCar::~CCar()
{
}
