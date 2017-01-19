#pragma once

#include "ICanvasDrawable.h"

#include <string>


// Треугольник, задается координатами трех вершин
class CTriangle : public ICanvasDrawable
{
public:
	CTriangle(int x0, int x1, int x2, int y0, int y1, int y2);
	void Draw(ICanvas & canvas)const override;
	std::string GetType()const override;
	~CTriangle();
private:
	int m_x0;
	int m_x1;
	int m_x2;
	int m_y0;
	int m_y1;
	int m_y2;
};
