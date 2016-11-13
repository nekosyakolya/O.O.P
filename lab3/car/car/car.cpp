// car.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "car.h"

bool IsValidGear(int gear)
{
	return (gear >= MIN_GEAR) && (gear <= MAX_GEAR);
}

bool IsValidSpeed(const Gear &gear, int currentSpeed)
{
	auto it = speedRange.find(gear);
	auto range = it->second;
	return ((currentSpeed >= range.first) && (currentSpeed <= range.second));
}


bool CCar::IsTurnedOn() const
{
	return m_isOn;
}

bool CCar::TurnOnEngine()
{
	return (m_isOn) ? false : m_isOn = true;
}

bool CCar::TurnOffEngine()
{
	return (m_isOn && m_currentGear == Gear::NEUTRAL_GEAR && m_currentSpeed == 0) ? !(m_isOn = false) : false;
}

bool CCar::SetGear(int gear)
{
	if (IsValidGear(gear) && ((m_isOn && IsValidSpeed(static_cast<Gear>(gear), m_currentSpeed)) || (!m_isOn && m_currentSpeed == 0)))
	{
		if (((m_currentGear == Gear::FIRST_GEAR || m_currentGear == Gear::NEUTRAL_GEAR || m_currentGear == Gear::REVERSE_GEAR)  && m_currentSpeed == 0) ||
			 (m_currentGear != Gear::REVERSE_GEAR) && (static_cast<Gear>(gear) != Gear::REVERSE_GEAR))
		{
			m_currentGear = static_cast<Gear>(gear);
			return true;
		}
	}
	return false;
}

Direction CCar::SetDirection(int speed)
{
	Direction directionCar;
	if (speed == MIN_SPEED)
	{
		directionCar = Direction::STAY;
	}
	else if (m_currentGear != Gear::REVERSE_GEAR)
	{
		directionCar = Direction::FORWARD;
	}
	else
	{
		directionCar = Direction::BACKWARD;
	}
	return directionCar;
}

bool CCar::SetSpeed(int speed)
{
	if (speed >= MIN_SPEED && speed <= MAX_SPEED)
	{
		if (IsValidSpeed(m_currentGear, speed) && (m_currentGear != Gear::NEUTRAL_GEAR || (m_currentGear == Gear::NEUTRAL_GEAR && speed == 0)))
		{
			m_currentSpeed = speed;
			m_direction = SetDirection(m_currentSpeed);
			return true;
		}
	}
	return false;
}

int CCar::GetSpeed() const
{
	return m_currentSpeed;
}

int CCar::GetDirection() const
{
	return static_cast<int>(m_direction);
}


CCar::~CCar()
{
}
