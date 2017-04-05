#pragma once

#include "ICanvasDrawable.h"

#include <string>


// Треугольник, задается координатами трех вершин
class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(int x0, int x1, int x2, int y0, int y1, int y2);
	void Draw(ICanvas & canvas)const override;
	Point GetFirstPoint()const;
	Point GetSecondPoint()const;
	Point GetThirdPoint()const;
	~CTriangle();
private:
	Point m_point1;
	Point m_point2;
	Point m_point3;
};
