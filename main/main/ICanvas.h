#pragma once

// �����, ����������� �������� ����������� ���������
class ICanvas
{
public:
	virtual void DrawLine(int x0, int y0, int x1, int y1) = 0;
	virtual ~ICanvas() {};
};

