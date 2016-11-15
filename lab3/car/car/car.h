#pragma once
#include <map>
#include "const.h"

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
  Direction SetDirection();
  Direction GetDirection() const;
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

