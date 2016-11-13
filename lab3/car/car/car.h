#pragma once
class CCar
{
public:
	bool IsTurnedOn()const;
	bool TurnOnEngine();
	CCar();
	~CCar();
private:
	bool m_isOn = false;
};

