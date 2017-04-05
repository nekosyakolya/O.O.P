#pragma once
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
	FORWARD = 1
};

using Speed = std::pair<int, int>;

using SpeedRange = std::map<Gear, Speed>;
extern const SpeedRange speedRange;

static const std::map<Direction, std::string> DIRECTION = {
	{ Direction::STAY, "stay"},
	{Direction::FORWARD, "forward"},
	{Direction::BACKWARD, "backward"}
};