#pragma once
#include "ICanvasDrawable.h"

#include <string>


// ѕр€моугольник, обладающий координатами верхнего левого угла, шириной и высотой
class CRectangle : public ICanvasDrawable
{
public:
	CRectangle(int x0, int y0, int width, int height);
	void Draw(ICanvas & canvas)const override;
	int GetHeight()const;
	int GetWidth()const;
	Point GetPoint()const;
	~CRectangle();
private:
	Point m_point;
	int m_width;
	int m_height;
};

