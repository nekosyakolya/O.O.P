#pragma once
#include <map>


static const int MIN_GEAR = -1;
static const int MAX_GEAR = 5;

static const int MIN_SPEED = 0;
static const int MAX_SPEED = 170;

enum struct Gear
{
	REVERSE_GEAR = MIN_GEAR,
	NEUTRAL_GEAR = 0,
	FIRST_GEAR = 1,
	SECOND_GEAR = 2,
	THIRD_GEAR = 3,
	FOURTH_GEAR = 4,
	FIFTH_GEAR = MAX_GEAR
};

enum struct Direction
{
	BACKWARD = -1,
	STAY = 0,
	FORWARD = 1,
};

using Speed = std::pair<int, int>;

using SpeedRange = std::map<Gear, Speed>;


static const SpeedRange speedRange = {
	{ Gear::REVERSE_GEAR, Speed(MIN_SPEED, 20) },
	{ Gear::NEUTRAL_GEAR, Speed(MIN_SPEED, MAX_SPEED) },
	{ Gear::FIRST_GEAR, Speed(0, 30) },
	{ Gear::SECOND_GEAR, Speed(20, 50) },
	{ Gear::THIRD_GEAR, Speed(30, 60) },
	{ Gear::FOURTH_GEAR, Speed(40, 90) },
	{ Gear::FIFTH_GEAR, Speed(50, MAX_SPEED) }
};

class CCar
{
public:
	CCar();
	bool IsTurnedOn()const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	int GetSpeed()const;
	Direction SetDirection(int speed);
	int GetDirection() const;
	int GetGear() const;
	~CCar();
private:
	bool m_isOn;
	Gear m_currentGear;
	Direction m_direction;
	int m_currentSpeed;
	bool IsValidGear(int gear)const;
	bool IsValidSpeed(const Gear &gear, int currentSpeed)const;
};

