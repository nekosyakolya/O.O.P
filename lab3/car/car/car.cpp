#include "stdafx.h"
#include "car.h"


const SpeedRange speedRange = {
	{ Gear::REVERSE_GEAR, Speed(MIN_SPEED, 20) },
	{ Gear::NEUTRAL_GEAR, Speed(MIN_SPEED, MAX_SPEED) },
	{ Gear::FIRST_GEAR, Speed(0, 30) },
	{ Gear::SECOND_GEAR, Speed(20, 50) },
	{ Gear::THIRD_GEAR, Speed(30, 60) },
	{ Gear::FOURTH_GEAR, Speed(40, 90) },
	{ Gear::FIFTH_GEAR, Speed(50, MAX_SPEED) }
};

bool CCar::IsValidGear(int gear) const
{
	return (gear >= MIN_GEAR) && (gear <= MAX_GEAR);
}

bool CCar::IsValidSpeed(const Gear & gear, int currentSpeed) const
{
	auto it = speedRange.find(gear);
	auto range = it->second;
	return ((currentSpeed >= range.first) && (currentSpeed <= range.second));
}

bool CCar::CanSetGear(const Gear & gear) const
{
	return (((m_currentGear == Gear::FIRST_GEAR || 
		m_currentGear == Gear::NEUTRAL_GEAR || 
		m_currentGear == Gear::REVERSE_GEAR) 
		&& m_currentSpeed == 0) 
		|| ((m_currentGear != Gear::REVERSE_GEAR) && (gear != Gear::REVERSE_GEAR) && (m_direction != Direction::BACKWARD &&  gear != Gear::REVERSE_GEAR))
		|| gear == Gear::NEUTRAL_GEAR);
}


CCar::CCar():
	m_isOn(false),
	m_currentGear(Gear::NEUTRAL_GEAR),
	m_direction(Direction::STAY),
	m_currentSpeed(MIN_SPEED)
{
}

bool CCar::IsTurnedOn() const
{
	return m_isOn;
}

bool CCar::TurnOnEngine()
{
	bool isTurnOn = false;
	if (!m_isOn)
	{
		m_isOn = true;
		isTurnOn = true;
	}
	return isTurnOn;
}

bool CCar::TurnOffEngine()
{
	bool isTurnOff = false;
	if (m_isOn && m_currentGear == Gear::NEUTRAL_GEAR && m_currentSpeed == 0)
	{
		m_isOn = false;
		isTurnOff = true;
	}
	return isTurnOff;
}

bool CCar::SetGear(int gear)
{
	if (IsValidGear(gear) && ((m_isOn && IsValidSpeed(static_cast<Gear>(gear), m_currentSpeed)) || (!m_isOn && static_cast<Gear>(gear) == Gear::NEUTRAL_GEAR)))
	{
		if (CanSetGear(static_cast<Gear>(gear)))
		{
			m_currentGear = static_cast<Gear>(gear);
			return true;
		}
	}
	return false;
}

Direction CCar::SetDirection()
{
	Direction directionCar;
	if (m_currentSpeed == MIN_SPEED)
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
	if (IsValidSpeed(m_currentGear, speed) && (m_currentGear != Gear::NEUTRAL_GEAR || (m_currentGear == Gear::NEUTRAL_GEAR && speed <= m_currentSpeed)))
	{
		m_currentSpeed = speed;
		m_direction = SetDirection();
		return true;
	}
	return false;
}

int CCar::GetSpeed() const
{
	return m_currentSpeed;
}


int CCar::GetGear() const
{
	return static_cast<int>(m_currentGear);
}

Direction CCar::GetDirection() const
{
	return m_direction;
}


CCar::~CCar()
{
}

